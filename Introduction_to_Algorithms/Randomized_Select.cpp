#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap(int &m, int &n);
int randomized_select(vector<int> &A, int p, int r, int i);
int random_partition(vector<int> &A, int p, int r);

int main()
{
	vector<int> v={6,10,13,5,8,3,2,11};

	for(auto a : v)
		cout<<a<<" ";
	cout<<endl;

	int result = randomized_select(v,0,7,3);
	cout<<result<<endl;
	return 0;
}

void swap(int &m, int &n)
{
	int tmp;
	tmp = m;
	m = n;
	n = tmp;
	return;
}

//随机快速排序分划程序
int random_partition(vector<int> &A, int p, int q)
{
	srand(time(NULL));
	int m = rand()%(q-p+1) + p;
	swap(A[m],A[p]);

	int x = A[p];
	int i = p;

	for(int j = p+1; j <= q; ++j)
	{
		if(A[j] < x)
		{
			i = i+1;
			swap(A[i],A[j]);
		}
	}

	swap(A[p],A[i]);

	return i;
}

//随机选择统计函数
int randomized_select(vector<int> &A, int p, int q, int k)
{
	if(p == q)
		return A[p];

	int pivot = random_partition(A,p,q);
	int i = pivot - p + 1;

	if(i==k)
		return A[pivot];
	else if(i<k)
		return randomized_select(A,pivot+1,q,k-i);//第k小的数不在主元左边，则在右边递归选择
	else 
		return randomized_select(A,p,pivot-1,k);//第k小的数不在主元右边，则在左边递归选择
}