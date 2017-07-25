#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> v, int key, int low, int high);

int main()
{
	vector<int> v={0,1,2,3,4,5,6,7,8,9,10};

	cout<<"If find the number 9 cout the number else -1"<<endl;

	cout<<BinarySearch(v,9,0,v.size())+1<<endl;

	return 0;
}

int BinarySearch(vector<int> v, int key, int low, int high)
{
	int mid;
	if(low>high)
		return -1;
	mid = (low+high)/2;

	if(v[mid]==key)
		return mid;
	else if (v[mid]>key)
	{
		return BinarySearch(v, key ,low, mid-1);
	}
	else 
		return BinarySearch(v,key,mid+1,high);

}