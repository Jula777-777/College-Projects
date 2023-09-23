package com.example.dicecollector;

import java.io.Serializable;

public class Dice implements Serializable {

    public Dice(){
    //default dice constructor
    }

    public Dice(String name, String number,String color, String note){
        this.setName(name);
        this.setNumber(number);
        this.setColor(color);
        this.setNote(note);

    }
    String number = "29122";
    void setNumber(String number){
        this.number = number;
    }
    String getNumber(){return number;}

    String img = "";

    public void setImg(String img) {
        this.img = img;
    }

    public String getImg() {
        return img;
    }

    String name = "Multicolor set of D6";

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    String color = "Yes";

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    String note = "Test Dice";

    public void setNote(String note) {
        this.note = note;
    }

    public String getNote() {
        return note;
    }
}
