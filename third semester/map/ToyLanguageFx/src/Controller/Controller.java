package Controller;

import Model.Expression.VarExp;
import Model.ProgramState;
import Model.Statement.CloseRFile;

import Repository.IRepository;

import Exception.*;

import java.io.IOException;

import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {

    private IRepository repository;
    private ExecutorService executor;


    public Controller(IRepository repository){
        this.repository = repository;
    }

    public void oneStepGUI()
    {
        try {
            executor = Executors.newFixedThreadPool(8);
            removeCompletedPrg(repository.getProgramStateList());
            List<ProgramState> programStateList = repository.getProgramStateList();
            if (programStateList.size() > 0) {
                oneStepForAllPrg(repository.getProgramStateList());
                removeCompletedPrg(repository.getProgramStateList());
                executor.shutdownNow();
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private void oneStepForAllPrg(List<ProgramState> programStateList){
        List<Callable<ProgramState>> callableList = programStateList.stream()
                .map((ProgramState p) ->
                        (Callable<ProgramState>)(p::oneStep))
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
                    .filter(p -> (p != null))
                    .collect(Collectors.toList());
        } catch (InterruptedException e){
            throw new StatementExecError(e.getMessage());
        }
        programStateList.addAll(newProgramStateList);
        programStateList.forEach(programState -> repository.logPrgStateExec(programState));
        repository.logCommon(programStateList.get(0));
        repository.setProgramStateList(programStateList);
    }

//
//    public void allSteps(){
//        executor = Executors.newFixedThreadPool(2);
//        List<ProgramState> programStates = removeCompletedPrg(repository.getProgramStateList());
//        programStates.forEach(programState -> repository.logPrgStateExec(programState));
//        repository.logCommon(programStates.get(0));
//        while(programStates.size() > 0){
//            programStates.forEach(p-> p.getHeap().setContent(conservativeGarbageCollector(p.getSymbolTable().values(), p.getHeap().getContent())));
//            oneStepForAllPrg(programStates);
//            programStates = removeCompletedPrg(repository.getProgramStateList());
//
//        }
//        executor.shutdownNow();
//        List<ProgramState> tmpList = repository.getProgramStateList();
//        tmpList.forEach(p-> p.getSymbolTable().keys().stream()
//                .filter(key -> p.getFileTable().containsKey(p.getSymbolTable().get(key)))
//                .map(item -> {
//                    try {
//                        return new CloseRFile(new VarExp(item)).execute(p);
//                    } catch (IOException e){
//                        e.printStackTrace();
//                    }
//                    return null;
//                }).forEach(item -> this.repository.logPrgStateExec()));
//        repository.setProgramStateList(programStates);
//    }

    private List<ProgramState> removeCompletedPrg(List<ProgramState> inPrgList){
        return inPrgList.stream().filter(ProgramState::isNotCompleted).collect(Collectors.toList());
    }

    private Map<Integer, Integer> conservativeGarbageCollector(Collection<Integer> symTable, Map<Integer, Integer> heap){
        return heap.entrySet().stream()
                .filter(e->symTable.contains(e.getKey())).collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    public IRepository getRepository(){return this.repository;}
}
