/* singlylinkedlist */

#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

#include "singlylinkedlist.h"

singlyLinkedList::singlyLinkedList()
{
	head = NULL;
}

singlyLinkedList::~singlyLinkedList()
{
}

void singlyLinkedList::addFront(Node* newNode)
{
	if (head == NULL)
		head = newNode;
	else
	{
		// Add code here! 
		/*    node1-->||| (before)   what is after   node2 --> node1 -->||| */

		newNode->next = head;
		head = newNode;
	};
}

void singlyLinkedList::displaySinglyLinkedList()
{
	Node* tempHead;

	tempHead = head;

	while (tempHead != NULL)
	{
		cout << tempHead->value << " ";
		tempHead = tempHead->next;
	}
	cout << endl;
}

void singlyLinkedList::bubbleSort() /* 50 points */
{
	// Your Code Starts Here!
	// Please display the runtime for this task before exit 40 points
	// start clock
	// ....
	// stop the clock
	// display the (stop-clock - start-clock 10 Points

	auto start{chrono::high_resolution_clock::now() };

	for (Node* iNode {head}; iNode != nullptr; iNode = iNode->next)
	{
		for (Node* jNode {iNode}; jNode != nullptr; jNode = jNode->next)
		{
			if (iNode->value > jNode->value)
			{
				int temp{ iNode->value };
				iNode->value = jNode->value;
				jNode->value = temp;
			}
		}
	}

	auto stop{ chrono::high_resolution_clock::now() };

	auto duration{ chrono::duration_cast<chrono::nanoseconds>(stop - start) };
	cout << "Time used by unoptimized bubble sort: " << duration.count() << " nanoseconds\n";
}

void singlyLinkedList::optimizedBubbleSort() /* 35 points */
{
	// Your Code Starts Here!
	// Please display the runtime for this task before exit
	// start clock
	// ....
	// stop the clock
	// display the (stop-clock - start-clock /* 5 points */

	auto start{ chrono::high_resolution_clock::now() };
	
	int flag{ 0 };
	for (Node* iNode {head}; iNode != nullptr; iNode = iNode->next)
	{
		for (Node* jNode {head}; jNode->next != nullptr; jNode = jNode->next)
		{
			if (jNode->value > jNode->next->value)
			{
				int temp{ jNode->value };
				jNode->value = jNode->next->value;
				jNode->next->value = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}

	auto stop{ chrono::high_resolution_clock::now() };

	auto duration{ chrono::duration_cast<chrono::nanoseconds>(stop - start) };
	cout << "Time used by optimized bubble sort: " << duration.count() << " nanoseconds\n";
}

void singlyLinkedList::swapNode(Node* tNode)
{
	Node* origHead{ head };
	Node* origTNode{ tNode };
	
	if (head == tNode)
	{
		return;
	}

	if (head == NULL || tNode == NULL)
	{
		return;
	}

	if (origHead != NULL)
	{
		origHead->next = tNode;
	}
	else
	{
		head = tNode;
	}
	if (origTNode != NULL)
	{
		tNode->next = head;
	}

	Node* temp{ tNode->next };
	tNode->next = head->next;
	head->next = temp;
	
}

int singlyLinkedList::findSmallestInt()
{
	int min{ head->value };
	
	for (Node* curr {head->next}; curr != nullptr; curr = curr->next)
	{
		if (curr->value < min)
		{
			min = curr->value;
		}
	}
	return min;
}

void singlyLinkedList::selectionSort()
{
	Node* min{ head };
	
	for (Node* iNode {head}; iNode->next->next != nullptr; iNode = iNode->next)
	{
		min = iNode;
		for (Node* jNode {iNode->next}; jNode->next != nullptr; jNode = jNode->next)
		{
			if (jNode->value < min->value)
			{
				min = jNode;
			}
			
			int temp{ iNode->value };
			iNode->value = min->value;
			min->value = temp;
		}
	}
}
