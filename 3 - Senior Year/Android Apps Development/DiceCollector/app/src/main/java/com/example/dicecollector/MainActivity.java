package com.example.dicecollector;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Parcelable;
import android.preference.PreferenceManager;
import android.view.View;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import com.example.dicecollector.diceSets;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.File;
import java.util.Scanner;


public class MainActivity extends AppCompatActivity {

    //these are here because i need them declared so that i can then pass them into the addDiceActivity
    diceSets diceList = new diceSets();
    DiceRVAdapter adapter= new DiceRVAdapter(diceList.getDiceList());


    //todo 1. figure out how to do the import and export of dice to the diceSets list
    //todo 2. figure out how to update the adapter when the addDice activity is finished
    //todo 3. add delete and edit to the dice

    private FloatingActionButton addDiceButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        addDiceButton = findViewById(R.id.addDiceBtn);

        initComponent();



    }

    public static void clearTheFile() {
        try {
            FileWriter fwOb = new FileWriter("dicelist.txt", false);
            PrintWriter pwOb = new PrintWriter(fwOb, false);
            pwOb.flush();
            pwOb.close();
            fwOb.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void writingFunction(){
        try{
            File path = this.getFilesDir();
            File file = new File(path, "dicelist.txt");
            FileOutputStream stream = new FileOutputStream(file);
            stream.write((diceList.getDiceList().size()+";").getBytes());
            for (int i = 0; i < diceList.getDiceList().size(); i++){
                stream.write((diceList.getDiceList().get(i).getName() +";").getBytes());
                stream.write((diceList.getDiceList().get(i).getNumber() +";").getBytes());
                stream.write((diceList.getDiceList().get(i).getColor() +";").getBytes());
                stream.write((diceList.getDiceList().get(i).getNote() +";").getBytes());
            }
            stream.close();

        } catch (Exception e){
            e.printStackTrace();
        }

    }

    public void readingFunction(){
        try{
            File path = this.getFilesDir();
            File file = new File(path, "dicelist.txt");
            Scanner sc = new Scanner(file).useDelimiter(";");
            int numDice = 0;
            numDice = sc.nextInt();
            for(int i = 0; i < numDice; i++){
                diceList.addDice(new Dice(
                        sc.next(),
                        sc.next(),
                        sc.next(),
                        sc.next()
                ));
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }

    public void addDice(){
        Intent intent = new Intent(this, AddDiceActivity.class);
        startActivityForResult(intent, 1);
    }

    public void editDice(int position)
    {
        Intent intent = new Intent(this, EditDiceActivity.class);
        intent.putExtra("position", position);
        intent.putExtra("diceList", diceList);
        startActivityForResult(intent, 2);
    }

    private void initComponent() {

        //load dice list
        //for(int i = 0; i < 5; i++){  diceList.getDiceList().add(new Dice()); }

        readingFunction();

        if(diceList.getDiceList().size() == 0){
            ((TextView) findViewById(R.id.onboardTextView)).setText(getString(R.string.onboardingMessage));
        }


        //set recyclerView
        RecyclerView RVDice = (RecyclerView) findViewById(R.id.RVDice);

        //bind adapter
        RVDice.setAdapter(adapter);

        RVDice.setLayoutManager(new LinearLayoutManager(this));



        addDiceButton = findViewById(R.id.addDiceBtn);

            addDiceButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view){
                addDice();
            }
        });

        adapter.setOnItemClickListener(new DiceRVAdapter.OnItemClickListener() {
            @Override
            public void onItemClick(int position)
            {
                editDice(position);
            }
        });

    }



    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == 1) {
            if(resultCode == RESULT_OK){
                Dice toAdd = (Dice)data.getSerializableExtra("toAdd");
                diceList.addDice(toAdd);
                adapter.notifyDataSetChanged();
                clearTheFile();
                writingFunction();
                ((TextView) findViewById(R.id.onboardTextView)).setText("");

            }
            if (resultCode == RESULT_CANCELED) {
                // Write your code if there's no result
            }
        }

        else if(requestCode == 2)
        {
            if(resultCode == RESULT_OK)
            {
                Dice toEdit = (Dice) data.getSerializableExtra("toEdit");
                int position = (int) data.getSerializableExtra("position");

                if(toEdit == null)
                {
                    diceList.deleteDice(position);
                    adapter.notifyDataSetChanged();
                    clearTheFile();
                    writingFunction();
                    if (diceList.getDiceList().isEmpty())
                    {
                        ((TextView) findViewById(R.id.onboardTextView)).setText(R.string.onboardingMessage);
                    }
                }
                else
                {
                    diceList.setDice(position, toEdit);
                    adapter.notifyDataSetChanged();
                    clearTheFile();
                    writingFunction();
                }


            }
            if (resultCode == RESULT_CANCELED) {
                // Write your code if there's no result
            }
        }
    } //onActivityResult





}