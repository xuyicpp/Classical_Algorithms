#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &A, int p, int q);
int GetMedian(vector<int> &A, int p, int q);
int partitionWithPivot(vector<int> &A, int p, int q,int pivot);
void swap(int &m, int &n);
int WorseLinearSelect(vector<int> &A, int p, int q, int k);

int main()
{
	int a[10] = {23, 4, 34, 345,3,21,45,246,98,50};
	vector<int> vec_int(a,a+10);

	for(auto a : vec_int)
		cout<<a<<" ";
	cout<<endl;

	int kmin=WorseLinearSelect(vec_int,0,9,2);
	cout<<"2nd is "<<kmin<<endl;

	return 0;
}


void insertion_sort(vector<int> &A, int p, int q)
{
	int i,j;
	int key;
	int len=q-p+1;
	for(j=p+1;j<=q;j++)
	{
		i = j-1;
		key = A[j];

		while(i >= p && A[i] > key)
		{
			A[i+1] = A[i];
			i--;
		}

		A[i+1] = key;
	}
}

//利用插入排序选择中位数
int GetMedian(vector<int> &A, int p, int q)
{
	insertion_sort(A,p,q);	//插入排序
	return A[(q-p)/2 + p];	//返回中位数，有两个中位数的话返回较小的那个
}

 /*
  *    根据指定的划分主元pivot来划分数组
  *    并返回主元的顺序位置
 */

int partitionWithPivot(vector<int> &A, int p, int q,int pivot)
{
	//先把主元交换到数组首元素
	for(int i = p; i<q; i++)
	{
		if(A[i] == pivot)
		{
			swap(A[i],A[p]);
			break;
		}
	}
	//常规的快速排序划分程序
	int x = A[p];
	int i = p;
	for(int j = p+1; j<=q; ++j)
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

/*
*    最坏情况下线性时间选择算法
*    此算法依然是建立在快速排序的划分算法基础之上的
*    但是与randomizedSelect算法的不同指之处，就是次算法的本质
*    是保证了每次划分选择的划分主元一定是一个较好的主元，算法先对数组5个一组进行分组
*    然后选择每组的中位数，再递归的选择各组中位数中的中位数作为数组的划分主元，以此保证划分的平衡性
*    选择中位数的时候必须使用递归调用的方法才能降低时间复杂度
*    从而保证在最坏情况下都得到一个好的划分
*    最坏情况下时间复杂度为O(n)
*/

int WorseLinearSelect(vector<int> &A, int p, int q, int k)
{
	 // 将输入数组的n个元素划分为n/5（上取整）组，每组5个元素，
     // 且至多只有一个组有剩下的n%5个元素组成。
     if(p==q)
     	return A[p];

     int len = q-p+1;
     int medianCount = 1;
     if(len>5)
     	medianCount = len%5 > 0 ? len/5 + 1 : len/5;
     vector<int> medians(medianCount);//存放每组的中位数

     //寻找每个组的中位数。首先对每组中的元素（至多为5个）进行插入排序，
     //然后从排序后的序列中选择出中位数
     int m = p;
     for(int j=0, m=p; j < medianCount - 1; j++)
     {
     	medians[j] = GetMedian(A,m,m+4);
     	m += 5;
     }
     medians[medianCount - 1] = GetMedian(A	,m, q);

     //对第2步中找出的n/5（上取整）个中位数，递归调用SELECT以找出其中位数pivot。
     //(如果是偶数取下中位数)
     int pivot = WorseLinearSelect(medians, 0, medianCount - 1, (medianCount+1)/2);
     //调用PARTITION过程，按照中位数pivot对输入数组进行划分。确定中位数pivot的位置r。
     int r = partitionWithPivot(A, p, q, pivot);
     int num = r-p+1;

     //如果num=k，则返回pivot。否则，如果k<num，则在地区间递归调用SELECT以找出第k小的元素，
     //若干k>num，则在高区找第(k-num)个最小元素。
     if(num == k)
     	return pivot;
     else if(num > k)
     	return WorseLinearSelect(A,p,r-1,k);
     else
     	return WorseLinearSelect(A,r+1,q,k-num);
}

void swap(int &m, int &n)
{
	int tmp;
	tmp = m;
	m = n;
	n = tmp;
	return;
}


