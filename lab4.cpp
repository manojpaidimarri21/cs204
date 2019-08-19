#include<bits/stdc++.h>
using namespace std;


struct et 
{ 
    string value; 
    et* left, *right; 
}; 

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

string removeSpaces(string str) 
{ 
    int i = 0, j = 0; 
    while (str[i]) 
    { 
        if (str[i] != ' ') 
           str[j++] = str[i]; 
        i++; 
    } 
    str[j] = '\0'; 
    return str; 
} 
bool isOperator(string c) 
{ 
    if (c == "+" || c == "-" || 
            c == "*" || c == "/" || 
            c == "^") 
        return true; 
    return false; 
} 

et* newNode(string v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}; 
  

vector<string> infixToPostfix(vector<string> s) 
{ 
    std::stack<string> st; 
    st.push("N"); 
    int l = s.size(); 
    vector<string> ns; 
    for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if(s[i]!="(" && s[i]!=")" && s[i]!="+" && s[i]!="*" && s[i]!="-" && s[i]!="/" && s[i]!="") 
         ns.push_back(s[i]); 

  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == "(")   
        st.push("("); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(s[i] == ")") 
        { 
            while(st.top() != "N" && st.top() != "(") 
            { 
                string c = st.top(); 
                st.pop(); 

              if(c!="")ns.push_back(c);
               
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
                if(c!="")ns.push_back(c); 
                
            } 
            st.push(s[i]); 
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(st.top() != "N") 
    { 
                string c = st.top(); 
                st.pop(); 
              if(c!="") ns.push_back(c); 
    } 
      
    return ns;
  
} 

// Returns root of constructed tree for given 
// postfix expression 
et* constructTree(vector<string> postfix) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
  
    // Traverse through every character of 
    // input expression 
    for (int i=0; i<postfix.size(); i++) 
    { 
        // If operand, simply push into stack 
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else // operator 
        { 
            t = newNode(postfix[i]); 
  
            // Pop two top nodes 
            t1 = st.top(); // Store top 
            st.pop();      // Remove top 
            t2 = st.top(); 
            st.pop(); 
  
            //  make them children 
            t->right = t1; 
            t->left = t2; 
  
            // Add this subexpression to stack 
            st.push(t); 
        } 
    } 
  
    //  only element will be root of expression 
    // tree 
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 
int eval(et * root){
    if(root==NULL) return 0;
    if(root->left==NULL&&root->right==NULL){
        return stoi(root->value);
    }
    int l=eval(root->left);
    int r=eval(root->right);
    if(root->value=="+") return l+r;
    else if(root->value=="-") return l-r;
    else if(root->value=="*") return l*r;
    else if(root->value=="/") return l/r;
    else return pow(l,r);
}

int main()
{
    string s;
	cin>>s;
	vector<string> str;
	string temp="";
    
	for(int i=0; i<s.length();i++)
	{
        //string temp="";
		if(s[i]>=48 && s[i]<=57)
		{
          temp+=s[i];
		}
		else
		{
             str.push_back(temp);//to push the number formed 
            temp=""; temp+=s[i];  //tp push the operator make it a string first 
              str.push_back(temp);//then push
            temp="";
		}

	}
    
    str.push_back(temp);
    
     vector<string> postexp=infixToPostfix(str);
   /* for(int i=0; i<str.size();i++)
    cout<<str[i];
    cout<<endl;
    vector<string> postexp=infixToPostfix(str);
    for(int i=0; i<postexp.size();i++)
    cout<<postexp[i]<<" ";
    cout<<endl;*/

    struct et* root=constructTree(postexp);
    int ans = eval(root);
    cout<<ans<<endl;




	
}

