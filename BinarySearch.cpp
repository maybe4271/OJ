#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

//Rescursive
int binarysearch(vector<int>& vec, int left, int right, int key)
{
	if (left > right)
		return -1;

	int mid = (left + right)/2;

	if (vec[mid] == key)
		return mid;
	else if (vec[mid] < key)
		return binarysearch(vec, mid+1, right, key);
	else
		return binarysearch(vec, left, mid-1, key);
}

//non-Rescursive
int BinarySearch(vector<int>& vec, int left, int right, int key)
{
	assert(!vec.empty());
	int mid;

	while (left <= right)
	{
		mid = (left + right)/2;

		if (vec[mid] < key)
		{
			left = mid + 1;
		}
		else if (vec[mid] > key)
		{
			right = mid - 1;
		}
		else
			return mid;
	}

	return -1;
}



int main()
{
	vector<int> vec;
	int key;
	cout << "please input a number" << endl;
	cin >> key;
	for (int i = 0; i < 11; i++)
		vec.push_back(i);

	cout << "all number is :" << "[ ";
	for (auto iter : vec)
	{
		cout << iter << " ";
	}
	cout << "]" << endl;

	int result = binarysearch(vec, 0, vec.size()-1, key);
	if (result > 0)
		cout << "the number " << key << " is in vector" << endl;
	else
		cout << "we can't find [" << key << "] in vector" << endl;

	return 0;	
}
