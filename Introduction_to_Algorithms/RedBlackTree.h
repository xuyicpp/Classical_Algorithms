/**
 * C++ RBTree
 * author xy
 */

#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_

#include <iostream>
#include <iomanip>	//iomanip.h是I/O流控制头文件,就像C里面的格式化输出一样.

using namespace std;

enum  RBTColor{ RED, BLACK};

template<class T>
class RBTNode
{
public:
	RBTColor color;
	T key;
	RBTNode* left;
	RBTNode* right;
	RBTNode* parent;

	RBTNode(T value, RBTColor c, RBTNode* p,RBTNode *l, RBTNode* r)
	:key(value),color(c),parent(),left(l),right(r) { }
};

template <class T>
class RBTree
{
private:
	RBTNode<T> *mRoot;	//root node

public:
	RBTree();
	~RBTree();

	//前序遍历"红黑树"
	void preOrder();
	// 中序遍历"红黑树"
	void inOrder();
	// 后序遍历"红黑树"
	void postOrder();

	// (递归实现)查找"红黑树"中键值为key的节点
	RBTNode<T>* search(T key);
	// (非递归实现)查找"红黑树"中键值为key的节点
	RBTNode<T>* iterativeSearch(T key);

	// 查找最小结点：返回最小结点的键值。
	T minimum();
	// 查找最大结点：返回最大结点的键值。
	T maximum();

	
};


#endif