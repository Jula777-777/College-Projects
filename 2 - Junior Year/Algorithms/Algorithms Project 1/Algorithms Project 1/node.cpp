/* node.cpp */

#include <iostream>
using namespace std;

#include "node.h"

Node::Node()
{
	value = 0;
	next = NULL;
}

Node::Node(int v)
{
	value = v;
	next = NULL;
}

Node::~Node()
{
}

int Node::displayValue()
{
	return value;
}