/* singlylinkedlist.h */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
using namespace std;

#include "node.h"

class singlyLinkedList
{
public:
	singlyLinkedList();
	~singlyLinkedList();
	void addFront(Node* newNode);
	void displaySinglyLinkedList();
	void bubbleSort();
	void optimizedBubbleSort();

	void swapNode(Node* tNode);
	int findSmallestInt();
	void selectionSort();
private:
	Node* head;
};

#endif