package Controller;

import Model.ProgramState;
import Repository.IRepository;
import Exception.*;
import java.util.List;
import java.util.Objects;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {

    private IRepository repository;
    private ExecutorService executor;


    public Controller(IRepository repository) {
        this.repository = repository;
    }

    public void oneStepGUI() {
        try {
            executor = Executors.newFixedThreadPool(8);
            removeCompletedPrg(repository.getProgramStateList());
            List<ProgramState> programStateList = repository.getProgramStateList();
            if (programStateList.size() > 0) {

                oneStepForAllPrg(repository.getProgramStateList());
                //update current symTable between statements
                programStateList.forEach(p -> p.setSymbolTable(p.getSymbolTableStack().peek()));
                removeCompletedPrg(repository.getProgramStateList());
                executor.shutdownNow();
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private void oneStepForAllPrg(List<ProgramState> programStateList) {
        List<Callable<ProgramState>> callableList = programStateList.stream()
                .map((ProgramState p) ->
                        (Callable<ProgramState>) (p::oneStep))
                .collect(Collectors.toList());
        List<ProgramState> newProgramStateList;
        try {
            newProgramStateList = executor.invokeAll(callableList).stream()
                    .map(future -> {
                        try {
                            return future.get();
                        } catch (InterruptedException | ExecutionException e) {
                            throw new StatementExecError(e.getMessage());
                        }
                    })
                    .filter(Objects::nonNull)
                    .collect(Collectors.toList());
        } catch (InterruptedException e) {
            throw new StatementExecError(e.getMessage());
        }
        programStateList.addAll(newProgramStateList);
        programStateList.forEach(programState -> repository.logPrgStateExec(programState));
        repository.logCommon(programStateList.get(0));
        repository.setProgramStateList(programStateList);
    }


    private List<ProgramState> removeCompletedPrg(List<ProgramState> inPrgList) {
        return inPrgList.stream().filter(ProgramState::isNotCompleted).collect(Collectors.toList());
    }

//    private Map<Integer, Integer> conservativeGarbageCollector(Collection<Integer> symTable, Map<Integer, Integer> heap) {
//        return heap.entrySet().stream()
//                .filter(e -> symTable.contains(e.getKey())).collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
//    }

    public IRepository getRepository() {
        return this.repository;
    }
}
