#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> a, int low , int high);
void randomized_quicksort(vector<int> a, int low, int high);

int main()
{
	vector<int> a={4,5,2,6,7,1};
	quick_sort(a,0,a.size());

	for(auto temp : a)
		cout<<temp<<" ";

	return 0;
}

void quick_sort(vector<int> a, int low , int high)
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
}