#include <iostream>

using namespace std;

int main()
{
    int arrsize;
    int *ptr;
    cin>>arrsize;
    ptr = new int [arrsize];
    int elements;
    int rep = 0;
    
    for(int i = 0; i < arrsize; i++)
    {
        cin>>ptr[i];
    }

   
    for(int i = 0; i < arrsize; i++)
    {
        for(int j = i+1; j < arrsize; j++)
        {
            if (ptr[i] == ptr[j]) {
                rep = 1;
            }
            
        }
        
    }
    if (rep == 1) {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    
    
        

}