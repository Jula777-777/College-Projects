package edu.ualr.intentsassignment;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.chip.Chip;

import org.w3c.dom.Text;

import edu.ualr.intentsassignment.model.Contact;

public class ContactInfoActivity extends AppCompatActivity
{
    // TODO 03. Create a new layout file to define the GUI elements of the ContactInfoActivity.
    // TODO 04. Define the basic skeleton of the ContactInfoActivity. Inflate the layout defined in the first step to display the GUI elements on screen.
    // TODO 07. Create a new method that reads the contact info coming from ContactFormActivity and use it to populate the several TextView elements in the layout.
    // TODO 08. Create a new method that invokes a Phone Dialer app, using as parameter the phone number included in the contact info received from ContactFormActivity in the previous step
    // TODO 09. Create a new method that invokes a Messages app, using as parameter the phone number included in the contact info received from ContactFormActivity in the 7th step
    // TODO 10. Create a new method that invokes a Maps app, using as parameter the address included in the contact info received from ContactFormActivity in the 7th step
    // TODO 11. Create a new method that invokes an Email app, using as parameter the email address included in the contact info received from ContactFormActivity in the 7th step
    // TODO 12. Create a new method that invokes an Web Browser app, using as parameter the web url included in the contact info received from ContactFormActivity in the 7th step

    private Chip callButton;
    private Chip textButton;
    private Chip emailButton;
    private Chip mapButton;
    private Chip webButton;


    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_contact_info);

        Contact contact = getIntent().getParcelableExtra(ContactFormActivity.EXTRA_CONTACT);

        TextView name = findViewById(R.id.contactName);
        TextView phone = findViewById(R.id.contactPhone);
        TextView email = findViewById(R.id.contactEmail);
        TextView address = findViewById(R.id.contactAddress);
        TextView website = findViewById(R.id.contactWebsite);

        name.setText(contact.getFirstName() + " " + contact.getLastName());
        phone.setText(contact.getPhoneNumber());
        email.setText(contact.getEmailAddress());
        address.setText(contact.getAddress());
        website.setText(contact.getWebsite());

        callButton = findViewById(R.id.callButton);
        callButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                Uri number = Uri.parse("tel:" + contact.getPhoneNumber());
                Intent callIntent = new Intent(Intent.ACTION_DIAL, number);
                startActivity(callIntent);
            }
        });

        textButton = findViewById(R.id.textButton);
        textButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                Uri number = Uri.parse("smsto:" + contact.getPhoneNumber());
                Intent textIntent = new Intent(Intent.ACTION_SENDTO, number);
                startActivity(textIntent);
            }
        });

        emailButton = findViewById(R.id.emailButton);
        emailButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                Uri email = Uri.parse("mailto:" + contact.getEmailAddress());
                Intent emailIntent = new Intent(Intent.ACTION_SENDTO, email);
                startActivity(emailIntent);
            }
        });

        mapButton = findViewById(R.id.mapButton);
        mapButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                Uri address = Uri.parse("geo:0,0?q=" + contact.getAddress());
                Intent mapIntent = new Intent(Intent.ACTION_VIEW, address);
                mapIntent.setPackage("com.google.android.apps.maps");
                startActivity(mapIntent);
            }
        });

        webButton = findViewById(R.id.webButton);
        webButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                Uri website = Uri.parse("https:" + contact.getWebsite());
                Intent webIntent = new Intent(Intent.ACTION_VIEW, website);
                startActivity(webIntent);
            }
        });

    }
}
