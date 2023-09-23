package com.example.dicecollector;

import java.io.Serializable;
import java.util.ArrayList;

public class diceSets implements Serializable {
    private ArrayList<Dice> diceList = new ArrayList<Dice>();
    public ArrayList<Dice> getDiceList() {return diceList;}
    public void addDice(Dice dice) {
        diceList.add(dice);
    }
    public void setDice(int index, Dice dice)
    {
        diceList.set(index, dice);
    }
    public void deleteDice(int index)
    {
        diceList.remove(index);
    }
}
