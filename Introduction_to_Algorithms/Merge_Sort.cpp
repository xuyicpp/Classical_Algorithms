#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& data, int start, int mid, int end, vector<int>& result);
void merge_sort(vector<int>& data, int start, int end, vector<int>& result);

int main()
{
	vector<int> v={5,4,3,2,1,0};
	vector<int> result(6);

	cout<<"Before sort:";
	for(auto q : v)
		cout<<q<<" ";
	cout<<endl;

	merge_sort(v,0,5,result);

	cout<<"After sort:";
	for(auto q : v)
		cout<<q<<" ";
	cout<<endl;
			
	return 0;
}

void merge(vector<int>& data, int start, int mid, int end, vector<int>& result)
{
	int i, j, k;
	i = start;
	j = mid + 1;		//避免重复比较data[mid]
	k = 0;
	while(i <= mid && j <= end)
	{
		if(data[i] <= data[j])
			result[k++] = data[i++];
		else
			result[k++] = data[j++];
	}
	while(i <= mid)
		result[k++] = data[i++];
	while(j <= end)
		result[k++] = data[j++];

	for(i = 0; i < k; ++i)
		data[start + i] = result[i];

	return;
}


void merge_sort(vector<int>& data, int start, int end, vector<int>& result)
{
	if(start < end)
	{
		int mid = (start + end) / 2;
		merge_sort(data, start, mid, result);
		merge_sort(data, mid + 1, end, result);
		merge(data, start, mid, end, result);
	}

	return;
}