/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
string getString(char x) 
{ 
    string s(1, x); 
  
    return s;    
} 
/*int stoi(string s)
{
	int l=s.length();
	int b=0;
	for(int p=0;p<l;p++)
	{
		int w=s[p]-48;
		b=10*b+w;
	}
		return b;
}*/
void display(vector<string> &v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n" << endl;
}
int prec(string c) 
{ 
    if(c == "^") 
    return 3; 
    else if(c == "*" || c == "/") 
    return 2; 
    else if(c == "+" || c == "-") 
    return 1; 
    else
    return -1; 
} 
vector<string>  infixToPostfix(vector<string> s) 
{ 
    stack < string > st; 
    st.push("N"); 
    int l = s.size(); 
    vector<string> ns; 
    for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if(s[i]!="+"&&s[i]!="-"&&s[i]!="*"&&s[i]!="/"&&s[i]!="^"&&s[i]!="("&&s[i]!=")") 
        ns.push_back(s[i]); 
  
        // If the scanned character is an (, push it to the stack. 
        else if(s[i] == "(" )
          
        st.push("("); 
          
        // If the scanned character is an ), pop and to output string from the stack 
        // until an ( is encountered. 
        else if(s[i] == ")") 
        { 
            while(st.top() != "N" && st.top() != "(") 
            { 
                string c = st.top(); 
                st.pop(); 
               ns.push_back(c); 
            } 
            if(st.top() == "(") 
            { 
                string c = st.top(); 
                st.pop(); 
            } 
        } 
          
        //If an operator is scanned 
        else{ 
            while(st.top() != "N" && prec(s[i]) <= prec(st.top())) 
            { 
                string c = st.top(); 
                st.pop(); 
                ns.push_back(c); 
            } 
            st.push(s[i]); 
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(st.top() != "N") 
    { 
        string c = st.top(); 
        st.pop(); 
        ns.push_back(c); 
    } 
      
    return ns;
  
} 
struct node
{
	string sym;
	struct node * rchild;
	struct node * lchild;
};
node* getNode() 
{ 
    // allocating space 
    node* newNode = new node(); 
  
    // inserting the required data
    newNode->sym=" ";
    newNode->rchild = NULL; 
    newNode->lchild = NULL; 
    return newNode; 
} 
struct node* treebuild(vector <string> s)
{
	stack <struct node *> st;
    int l = s.size(); 
struct node * temp=getNode();
struct node * t1, * t2;
    
    for(int i = 0; i < l; i++) 	
    {
    	if(s[i]!="+"&&s[i]!="-"&&s[i]!="*"&&s[i]!="/"&&s[i]!="^") 
                {
        	struct node * temp=getNode();
        	temp->sym=s[i];
        	temp->lchild=NULL;
        	temp->rchild=NULL;
        	st.push(temp);
        	
		 } 
		 else 
		 {      
		 	temp->sym=s[i];
		 	t1=st.top();
			 temp->rchild = t1;
			
			 t2=st.top();
		 	temp->lchild = t2;
		 	st.push(temp);
		 }
    }
         temp = st.top();
    st.pop();
	return temp;
}
int evaluation(struct node *temp)
{
	if(temp->lchild==NULL&&temp->rchild==NULL)
	{  string s1=temp->sym;
	   int j =stoi(s1);
		return j;	
	}
	    struct node * ltemp;
	    ltemp=temp->lchild;
	    struct node * rtemp;
	    rtemp=temp->rchild;
		int l_val=evaluation(ltemp);
		int r_val=evaluation(rtemp);
	if(temp->sym == "+")
 {    
 	return  l_val + r_val;
 }
 	else if(temp->sym == "-")
 {
 	return l_val - r_val;
 }
	else if(temp->sym == "*")
 {
 	return  l_val * r_val;
 }
 else if(temp->sym == "/")
 {
 	return  l_val / r_val;
 }
 
}
  
int main()
{
    vector<string> s;
    char p,c;
    cin>>p;
    s.push_back(getString(p));
    cin>>c;
    while(c!='k')
    {
    	if(c!='+'&&c!='-'&&c!='*'&&c!='/'&&c!='('&&c!=')')
    	{
    		if(p=='+'||p=='-'||p=='*'||p=='/'||p=='('||p==')')
    		{
    			s.push_back(getString(c));
    			p=c;
    			cin>>c;
			}
			else
			{
				s.back()=s.back()+getString(c);
				p=c;
				cin>>c;
				
			}
    		
		}
		else
		{
			s.push_back(getString(c));
    			p=c;
    			cin>>c;
			
		}
    	
	}
	display(s);
	vector<string> ns=infixToPostfix(s);
	display(ns);
	struct node *tem=NULL;
	tem=treebuild(ns);
	int h=evaluation(tem);
	cout<<h;
    return 0;
}
