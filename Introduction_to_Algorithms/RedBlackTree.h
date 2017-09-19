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


#endif