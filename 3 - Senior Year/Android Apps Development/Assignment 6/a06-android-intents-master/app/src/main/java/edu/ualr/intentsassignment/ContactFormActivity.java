package edu.ualr.intentsassignment;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.button.MaterialButton;

import edu.ualr.intentsassignment.model.Contact;

public class ContactFormActivity extends AppCompatActivity
{
    // TODO 01. Create a new layout file to define the GUI elements of the ContactFormActivity.
    // TODO 02. Define the basic skeleton of the ContactFormActivity. Inflate the layout defined in the first step to display the GUI elements on screen.
    // TODO 06. Create a new method that reads the values in the several EditText elements of the layout and then uses the Contact class to send those data to ContactInfoActivity

    private Button saveButton;
    private String firstname;
    private String lastName;
    private String phone;
    private String email;
    private String address;
    private String website;
    public static final String EXTRA_CONTACT = "ContactData";


    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_contact_form);
        saveButton = findViewById(R.id.saveButton);

        saveButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                firstname = ((EditText) findViewById(R.id.editFirstName)).getText().toString();
                lastName = ((EditText) findViewById(R.id.editLastName)).getText().toString();
                phone = ((EditText) findViewById(R.id.editPhone)).getText().toString();
                email = ((EditText) findViewById(R.id.editEmail)).getText().toString();
                address = ((EditText) findViewById(R.id.editAddress)).getText().toString();
                website = ((EditText) findViewById(R.id.editWebsite)).getText().toString();

                saveContact();
            }
        });
    }

    public void saveContact()
    {
        Intent intent = new Intent(this, ContactInfoActivity.class);
        Contact contact = new Contact(firstname, lastName, phone, email, address, website);
        intent.putExtra(EXTRA_CONTACT, contact);
        startActivity(intent);
    }
}
