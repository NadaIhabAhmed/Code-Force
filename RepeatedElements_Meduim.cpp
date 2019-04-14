#include <iostream>
using namespace std;

int main()
{
    int arrsize;
    //int *ptr;
    cin>>arrsize;
    //ptr = new int [arrsize];
    
    int arr[arrsize];
    int rep = 0;
    for(int i = 0; i < arrsize; i++) // user inputs array elements
    {
        cin>>arr[i];
    }

    for(int i = 0; i < arrsize - 1 ; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            rep = 1;
        }
         
    }
    if (rep == 1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }     
}
