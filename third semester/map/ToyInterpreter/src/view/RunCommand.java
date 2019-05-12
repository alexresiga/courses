package view;

import controller.Controller;

public class RunCommand extends Command {

    private Controller ctrl;

    public RunCommand(String key, String desc, Controller ctrl){
        super(key, desc);
        this.ctrl = ctrl;
    }

    @Override
    public void execute()  {

        try{
            ctrl.allSteps();
        }
        catch (Exception exc) {
            System.out.println(exc.getMessage());
        }
    }

}
