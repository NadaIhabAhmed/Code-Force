#include <iostream>
using namespace std;


int main()
{
	int num_search;
	int arrsize;
	int *ptr;
	int exists = 0;
	cin >> num_search;
	cin >> arrsize;
	ptr = new int[arrsize];

	for (int i = 0; i < arrsize; i++)
	{
		cin >> ptr[i];
	}


	int first = 0;
	int last = arrsize - 1;
	int middle = (first + last) / 2;
	int print = 0;
	while (first <= last)
	{
		if (ptr[middle] < num_search)
		{
			first = middle + 1;
			exists = 0;
			for (int i = first; i < last + 1; i++)
			{
				cout << ptr[i] << " ";
				print = 1;
			}
			if (print)
			{
				cout << "\n";
				print = 0;
			}
		}
		else if (ptr[middle] == num_search)
		{
			exists = 1;
			break;
		}
		else if (ptr[middle] > num_search)
		{
			last = middle - 1;
			exists = 0;
			for (int i = first; i < middle; i++)
			{
				cout << ptr[i] << " ";
				print = 1;
			}
			if (print)
			{
				cout << "\n";
				print = 0;
			}
		}
		middle = (first + last) / 2;
		
	}
	if (first > last)
	{
		exists = 0;
	}

	if (exists == 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

}