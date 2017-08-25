//验证HashTable类的成员函数
#include <iostream>
#include <string>
#include <assert.h>
#include <cmath>

using namespace std;

//对两个数值型关键字的比较约定为如下的宏定义
#define EQ(a, b) ((a) == (b))
//const int EMPTY = 0;	//设置0为无数据标志(此时关键字不可为0)
//const int TOMB = -1;	//设置-1为删除数据标志(此时关键字不可为-1)
typedef int KeyType;

//定义模板<D>的实参HD及相应的I/O操作
struct HD
{
	KeyType key;
	int order;
};

void Visit(int i, HD* c)
{
	cout << '[' << i << "]: " << '(' << c->key << ", " << c->order << ')' << endl;
}

void Visit(HD c)
{
	cout << '(' << c.key << ", " << c.order << ')';
}

// void InputFromFile(ifstream &f, HD &c)
// {
// 	f >> c.key >> c.order;
// }

// void InputKey(KeyType &k)
// {
// 	cin >> k;
// }

#include "HashTable.h"

int main()
{
	HashTable<HD> h;
	int i, j, n, p=0;
	bool m;

	HD e[10] = {{17, 1},{60, 2},{29, 3},{38, 4},{1 ,5},{2 ,6},
{3 ,7},{4 ,8},{60, 9},{13, 10}};

	KeyType K;
	// ifstream fin("input.txt");	//第一行的数表示数据个数
	// fin>>n;
	n = 10;
	//建立哈希表
	for(i = 0; i<n; i++)
	{
		// InputFromFile(fin, e);
		j = h.InsertHash(e[i]);
		if(j == DUPLICATE)
		{
			cout<<"哈希表中已有关键字为"<<e[i].key<<"的数据，无法再插入数据";
			Visit(e[i]);
			cout<<endl;
		}
		if(j == UNSUCCESS)	//插入不成功，重建哈希表
			j=h.InsertHash(e[i]);
	}

	cout<<"按哈希地址的顺序遍历哈希表："<<endl;
	h.TraverseHash(Visit);

	//删除数据测试
	HD tempe;
	cout<<"请输入待删除数据的关键字： 13"<<endl;
	KeyType k = 13;
	m = h.DeleteHash(k, tempe);
	if(m)
	{
		cout<< "成功删除数据";
		Visit(tempe);
		cout<< endl;
	}
	else
		cout<< "不存在关键字，无法删除！"<<endl;

	cout<<"按哈希地址的顺序遍历哈希表："<<endl;
	h.TraverseHash(Visit);

	//查询数据测试
	cout<<"请输入待查找数据的关键字：4"<<endl;
	// InputKey(k);
	k = 4;
	n = 0;
	j = h.SearchHash(k, p, n);
	if(j==SUCCESS)
	{
		Visit(h.GetElem(p));
		cout<<endl;
	}
	else
		cout<<"未找到"<<endl;

	//插入数据测试
	cout<<"插入数据，请输入待插入数据的关键字：16"<<endl;
	//InputKey(e.key);
	tempe.key = 16;
 	cout<<"请输入待插入数据的order：15"<<endl;
 	//cin>>e.order;
 	tempe.order = 15;
 	j = h.InsertHash(tempe);
 	if(j==DUPLICATE)
 	{
 		cout<<"哈希表中已有关键字为" << tempe.key << "的数据，无法再插入数据";
 		Visit(tempe);
 		cout<<endl;
 	}
 	if(j == UNSUCCESS)//插入不成功，重建哈希表
 		j = h.InsertHash(tempe);
 	cout<<"按哈希地址的顺序遍历哈希表："<<endl;
 	h.TraverseHash(Visit);

	return 0;
}