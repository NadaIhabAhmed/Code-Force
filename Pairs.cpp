#include<iostream>
#include <algorithm> 
using namespace std; 

bool exist(int A[], int arr_size, int sum) 
{ 
    int l, r; 
  
    sort(A, A + arr_size); 
  
    
    l = 0; 
    r = arr_size - 1;  
    while (l < r) 
    { 
        if(A[l] + A[r] == sum) 
            return 1;  
        else if(A[l] + A[r] < sum) 
            l++; 
        else // A[i] + A[j] > sum 
            r--; 
    }  
    return 0; 
} 
  
int main() 
{ 
    int num_search;
    int arrsize;
    int *ptr;
    int exists = 0;
    cin>>arrsize;
    cin>>num_search;
    ptr = new int [arrsize];
    
    for(int i = 0; i < arrsize; i++)
    {
        cin>>ptr[i];
    }

      
    // Function calling 
    if (exist(ptr, arrsize, num_search)) 
    {
        cout << "YES"; 
    }
    else
    {
        cout<<"NO";
    }
          
    return 0; 
} 