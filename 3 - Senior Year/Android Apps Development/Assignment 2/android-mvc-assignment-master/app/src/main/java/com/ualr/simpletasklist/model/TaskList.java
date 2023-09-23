package com.ualr.simpletasklist.model;

import java.util.HashMap;

public class TaskList {

    // TODO 03. Define TaskList's attributes. The class will have just one attribute to store all
    //  the tasks created by the user.

    private HashMap<Integer, Task> list;

    // TIP. We need a data structure able to dynamically grow and shrink. That's why we'll use a HashMap.
    // where keys will be integer values and the mapped values will be a task object

    // TODO 04. Define the class constructor and the corresponding getters and setters.

    public TaskList()
    {
        list = new HashMap();
    }

    public HashMap<Integer, Task> getList()
    {
        return list;
    }

    public void setList(HashMap<Integer, Task> list)
    {
        this.list = list;
    }

    // TODO 06.03. Define a new method called "add" that, given a task description, will create a
    //  new task and add it to the task list.

    public void add(String description)
    {
        Task newTask = new Task(description);
        list.put(list.size() + 1, newTask);
    }

    // TODO 06.04. Define a new "toString" method that provides a formatted string with all the tasks in the task list.
    // Format: 1 line per task. Each line should start with the id number of the task, then a dash, and the task description right after that.
    // If the task is marked as done, "Done" should be included at the end of the line

    public String toString()
    {
        String printedList = "";
        for (int i = 1; i <= list.size(); i++)
        {
            printedList += i + " - " + list.get(i).getDescription();
            if (list.get(i).getDone() == true)
            {
                printedList += " - Done";
            }
            printedList += "\n";
        }
        return printedList;
    }

    // TODO 07.03. Define a new method called "delete" that, given a task id, will delete the
    //  corresponding task from the task list.

    public void delete(Integer id)
    {
        for (int i = id; i < list.size(); i++)
        {
            list.replace(i, list.get(i + 1));
        }
        list.remove(list.size());
    }

    // TODO 08.03. Define a new method called "markDone" that, given a task id, will mark the
    //  corresponding task as done.

    public void markDone(Integer id)
    {
        list.get(id).setDone(true);
    }

}
