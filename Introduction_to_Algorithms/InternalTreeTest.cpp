#include <iostream>
#include "IntervalTree.h"
#include <vector>

using namespace std;

int main()
{
	int a[6] = {17, 5, 21, 4, 15, 7};
	int b[6] = {19, 11, 23, 8, 18, 10};
	vector<dataNode> data;
	for(int i = 0; i < 6; i++)
	{
		dataNode d;
		d.low = a[i];
		d.high = b[i];
		data.push_back(d);
	}
	IntervalTree interval(data[0]);
	for(int i = 1; i < data.size(); i++){
		interval.insertIntervalTree(interval.root, data[i]);
	}
	cout << "中序遍历的结果: " << endl;
	interval.inorderOSRBTree(interval.root);
	cout << endl;

	dataNode sd;
	sd.low = 18;
	sd.high = 25;
	BSTNode * bst = interval.intervalSearch(interval.root, sd);
	cout << "[" << bst->d.low << "," << bst->d.high << "]" << endl;
}