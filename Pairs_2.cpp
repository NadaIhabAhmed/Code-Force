
#include<iostream>
#include <algorithm> 
using namespace std;

int exist(int A[], int arr_size, int sum)
{
	int l, r;
	int right = 0, left = 0, count = 0;
	sort(A, A + arr_size);


	l = 0;
	r = arr_size - 1;
	while (l < r)
	{
		if (A[l] + A[r] == sum)
		{
			count++;
			if (left == 1)
			{
				l++;
			}
			else if (right == 1)
			{
				r--;
			}


		}
		else if (A[l] + A[r] < sum)
		{
			l++;
			left = 1; right = 0;
		}
		else // A[i] + A[j] > sum
		{
			r--;
			right = 1; left = 0;
		}
	}
	return count;
}

int main()
{
	int num_search;
	int arrsize;
	int *ptr;
	int exists = 0;
	cin >> arrsize;
	cin >> num_search;
	ptr = new int[arrsize];

	for (int i = 0; i < arrsize; i++)
	{
		cin >> ptr[i];
	}


	// Function calling 
	cout << exist(ptr, arrsize, num_search);


}