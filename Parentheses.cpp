#include <iostream>
using namespace std;

/*----------------------------------------------------------------------------------------------*/
class node
{
private:
	int data; // data in each node
	node * next; // pointer wich points to the next node

public:
	// Default constructor
	node() {
		data = 0;
		next = NULL; // next points to null (ground)
	}
	//Other constructor

	node(int d) {  /*same as*/ /*node(int d) : data(d), next(NULL) {} ;*/
		data = d;
		next = NULL;
	}

	/*-----------------------------------------------------------------------------------*/
	friend class list; // class node is friend with class list so list can use node's functions
};

/*----------------------------------------------------------------------------------------------*/
class list
{
private:
	node * chain; // temp node
	node * head;
	node * tail;

public:
	list() { // default constructor
		chain = NULL; head = NULL; tail = NULL;
	}

	void createNode(int d) {/*if the constructor on line 18 didn't exist we would do something like this
	chain = new node; chain -> data = d; */
	/*if list is empty then the newly craeted node is placed at the begining, if not place it at th eend*/
		chain = new node(d);
		if (head == NULL) { /*if list is empty*/
			head = chain;
			tail = chain;
			chain = NULL;
		}
		else { /*if list is not empty add node to the end ot the chain */
			tail->next = chain;
			tail = tail->next;
		}

	}

	void push(int d) { /*insert node at the start*/
		chain = new node(d);
		chain->next = head;
		head = chain;
	}

	void pop() {
		chain = new node();
		chain = head; // make a temporary node = head
		head = head->next; // make head points to the next node in line
		delete chain; // delete the first node
	}

	int top() {
		return head->data;
	}

	int length(void)
	{
		int len = 0;
		chain = new node();
		chain = head;
		while (chain != NULL)
		{
			len++;
			chain = chain->next;
		}
		return len;
	}
	bool isEmpty()
	{
		
		if (this->length() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
    void display_all(){
            chain = new node; // try this chain = new node();
            chain = head;

            while(chain != NULL){
                cout<<chain->data<<" ";
                //cout<<chain->next<<"->";
                chain = chain->next;
            }
        }
};

bool balanced_pair(string expr)
{
	/*
	list pair_stack;
	int right_pair = 0, left_pair = 0;
	if((pair.length() % 2) != 0) // if input is not even number
	{
		return false;
	}
	else
	{
		for (int i = 0; i < pair.length(); i++)
		{

			if ((pair[i] == '(') || (pair[i] == '{') || (pair[i] == '[') || (pair[i] == '<'))
			{

				pair_stack.push(pair[i]);
				left_pair ++;
			}      
    	    else if (pair_stack.length() > 0)
			{

				if ((pair[i] == ')') || (pair[i] == '}') || (pair[i] == ']') || (pair[i] == '>'))
				{

					char temp = pair_stack.top();
    	    		pair_stack.pop();
					if ((pair[i] - temp == 2) || (pair[i] - temp == 1))
					{

						right_pair ++;
					}
				}
    	    }
		}
		if ((pair.length() != 0) && (left_pair > 0 && right_pair > 0) && (left_pair == right_pair))
		{
			return true;
		}
		else
		{
			return false;
		}

	}*/
	 list s; 
    char x; 
  
    // Traversing the Expression 
    for (int i=0; i<expr.length(); i++) 
    { 
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{' || expr[i] == '<') 
        { 
            // Push the element in the stack 
            s.push(expr[i]); 
            continue; 
        } 
  
        // IF current current character is not opening 
        // bracket, then it must be closing. So stack 
        // cannot be empty at this point. 
        if (s.isEmpty()) 
           return false; 
  
        switch (expr[i]) 
        { 
        case ')': 
  
            // Store the top element in a 
            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='['|| x == '<') 
                return false; 
            break; 
  
        case '}': 
  
            // Store the top element in b 
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[' || x == '<') 
                return false; 
            break; 
  
        case ']': 
  
            // Store the top element in c 
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{' || x == '<') 
                return false; 
            break; 
         
		case '>': 
  
            // Store the top element in c 
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{' || x == '[') 
                return false; 
            break; 
        }
	 
    } 
  
    // Check Empty Stack 
    return s.isEmpty(); 
	
}

int main()
{
	int num;
	cin>>num;
	if (num >= 0 && num <= 1000)
	{
		string string1;
		for(int i = 0; i < num; i++)
		{
			cin>>string1;
			if (balanced_pair(string1) == true)
			{
				cout<<"YES";
				cout<<endl;
			}
			else
			{
				cout << "NO";
				cout<<endl;
			}
		
		}
	}

}
