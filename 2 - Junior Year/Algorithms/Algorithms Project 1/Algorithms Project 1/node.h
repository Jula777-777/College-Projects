/* node.h */
/*

two classes 1: node.h   2. singlylinkedlist.h

nod1 (value + pointer) ---> node2 ---> node3 ---> ||||  <--- node.h
^
|               singlylinkedlist
----------------*node head;

*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
	friend class singlyLinkedList;
public:
	Node();
	Node(int value);
	~Node();
	int displayValue();
public:
	int value;
	Node* next;
};

#endif
