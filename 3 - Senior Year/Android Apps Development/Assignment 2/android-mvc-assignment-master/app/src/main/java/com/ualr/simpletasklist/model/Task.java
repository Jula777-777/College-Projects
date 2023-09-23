package com.ualr.simpletasklist.model;

public class Task {

    // TODO 01. Define two attributes for the Task class: one to store the task description and a second one that
    //  indicates whether the task is done or not

    private String description;
    private Boolean isDone;

    // TODO 02. Define the class constructor and the corresponding getters and setters.

    public Task(String description)
    {
        this.description = description;
        this.isDone = false;
    }

    public String getDescription()
    {
        return description;
    }

    public void setDescription(String description)
    {
        this.description = description;
    }

    public Boolean getDone()
    {
        return isDone;
    }

    public void setDone(Boolean done)
    {
        isDone = done;
    }
}
