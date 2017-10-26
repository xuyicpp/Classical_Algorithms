#ifndef OSRBTREE
#define OSRBTREE
#include <iostream>
#include <string>
using namespace std;

class BSTNode{
public:
	BSTNode *left, *right;
	BSTNode *parent;
	int val;
	string color;
	int size;
};

class OSRBTree{
public:
	OSRBTree(const int &rootVal){
		root = new BSTNode();
		root->val = rootVal;
		root->left = NULL;
		root->right = NULL;
		root->color = "black";
		root->size = 1;
		root->parent = NULL;
	}
	BSTNode* insertBST(BSTNode *p, const int &value);
	void insertOSRBTree(BSTNode *root1, const int &value);
	void inorderOSRBTree(BSTNode *p);
	BSTNode* os_select(BSTNode *p, const int &ith);
	int os_rank(BSTNode *p, const int &value);
public:
	BSTNode *root;
};

#endif