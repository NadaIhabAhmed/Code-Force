#include<iostream>
#include<string>

using namespace std;


int main()
{

    string alpha_string = "";
    string str;
    cin>>str;
    


    int j = 0;
    for (int i = 0; i < str.length(); i++)
    {
        //cout<<str[i];
        //cout<<"1";
        if (j < 0)
        {
            j = 0;
        }
        if (isdigit(str[i]) || isalpha(str[i]))
        {
            //cout<<"2";
            alpha_string.insert(j, 1, str[i]);
            
            j++;
        }
		else if (alpha_string.length() > 0)
		{
			switch (str[i])
			{
				case '-':
					//cout<<"3";
					if (j > 0)
					{
						//cout<<"4";
						alpha_string.erase(j - 1, 1);
					}
					j --;
					break;
				case '<':
				    //cout<<"5";
					if (j > 0)
					{
						//cout<<"6";
						j --;
					}  
					break;
				case '>':
					//cout<<"7";
					if (j <= alpha_string.length() - 1)
					{
						//cout<<"8";
						j ++;
					}
					break;
			}
		}
		/*
        else if(str[i] == '-' && alpha_string.length() > 0)
        {
            //cout<<"3";
            if (j > 0)
            {
                cout<<"4";
                alpha_string.erase(j - 1, 1);
            }
            j --;
       }
       else if (str[i] = '<' && alpha_string.length() > 0)
       {
           //cout<<"5";
           if (j > 0)
           {
               //cout<<"6";
               j --;
           }           
       }
       else if(str[i] = '>' && alpha_string.length() > 0)
       {
           //cout<<"7";
           if (j <= alpha_string.length() - 1)
           {
               cout<<"8";
               j ++;
           }
           
       } */
    }
        
    

    cout<<alpha_string;
    
}