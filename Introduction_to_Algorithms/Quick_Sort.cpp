#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void quick_sort(vector<int> &a, int low , int high);
void randomized_quicksort(vector<int> &a, int low, int high);

int main()
{
	
	vector<int> a={4,5,2,6,7,1};

	for(auto temp : a)
		cout<<temp<<" ";
	cout<<endl;

	quick_sort(a,0,a.size());

	for(auto temp : a)
		cout<<temp<<" ";
	cout<<endl;

	vector<int> b={4,5,2,6,7,1};

	for(auto temp : b)
		cout<<temp<<" ";
	cout<<endl;

	randomized_quicksort(b,0,b.size());

	for(auto temp : b)
		cout<<temp<<" ";
	cout<<endl;

	return 0;
}

void quick_sort(vector<int> &a, int low , int high)
{
	if(low>=high)
	{
		return;
	}
	int first = low;
	int last = high;
	int key = a[first];

	while(first < last)
	{
		while(first < last && a[last] >= key)
		{
			--last;
		}

		a[first] = a[last];

		while(first < last && a[first] <= key)
		{
			++first;
		}

		a[last] = a[first];
	}

	a[first] = key;

	quick_sort(a, low, first-1);
	quick_sort(a, first+1, high);

	return;
}

void randomized_quicksort(vector<int> &a, int low, int high)
{
	if(low>=high)
	{
		return;
	}

	//随机交换中间值
	srand(time(0));
	int i=random()%(high-low)+low;
    int temp1 = a[low];
    a[low] = a[i];
    a[i] = temp1;

	int first = low;
	int last = high;
	int key = a[first];

	while(first < last)
	{
		while(first < last && a[last] >= key)
		{
			--last;
		}

		a[first] = a[last];

		while(first < last && a[first] <= key)
		{
			++first;
		}

		a[last] = a[first];
	}

	a[first] = key;

	randomized_quicksort(a, low, first-1);
	randomized_quicksort(a, first+1, high);

	return;
}
