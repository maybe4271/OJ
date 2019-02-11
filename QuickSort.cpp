#include <iostream>
#include <vector>
#include <assert.h>
#include <stack>

using namespace std;

//recursive
void quicksort(vector<int>& vec, int start, int end)
{
	if (start >= end) return;

	int left = start;
	int right = end;
	int index = vec[start];

	while (left < right)
	{
		while (left < right && vec[right] >= index) right--;
		vec[left] = vec[right];
		
		while (left < right && vec[left] <= index) left++;
		vec[right] = vec[left];	
	}
	vec[left] = index;

	quicksort(vec, start, left-1);
	quicksort(vec, left+1, end);
}


//non-recursive
void QuickSort(vector<int>& vec, int start, int end)
{
	assert(!vec.empty());
	stack<int> st;
	st.push(start);
	st.push(end);

	while (!st.empty())
	{
		int right = st.top();
		int r = right;
		st.pop();
		int left = st.top();
		int l = left;
		st.pop();
		int index = vec[left];
		
		while (left < right)
		{
			while (left < right && vec[right] >= index) right--;
			vec[left] = vec[right];
			while (left < right && vec[left] <= index) left++;
			vec[right] = vec[left];
		}
		vec[left] = index;
		if (left - 1 > l)
		{
			st.push(l);
			st.push(left-1);
		}
		if (left + 1 < r)
		{
			st.push(left+1);
			st.push(r);
		}
	}
}

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(8);
	vec.push_back(7);
	vec.push_back(2);
	vec.push_back(0);
	vec.push_back(9);
	vec.push_back(6);
	
	QuickSort(vec, 0, vec.size()-1);
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << endl;
	}


	return 0;
}


