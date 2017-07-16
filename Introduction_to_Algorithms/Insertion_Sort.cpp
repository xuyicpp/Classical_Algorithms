#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v={5,4,3,2,1,0};

	cout<<"Before sort:";
	for(auto q : v)
		cout<<q<<" ";
	cout<<endl;

	//algorithm
	for(int j = 1;j<=v.size();++j)
	{
		int key = v[j];
		//Insert A[j] into the sorted sequence A[1..J-1]
		int i = j -1;
		while(i >= 0 && v[i] > key)
		{
			v[i+1] = v[i];
			--i;
		}
		v[i+1] = key;
	}

	cout<<"After sort:";
	for(auto q : v)
		cout<<q<<" ";
	cout<<endl;

	return 0;
}