#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(Node* node);
	void insertRecursively(Node* root, Node* Newnode);



	Node* getRoot();
	void inorderTraversal(Node* root);
	int maxDepth(Node* root);

	void collectDataUsingInorderTraversal(Node* root, vector<int>& v);
	void reArrangeInputSequence(vector<int> v, int start, int end, vector<int>& newV);
private:
	Node* root;
};

#endif