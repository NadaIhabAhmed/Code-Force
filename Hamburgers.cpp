#include<iostream>
using namespace std;

int main()
{
    long long nc,nb,ns; // quantity of each one in the kitchen
    long long ps,pb,pc; // price of each one
    long long Bcount = 0, Ccount = 0, Scount = 0; // from the recipe
    long long r; // money that he got

    string s;
    long long min = 0;
    long long max = 10000000000000;
    long long cost;
    cin>>s; // take input from user

    for(int i = 0; i < s.size() ; i++) 
    {
        //++mp[s[i]];
        if(s[i] == 'B')
        {
            Bcount++;
        }
        else if (s[i] == 'C')
        {
            Ccount++;
        }
        else if(s[i] == 'S')
        {
            Scount++;
        }
    }
    
        cin >> nb >> ns >> nc; // quantity in the kitchen
        cin >> pb >> ps >> pc; // price of each
        cin >> r;
        
        while(min + 1 < max)
        {
            long long mid = (max + min) / 2;
            long long cb = (Bcount * mid > nb ? (Bcount * mid - nb) : 0 );
            long long cs = (Scount * mid > ns ? (Scount * mid - ns) : 0 );
            long long cc = (Ccount * mid > nc ? (Ccount * mid - nc) : 0 );

            cost = cs * ps + cb * pb + cc * pc;
            if(cost <= r)
            {
                min = mid;
            }  
            else 
            {
                max = mid;   
            }
    }
  

    cout<<min<<endl;

}