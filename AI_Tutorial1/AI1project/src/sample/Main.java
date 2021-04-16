package sample;
//IIT2018187
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.util.Pair;

import  java.io.*;
import  java.util.*;
import  java.util.regex.*;
class environment{
    private Pair<Integer, Integer> end;

    public environment(Pair<Integer, Integer> end) {
        this.end = end;
    }

    public Pair<Integer, Integer> getEnd() {
        return end;
    }

    public void setEnd(Pair<Integer, Integer> end) {
        this.end = end;
    }

    public boolean isValid(Pair <Integer,Integer> point){
        if(point.getKey()<0||point.getKey()>=end.getKey()||point.getValue()<0||point.getValue()>=end.getValue()) return false;
        return true;
    }
    public Pair<Integer, Integer> myNextMove(Pair<Integer, Integer> cura,Pair<Integer, Integer> end){
        if(cura.getKey()<end.getKey()){
            return new Pair<Integer, Integer>(cura.getKey()+1,cura.getValue());
        }
        if(cura.getKey()>end.getKey()){
            return new Pair<Integer, Integer>(cura.getKey()-1,cura.getValue());
        }
       if(cura.getValue()<end.getValue()){
            return new Pair<Integer, Integer>(cura.getKey(),cura.getValue()+1);
        }
        if(cura.getValue()>end.getValue()){
            return new Pair<Integer, Integer>(cura.getKey(),cura.getValue()-1);
        }
        return cura;
    }
    
}
 class Agent {
    environment env;
    private int ID;
    private Pair<Integer, Integer> srca;
    private Pair<Integer, Integer> desa;
    private Pair<Integer, Integer> cura;
    boolean Astate=false;

    public Agent(environment env, int ID, Pair<Integer, Integer> srca, Pair<Integer, Integer> desa, Pair<Integer, Integer> cura, boolean astate) {
        this.env = env;
        this.ID = ID;
        this.srca = srca;
        this.desa = desa;
        this.cura = cura;
        Astate = astate;
    }

    public environment getEnv() {
        return env;
    }

    public void setEnv(environment env) {
        this.env = env;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public Pair<Integer, Integer> getSrca() {
        return srca;
    }

    public void setSrca(Pair<Integer, Integer> srca) {
        this.srca = srca;
    }

    public Pair<Integer, Integer> getDesa() {
        return desa;
    }

    public void setDesa(Pair<Integer, Integer> desa) {
        this.desa = desa;
    }

    public Pair<Integer, Integer> getCura() {
        return cura;
    }

    public void setCura(Pair<Integer, Integer> cura) {
        this.cura = cura;
    }

    public boolean getAstate() {
        return Astate;
    }

    public void setAstate(boolean astate) {
        Astate = astate;
    }

    public void Analyze()
    {
        if(this.cura.getValue()==this.desa.getValue() && this.cura.getKey()==this.desa.getKey()) setAstate(true);
        else setAstate(false);
    }

    public Pair <Integer,Integer> AgentNext()
    {
        setCura(env.myNextMove(cura,desa));
        Analyze();
        return getCura();
    }
}
class Main{
    public  static  void  main(String[]  args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Max rows of matrix :\n");
        int row = scanner.nextInt();


        System.out.print("\nEnter the Max of matrix :\n");
        int col = scanner.nextInt();


        environment env = new environment(new Pair<Integer, Integer>(row, col));

        int srcax, srcay;

            System.out.print("\nEnter Agent BINOD x pos  : \n");
            srcax = scanner.nextInt();


            System.out.print("\nEnter Agent BINOD y pos : \n");
            srcay = scanner.nextInt();


            if (!env.isValid(new Pair<Integer, Integer>(srcax, srcay))) {
                System.out.println("\n OOPS something Wrong BINOD ReEnter\n");
                System.exit(0);
            }


        int desax, desay;

            System.out.print("\nEnter destination's x coordinate : \n");
            desax = scanner.nextInt();

            System.out.print("\nEnter destination's y coordinate : \n");
            desay = scanner.nextInt();

            if (!env.isValid(new Pair<Integer, Integer>(desax, desay))) {
                System.out.println(" \nOOOPS something Wrong BINOD ReEnter \n");
                System.exit(0);
            }

        ArrayList<Pair<Integer, Integer>> pathofAgent = new ArrayList<>();
        System.out.print("\nThe path of Agent BINOD is as follows: \n");
        Pair<Integer, Integer> sourcepos = new Pair<>(srcax, srcay);
        Pair<Integer, Integer> despos = new Pair<>(desax, desay);
        Agent agentBinod = new Agent(env, 512, sourcepos, despos, sourcepos, false);
        pathofAgent.add(sourcepos);
        while (!agentBinod.getAstate()) {
            pathofAgent.add(agentBinod.AgentNext());
        }
        for (Pair<Integer, Integer> p : pathofAgent) {
            System.out.print("[" + p.getKey() + "," + p.getValue() + "]--->");
        }
        System.out.println();
    }
}



