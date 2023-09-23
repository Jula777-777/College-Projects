package com.example.dicecollector;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.List;
import com.example.dicecollector.diceSets;

public class EditDiceActivity extends AppCompatActivity {

    private Button checkImgBtn;
    private Button editButton;
    private Button deleteButton;
    private String diceName;
    private String diceNum;
    private String diceColor;
    private String diceNote;
    Dice toEdit = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_dice);

        Intent intent = getIntent();
        int position = (int)intent.getSerializableExtra("position");
        diceSets diceList = (diceSets)intent.getSerializableExtra("diceList");

        ((EditText) findViewById(R.id.diceNameEdit)).setText(diceList.getDiceList().get(position).getName());
        ((EditText) findViewById(R.id.diceNumEdit)).setText(diceList.getDiceList().get(position).getNumber());
        ((EditText) findViewById(R.id.diceColorEdit)).setText(diceList.getDiceList().get(position).getColor());
        ((EditText) findViewById(R.id.diceNoteEdit)).setText(diceList.getDiceList().get(position).getNote());


        checkImgBtn = findViewById(R.id.checkImgBtnEdit);
        editButton = findViewById(R.id.editButton);
        deleteButton = findViewById(R.id.deleteButton);

        DiceRVAdapter adapter = (DiceRVAdapter)getIntent().getSerializableExtra("adapter");

        editButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {

                diceName = ((TextView) findViewById(R.id.diceNameEdit)).getText().toString();
                diceNum = ((TextView) findViewById(R.id.diceNumEdit)).getText().toString();
                diceColor = ((TextView) findViewById(R.id.diceColorEdit)).getText().toString();
                diceNote = ((TextView) findViewById(R.id.diceNoteEdit)).getText().toString();


                //edit dice and update data set
                toEdit = new Dice(diceName, diceNum, diceColor, diceNote);
                Intent returnIntent = new Intent();
                returnIntent.putExtra("toEdit", toEdit);
                returnIntent.putExtra("position", position);
                setResult(RESULT_OK, returnIntent);
                finish();
            }
        });

        deleteButton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                Intent returnIntent = new Intent();
                returnIntent.putExtra("position", position);
                setResult(RESULT_OK, returnIntent);
                finish();
            }
        });

        checkImgBtn.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                Picasso.get()
                        .load("https://store.chessex.com:11552/images/"+ ( ((TextView) findViewById(R.id.diceNumEdit)).getText() ) + ".jpg")
                        .resize(500,500)
                        .into((ImageView)findViewById(R.id.diceTestImgViewEdit));

            }
        });

    }




}