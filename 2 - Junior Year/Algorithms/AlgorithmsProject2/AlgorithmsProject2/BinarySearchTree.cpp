#include <iostream>
#include <vector>
using namespace std;

#include "Node.h"
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
}

Node* BinarySearchTree::getRoot()
{
	return(root);
}

/*
void BinarySearchTree::insert(Node* node)
{
	if (root == NULL)
		root = node;else
	{
		Node* tempNode = root;
		while (tempNode != NULL)
		{
			if (node->value < tempNode->value) // go left
			{
				if (tempNode->left != NULL)
					tempNode = tempNode ->left;
				else
				{
					tempNode->left = node;
					break;
				}
			}
			else // go right
			{
				if (tempNode->right != NULL)
					tempNode = tempNode ->right;
				else
				{
					tempNode->right = node;
					break;
				}
			}
		} // while
	} //if
}
*/

// The following code needs to be implemented by you
// Rearrange the input sequence in v and save the new sequence of integers in newV
// newV is a reference variable so it can be passed back to main
// 50 points for the implementation
// input: v: values saved in the original binary search tree which is a sorted sequence
//        start: the start position in the vector
//        end: the last position to the vector
// output: newV: Store the rearranged sequence
// algorithm: find the median as the pivot and save the pivot to newV
//            split the input sequence into left half sequence and right half sequence
//            recurese half sequence followed by right sequence
//            recursion stops if (start > end) or recurse.
void BinarySearchTree::reArrangeInputSequence(vector<int> v, int start, int end, vector<int>& newV)
{
	// YOUR CODE STARTS HERE!
	
	int median{ (start + end) / 2 };
	newV.push_back(v.at(median));

	if (start > end)
	{
		return;
	}
	
	vector<int> leftV;
	vector<int> rightV;

	for (int i{ 0 }; i < median; i++)
	{
		leftV.push_back(v.at(i));
	}

	for (int i{ median + 1 }; i <= end; i++)
	{
		rightV.push_back(v.at(i));
	}
	
	if (!leftV.empty())
	{
		reArrangeInputSequence(leftV, 0, leftV.size() - 1, newV);
	}
	
	if (!rightV.empty())
	{
		reArrangeInputSequence(rightV, 0, rightV.size() - 1, newV);
	}

}

void BinarySearchTree::insertRecursively(Node* troot, Node* newNode)
{
	if (troot == NULL)
		root = newNode;
	else
	{
		if (newNode->value < troot->value) {
			if (troot->left == NULL)
				troot->left = newNode;
			else
				insertRecursively(troot->left, newNode);
		}
		else
		{// go right
			if (troot->right != NULL)
				insertRecursively(troot->right, newNode);
			else
				troot->right = newNode;
		}
	}
}



void BinarySearchTree::collectDataUsingInorderTraversal(Node* root, vector<int>& v) // Left Root Right
{
	if (root != NULL)
	{
		collectDataUsingInorderTraversal(root->left, v);
		v.push_back(root->value);
		collectDataUsingInorderTraversal(root->right, v);
	}
}

void BinarySearchTree::inorderTraversal(Node* root) // Left Root Right
{
	if (root != NULL)
	{
		inorderTraversal(root->left);
		cout << root << " ";
		cout << root->left << " ";
		cout << root->value << " ";
		cout << root->right << endl;
		inorderTraversal(root->right);
	}
}

int BinarySearchTree::maxDepth(Node* root)
{
	/*
	  Compute the "maxDepth" of a tree -- the number of nodes along
	  the longest path from the root node down to the farthest leaf node.
	*/
	if (root == NULL) {
		return(-1);
	}
	else {
		// compute the depth of each subtree 
		int lDepth = maxDepth(root->left);
		int rDepth = maxDepth(root->right);
		// use the larger one 
		if (lDepth > rDepth) return(lDepth + 1);
		else return(rDepth + 1);
	}
}


/*
void BinarySearchTree::buildHeightBalancedBST(vector<int> v, int start, int end)
{
	Node* tNode;

	if (start > end)
		return;

	// find the middle index
	int mid = (start + end) / 2;

	// The root will be node storing the integer at the mid index
	tNode = new Node(v[mid]);
	insertRecursively(root, tNode);
	cout << tNode->value << endl;

	buildHeightBalancedBST(v, start, mid-1);
	buildHeightBalancedBST(v, mid+1, end);
}
*/