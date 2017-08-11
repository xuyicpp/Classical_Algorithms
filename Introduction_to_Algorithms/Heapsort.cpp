#include <iostream>
//#include <vector>
#include <algorithm>

using namespace std;

void HeapAdjust(int *a, int i, int size)	//调整堆
{
	int lchild = 2*i;	//i的左孩子节点序号
	int rchild = 2*i + 1;	//i的右孩子节点序号
	int max=i;			//临时变量
	if(i<=size/2)		//如果i是叶节点就不用进行调整
	{
		if(lchild<=size && a[lchild]>a[max])
		{
			max = lchild;
		}

		if(rchild <= size && a[rchild]>a[max])
		{
			max = rchild;
		}

		if(max!=i)
		{
			swap(a[i],a[max]);
			HeapAdjust(a,max,size);
		}
	}
}

void BuildHeap(int *a, int size)
{
	int i;
	for(i=size/2;i>=1;--i)
	{
		HeapAdjust(a,i,size);
	}
}

void HeapSort(int *a, int size)
{
	int i;
	BuildHeap(a,size);
	for(i=size;i>=1;--i)
	{
		swap(a[1],a[i]);
		HeapAdjust(a,1,i-1);
	}
}

//数据堆的下标从1开始
int main()
{
	int a[]={0,16,20,3,11,17,8};

	int i_size = sizeof(a)/sizeof(int);//calculate the size of array

	HeapSort(a,i_size);
	for(int i=1;i<=i_size;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}