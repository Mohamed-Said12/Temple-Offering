
#include <iostream>
using namespace std;
#define n 6
int templeOfferings(int nums[])
{
	int offerings[n];
	offerings[0] = 1;

	for (int i = 1; i < n; i++)
	{
		if (nums[i] > nums[i - 1])
			offerings[i] = offerings[i - 1] + 1;
		else
			offerings[i] = 1;
	}
	for (int i = n - 2; i >= 0; i--)
	{
		if (nums[i] > nums[i + 1] && offerings[i] <= offerings[i + 1])
			offerings[i] = offerings[i + 1] + 1;
	}


	int sum = 0;
	for (int val : offerings)
		sum += val;
	return sum;
}
int main()
{
	int arr[] = { 1, 4, 3, 6, 2, 1 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	cout << (templeOfferings(arr));
	return 0;
}


