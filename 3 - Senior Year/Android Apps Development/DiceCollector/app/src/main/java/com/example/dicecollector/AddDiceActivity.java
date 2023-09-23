package com.example.dicecollector;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.List;

public class AddDiceActivity extends AppCompatActivity {

    private Button checkImgBtn;
    private Button saveButton;
    private String diceName;
    private String diceNum;
    private String diceColor;
    private String diceNote;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_dice);
        checkImgBtn = findViewById(R.id.checkImgBtn);
        saveButton = findViewById(R.id.saveButton);

        DiceRVAdapter adapter = (DiceRVAdapter)getIntent().getSerializableExtra("adapter");

        saveButton.setOnClickListener(new View.OnClickListener() {
           public void onClick(View v) {

               diceName = ((TextView) findViewById(R.id.diceNameInput)).getText().toString();
               diceNum = ((TextView) findViewById(R.id.diceNumInput)).getText().toString();
               diceColor = ((TextView) findViewById(R.id.diceColorInput)).getText().toString();
               diceNote = ((TextView) findViewById(R.id.diceNoteInput)).getText().toString();


               //add dice to list of dice and update data set
               Dice toAdd = new Dice(diceName, diceNum, diceColor, diceNote);
               Intent returnIntent = new Intent();
               returnIntent.putExtra("toAdd", toAdd);
               setResult(RESULT_OK, returnIntent);
               finish();
           }
        });

        checkImgBtn.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                Picasso.get()
                        .load("https://store.chessex.com:11552/images/"+ ( ((TextView) findViewById(R.id.diceNumInput)).getText() ) + ".jpg")
                        .resize(500,500)
                        .into((ImageView)findViewById(R.id.diceTestImgView));

            }
        });

    }




}