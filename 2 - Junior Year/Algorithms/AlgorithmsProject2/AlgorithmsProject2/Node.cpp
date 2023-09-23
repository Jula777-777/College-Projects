#ifndef NODE_CPP
#define NODE_CPP
#include <iostream>
using namespace std;

#include "Node.h"

Node::Node()
{
	left = NULL;
	value = 0;
	right = NULL;
}

Node::Node(int val)
{
	left = NULL;
	right = NULL;
	value = val;
} 

Node::~Node()
{
}

int Node::getValue()
{
	return value;
}

// My code needs this, but your code might not need it
// depending your design of the algorithm
// You can leave it, it won;t hurt
Node* Node::getLeftNode()
{
	return (left);
}

// My code needs this, but your code might not need it
// depending your design of the algorithm
// You can leave it, it won;t hurt
Node* Node::getRightNode()
{
	return (right);
}
#endif