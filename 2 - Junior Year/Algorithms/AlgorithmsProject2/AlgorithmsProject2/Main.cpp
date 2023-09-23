// University of Arkansas at Little Rock
// Department of Computer Science
// CPSC 2380: Algorithms
// Fall 2020
// Instructor: Dr. Chia-Chu Chiang
// Date Written: 11-10-2020
// Description: This program builds up a binary search tree from a sequence of integers in the asending (or descending)  order, 
//              the height of this binary search tree is n, so the search O(n) in this worst case. 
//              We can improve the complexity by building up a height balanced binary search tree.
//              The height balanced binary search tree (+- 1 on depth or height difference on left and right subtree) 
//              can shorten the height from O(n) worst case to the average case O(log n) even in worst case the input 
//              is in the sorted order.
// Student T-number (last 4 digitd): 5708
// Student Name: Justin Dady
// Due Date: 12-3-2020 (Thursday), Midnight <------------------------------------------------------------------------ 
// Date of written: 11/17/2020
// No late project, please. No uncompiled code.

// You need to submit Mode.h, Node.cpp, BinarySearchTree.h, BinarySearchTree.cpp, and Main.cpp to
// the blackboard and also to TA, Siddartha Polishetti, email: spolishetti@ualr.edu with SUBJECT CPSC 2380 Project 2 <--

// Goal of the project: Complexity analysis can be used to show that 
// there is room for improvement in the Binary Search Tree algorithm.


// In Project 2, your are required to implement the code for height balanced binary search tree
// using the data structure of binary search tree (nothing else).
// Given a sorted sequence of integers, a binary search tree is built, and the search O(n), no good.
// Therefore, rearrange the sequence of integers for the input data, the same binary search tree can be used to
// build a height balanced tree which improves Big-Oh from O(n) to O(log n) without modifying the
// binary search tree code! Is it beautiful, isn't it?

#include <iostream>
#include <vector>
using namespace std;

#include "Node.h"
#include "BinarySearchTree.h"

int main()
{
	/* The following reads in the integers from the binary search tree.
	   Building a binary search tree for the worst case of sorted integers.
	*/
	BinarySearchTree* bst = new BinarySearchTree();

	Node* node5 = new Node(5);
	bst->insertRecursively(bst->getRoot(), node5);

	Node* node6 = new Node(6);
	bst->insertRecursively(bst->getRoot(), node6);

	Node* node7 = new Node(7);
	bst->insertRecursively(bst->getRoot(), node7);

	Node* node8 = new Node(8);
	bst->insertRecursively(bst->getRoot(), node8);

	Node* node9 = new Node(9);
	bst->insertRecursively(bst->getRoot(), node9);

	Node* node10 = new Node(10);
	bst->insertRecursively(bst->getRoot(), node10);

	cout << "Binary Tree with sorted sequence of integers: \n \n";
	
	// depth
	cout << "max depth (level) starting with 0: " << bst->maxDepth(bst->getRoot()) << endl;

	// inorder traversal
	// Do not modify the code for inorder traversal
	// It displays the structure of binary search tree for verification
	vector<int> intVec;
	vector<int> intNewVec;
	cout << endl << "Inorder Traversal: " << endl;
	bst->inorderTraversal(bst->getRoot());
	cout << endl;


	// collect data and save it into intVec
	bst->collectDataUsingInorderTraversal(bst->getRoot(), intVec);
	// use vector to implement arrays
	// iterate the intVec to display the integers in the asending order
	// You can access them with operator[], just like an array
	for (vector<int>::size_type i = 0; i < intVec.size(); ++i) {
		cout << "intVec[" << i << "] = " << intVec[i] << '\n';
	}
	cout << endl;

	// You don't have to modify the code above
	/*--------------------  Start of building a height balanced binary search tree --------------- */

	/* The following rearranges the input sequence of integers in
	   a vector (dynamic arrays) in STL. For example,
	   input sequence 5, 6, 7, 8, 9, 10 in Intvec,
	   you are rearranging the input sequence by decomposing the sequence into halves recursively,
	   6 integers in the sequence, (1+6)/2 = 3.5 (median), two halves with the pivot intVec[3] = 7 (save into newVec)
	   Left: 5, 6
		   intVec[1+2/2] = intVec[1] with the pivot 5 (save into newVec) with two halves empty for left and 6 in the right
		   right: 6 intVec[1] = 6 with the pivot 6 (save into newVec) stop the left recusion because
		   two halves are empty. STOP!
		   The sequence of this rearranged integers in newVec is  7, 5, 6! Done with the left subtree
	   Right: 8, 9, 10
		   intVec[1+3/2] = intVec[2] with the pivot 9 (save into newVec) with two halves 8 for left and 10 in the right
		   left: 8, intVec[1] = 8 with the pivot 8 and two halves are empty, done with the left recursion
		   right: 10, intVec[1] = 10 with the pivot 10 (save into newVec) stop the right recusion because
		   two halves are empty. STOP!
		   The sequence of this rearranged integers in newVec is  7, 5, 6, 9, 8, 10 Done with the left subtree
	*/
	// Reading the values from newVec and call Building binary Search tree one value at a time
	// When the input is exhausted, you will have a height balnaced binary search tree
	BinarySearchTree* HeightBalancedBST = new BinarySearchTree();

	/* Rearrange the input sequence into intNewVec
	   50 Points to implement this method in BinarySearchTree.cpp
	*/
	HeightBalancedBST->reArrangeInputSequence(intVec, 0, intVec.size() - 1, intNewVec);  // 50 points to implement reArrangeInputSequence

	// Implement a section of code to loop through intNewVec 
	// for each individual value, insert a node with the value into HeightBalancedBST
	// you should call insertRecursively function to insert the node in the loop
	// 45 Points 
	// YOUR CODE START HERE

	for (int i : intNewVec)
	{
		Node* tempNode = new Node(i);
		HeightBalancedBST->insertRecursively(HeightBalancedBST->getRoot(), tempNode);
	}

	cout << "Height Balanced Binary Tree: \n \n";
	
	// depth
	cout << "max depth (level) starting with 0: " << HeightBalancedBST->maxDepth(HeightBalancedBST->getRoot()) << endl;

	// inorder traversal
	// Do not modify the code for inorder traversal
	// It displays the structure of binary search tree for verification
	cout << endl << "Inorder Traversal: " << endl;
	HeightBalancedBST->inorderTraversal(HeightBalancedBST->getRoot());
	cout << endl;

	system("PAUSE");
	return 0;
}