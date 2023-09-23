package com.example.dicecollector;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ImageView;
import android.widget.TextView;
import com.squareup.picasso.Picasso;
import androidx.annotation.NonNull;
import com.example.dicecollector.Dice;
import androidx.recyclerview.widget.RecyclerView;

import java.io.Serializable;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;


public class DiceRVAdapter extends RecyclerView.Adapter<DiceRVAdapter.ViewHolder> implements Serializable {

    private ArrayList<Dice> mDiceList;
    private Context mContext;
    public ArrayList<Dice> getDiceList(){return mDiceList;}
    private OnItemClickListener mOnItemClickListener;

    public interface OnItemClickListener
    {
        void onItemClick(int position);
    }

    public void setOnItemClickListener(final OnItemClickListener mItemClickListener)
    {
        this.mOnItemClickListener = mItemClickListener;
    }

    public DiceRVAdapter(Context context, ArrayList<Dice> items)
    {
        this.mDiceList = items;
        this.mContext = context;
    }


    public class ViewHolder extends RecyclerView.ViewHolder implements  View.OnClickListener{

        protected final TextView diceNameTextView;
        protected final TextView diceColorTextView;
        protected final TextView diceNumTextView;
        protected final ImageView diceImageView;
        protected final TextView noteTextView;
        public View item_parent;



        public ViewHolder(@NonNull View itemView) {
            super(itemView);

            diceNameTextView = (TextView) itemView.findViewById(R.id.diceNameTextView);
            diceColorTextView = (TextView) itemView.findViewById(R.id.diceColorTextView);
            diceNumTextView = (TextView) itemView.findViewById(R.id.diceNumTextView);
            diceImageView = (ImageView) itemView.findViewById(R.id.diceImageView);
            noteTextView = (TextView) itemView.findViewById(R.id.noteTextView);
            item_parent = itemView.findViewById(R.id.item_parent);
            item_parent.setOnClickListener(this);


        }

        public void onClick(View view)
        {
            mOnItemClickListener.onItemClick(getLayoutPosition());
        }

        public ImageView getDiceImageView() {
            return diceImageView;
        }

        public TextView getDiceColorTextView() {
            return diceColorTextView;
        }

        public TextView getDiceNameTextView() {
            return diceNameTextView;
        }

        public TextView getDiceNumTextView() {
            return diceNumTextView;
        }

        public TextView getNoteTextView() { return noteTextView; }
    }


    public DiceRVAdapter(ArrayList<Dice> diceList) { mDiceList = diceList;}


    @NonNull
    @Override
    public DiceRVAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {

            Context context = parent.getContext();
            LayoutInflater inflater = LayoutInflater.from(parent.getContext());

            // Inflate the custom layout
            View diceView = inflater.inflate(R.layout.item_layout, parent, false);

            // Return a new holder instance
            return new ViewHolder(diceView);

    }

    @Override
    public void onBindViewHolder(@NonNull DiceRVAdapter.ViewHolder holder, int position) {


        holder.getDiceNameTextView().setText((mDiceList.get(position)).getName());
        holder.getDiceNumTextView().setText((mDiceList.get(position)).getNumber());
        holder.getDiceColorTextView().setText((mDiceList.get(position)).getColor());
        holder.getNoteTextView().setText((mDiceList.get(position)).getNote());
        Picasso.get()
                .load("https://store.chessex.com:11552/images/"+ mDiceList.get(holder.getAdapterPosition()).getNumber() + ".jpg")
                .resize(500,500)
                .into(holder.getDiceImageView());



    }

    @Override
    public int getItemCount() {
        return mDiceList.size();
    }
}
