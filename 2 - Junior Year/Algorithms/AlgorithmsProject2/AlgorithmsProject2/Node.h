#ifndef NODE_H
#define NODE_H

class Node
{
	friend class BinarySearchTree;
public:
	Node();
	Node(int val);
	~Node();
	int getValue();
	Node* getLeftNode();
	Node* getRightNode();
private:
	Node* left;
	int value;
	Node* right;
};

#endif