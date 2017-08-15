#include <iostream>
#include <vector>

using namespace std;

int maxbit(vector<int> data, int n) //辅助函数，求数据的最大位数
void radixsort(vector<int> data, int n) //基数排序

int main()
{
	vector<int> v={101,201,99,55,206,708};
	radixsort(v,v.size());

	for(auto a : v)
		cout<< a <<" ";

	cout << endl;
	return 0;
}

int maxbit(vector<int> data, int n) //辅助函数，求数据的最大位数
{
    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void radixsort(vector<int> &data, int n) //基数排序
{
    int d = maxbit(data, n);
    int *tmp = newint[n];
    int *count = newint[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete[]tmp;
    delete[]count;
}