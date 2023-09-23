package com.ualr.layoutassignment;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import com.ualr.layoutassignment.databinding.ActivityMainBinding;

import java.util.Locale;

public class MainActivity extends AppCompatActivity {

    // TODO 02. Create a new method called "calculateTotal" for calculating the invoice's total amount of money

    // TODO 03. Bind the "calculateTotal" method to the button with the "CALCULATE TOTAL" label

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

    }

    public void calculateTotal(View view)
    {
        double totalCost = 0.00;
        if (this.binding.checkBox1.isChecked())
        {
            try
            {

                    totalCost += Double.parseDouble(this.binding.inputProduct1.getText().toString());
            }catch(Exception e)
            {
                    e.printStackTrace();
            }
        }

        if (this.binding.checkBox2.isChecked())
        {
            try
            {

                totalCost += Double.parseDouble(this.binding.inputProduct2.getText().toString());
            }catch(Exception e)
            {
                e.printStackTrace();
            }
        }

        if (this.binding.checkBox3.isChecked())
        {
            try
            {

                totalCost += Double.parseDouble(this.binding.inputProduct3.getText().toString());
            }catch(Exception e)
            {
                e.printStackTrace();
            }
        }

        if (this.binding.checkBox4.isChecked())
        {
            try
            {

                totalCost += Double.parseDouble(this.binding.inputProduct4.getText().toString());
            }catch(Exception e)
            {
                e.printStackTrace();
            }
        }

        if (this.binding.discountButton.isChecked())
        {
            totalCost *= 0.75;
        }

        this.binding.moneyTotal.setText("$" + String.format(Locale.getDefault(), "%.2f", totalCost));
    }
}