
#include <iostream>
using namespace std;

// To store count of increasing order temples
// on left and right (including current temple)
struct Temple {
	int L;
	int R;
};

// Returns count of minimum offerings for
// n temples of given heights.
int offeringNumber(int n, int templeHeight[])
{
	// Initialize counts for all temples
	Temple chainSize[n];
	for (int i = 0; i < n; ++i) {
		chainSize[i].L = -1;
		chainSize[i].R = -1;
	}

	// Values corner temples
	chainSize[0].L = 1;
	chainSize[n - 1].R = 1;

	// Filling left and right values using same
	// values of previous(or next)
	for (int i = 1; i < n; ++i) {
		if (templeHeight[i - 1] < templeHeight[i])
			chainSize[i].L = chainSize[i - 1].L + 1;
		else
			chainSize[i].L = 1;
	}
	for (int i = n - 2; i >= 0; --i) {
		if (templeHeight[i + 1] < templeHeight[i])
			chainSize[i].R = chainSize[i + 1].R + 1;
		else
			chainSize[i].R = 1;
	}

	
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += max(chainSize[i].L, chainSize[i].R);
	return sum;
}


int main()
{
	int arr1[3] = { 1, 2, 2 };
	 cout<< offeringNumber(3, arr1) << "\n";
	int arr2[6] = { 1, 4, 3, 6, 2, 1 };
	cout << offeringNumber(6, arr2) << "\n";
	return 0;
}



