#ifndef INTERVALTREE
#define INTERVALTREE
#include <iostream>
#include <string>
using namespace std;
struct dataNode{
	int low;
	int high;
};
class BSTNode{
public:
	BSTNode *left, *right;
	BSTNode *parent;
	int val;
	dataNode d;
	string color;
	int m;         // 最大值
};

class IntervalTree{
public:
	IntervalTree(const dataNode &d)
	{
		root = new BSTNode();
		root->d = d;
		root->color = "black";
		root->left = NULL;
		root->right = NULL;
		root->m = d.high;
		root->parent = NULL;
		root->val = d.low;
	}

	BSTNode* insertBST(BSTNode *p, const dataNode &d);
	void insertIntervalTree(BSTNode *root1, const dataNode &d);
	void inorderOSRBTree(BSTNode *p);
	BSTNode* intervalSearch(BSTNode *p, const dataNode &d);
public:
	BSTNode *root;
	void destroyBST(BSTNode *p);
};


#endif
