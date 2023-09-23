// University of Arkansas at Little Rock
// Department of Computer Science
// CPSC 2380: Algorithms
// Fall 2020
// Instructor: Dr. Chia-Chu Chiang
// Date Written: 10-01-2020
// Description: This program reads in a sequence of integers, 
//              sort the sequence in bubble sort, and print out the sequence 
//              from the head to the end of the singly linked list
// Student T-number (last 4 digits): 5708
// Student Name: Justin Dady
// Due Date: 10-15-2020 (Thursday) 
// Date written: 10-15-2020
// No late project, please. No uncompiled code.

// You need to submit node.h, singlylinkedlist.h, node.cpp, singlylinkedlist.cpp, and main.cpp to
// the blackboard and also to  
// TA, Siddartha Polishetti, email: spolishetti@ualr.edu with SUBJECT CPSC 2380 Project 1

// Goal of the project: Complexity analysis can be used to show that 
// there is room for improvement in the bubble sort algorithm.


// In Project 1, your are required to implement the code for bubble sort and optimized bubble sort
// using the data structure of sinngly linked list (nothing else).

/* Bubble Sort:
for (int i = 0; i < n; i++)
   for (int j = i; j < n; j++)
   {
	if (A[i] > A[j])
	{
	 temp = A[i];
	 A[i] = A[j];
	 A[j] = temp;
	}
   }
}
*/

/* Optimized Bubble Sort:
flag = 0;
for (int i = 0; i < n; i++)
   for (int j = 0; j < n-1; j++)
   {
	if (A[j] > A[j+1])
	{
	 temp = A[j];
	 A[j] = A[j+1];
	 A[j+1] = temp;
	 flag = 1; // if swapping occurs
	}
   }
	if (flag == 0)
	   break; // the input list already sorted, no need for the inner loop
}
*/

// The main program will create 10 nodes for storing a sequence of 10 integers
// bubble Sort() will be invoked to sort these 10 integers
// then optimizedBubbleSort will be invoked to sort the sorted sequence (degenerate case) again
// You will find out optimizedBubbleSort will take O(1) running time to do the sorting
// unlike bubbleSort taking O(n^2) run time to sort a sorted sequence.

// Lastly, in order to see the differences of bubbleSort and optimizedBubbleSort,
// also implement timer into both code, after the sorting, print out the runtime
// of sorting the sequence. For bubbleSort, no matter sorted or unsorted, it always 
// take O(n^2) runtime. But for optimizedBubbleSort, for unsorted sequence, like 
// bubbleSort, it takes O(n^2) runtime. However, for a sorted sequence,
// optimizedBubbleSort will take O(1) only. For a sorted sequence as a
// degenerate case, optimizedBubbleSort is more efficient than bubbleSort
// for sorting a sequence of integers.

// You MUST use this provided code for Project 1

#include <iostream>
using namespace std;

#include "node.h"
#include "singlylinkedlist.h"


int main()
{
	/* create 10 nodes */
	Node* n1 = new Node(23);  // objects creation (class instantiation)
	Node* n2 = new Node(-20);
	Node* n3 = new Node(7);
	Node* n4 = new Node(174);
	Node* n5 = new Node(56);
	Node* n6 = new Node(-98);
	Node* n7 = new Node(101);
	Node* n8 = new Node(46);
	Node* n9 = new Node(31);
	Node* n10 = new Node(5);

	/* create singly linked list */
	singlyLinkedList* sLL;
	sLL = new singlyLinkedList();

	/* insert 10 nodes into the singly linked list in First in, Last out manner */
	sLL->addFront(n1);
	sLL->addFront(n2);
	sLL->addFront(n3);
	sLL->addFront(n4);
	sLL->addFront(n5);
	sLL->addFront(n6);
	sLL->addFront(n7);
	sLL->addFront(n8);
	sLL->addFront(n9);
	sLL->addFront(n10);

	/* display the contents of the 10 nodes in the singly linked list */
	cout << "Original list: \n";
	sLL->displaySinglyLinkedList();
	cout << endl;

	///* The following code will act it is supposed to do
	//   when you are successfully implment bubbleSort and
	//   optimizedBubbleSort. */
	//sLL->bubbleSort(); // bubble sort the unsorted sequence
	//
	//cout << "List sorted with unoptimized bubble sort: \n";
	//sLL->displaySinglyLinkedList(); // a sorted sequence displayed
	//cout << endl;


	//sLL->optimizedBubbleSort(); // optimized bubble sort the already sorted sequence (a degenerate case)
	//							// the runtime should show O(1), it means time should be much less than runtime 
	//							// of bubbleSort()
	//
	//cout << "List sorted by optimized bubble sort: \n";
	//sLL->displaySinglyLinkedList(); // a sorted sequence displayed
	//cout << endl;

	//n2->next = n1;
	//sLL->swapNode(n2);

	sLL->selectionSort();
	sLL->displaySinglyLinkedList();
	cout << endl;

	cout << sLL->findSmallestInt() << endl;
	
	system("PAUSE");
	return 0;
}