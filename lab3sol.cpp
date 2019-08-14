#include <iostream> 
#include <stack> 
using namespace std; 
int main()
{
stack <char> s;
string p;
int k;
cin>>k;
for(int j=0;j<k;j++)
{
cin>>p;
int i,count=0,slen=p.length();
for(i=0;i<slen;i++)
 {
  if(p[i]=='(')
    {s.push('(');
    }
  if(p[i]=='{')
    {s.push('{');
    }
  if(p[i]=='[')
    {s.push('[');
    }
  if(p[i]=='<')
    {s.push('<');
    }  
  if(p[i]=='|'&&count%2==0)
{s.push('|');
count++;
}
 else if(p[i]=='|'&&count%2==1)
    { if(s.empty()== 1)
       { cout<<"NO"<<endl;
          break;
        }
      else if(s.top()=='|')
         {s.pop();
          count++;
          }
      else
         {cout<<"NO"<<endl;
          break;
         }
    }
  if(p[i]==')')
    { if(s.empty()== 1)
       { cout<<"NO"<<endl;
          break;
        }
      else if(s.top()=='(')
         {s.pop();
          }
             else
         {cout<<"NO"<<endl;
          break;
         }
    }
   if(p[i]=='}')
    { if(s.empty()== 1)
       { cout<<"NO"<<endl;
          break;
        }
      else if(s.top()=='{')
         {s.pop();
          }
      else
         {cout<<"NO"<<endl;
          break;
         }
    }
   if(p[i]==']')
    { if(s.empty()== 1)
       { cout<<"NO"<<endl;
          break;
        }
      else if(s.top()=='[')
         {s.pop();
          }
      else
         {cout<<"NO"<<endl;
          break;
         }
    }
   if(p[i]=='>')
    { if(s.empty()== 1)
       { cout<<"NO"<<endl;
          break;
        }
      else if(s.top()=='<')
         {s.pop();
          }
      else
         {cout<<"NO"<<endl;
          break;
         }
    }
 }

if (s.empty()==1&&i==slen)
{
  cout<<"YES"<<endl;
}
else if (s.empty()==0&&i==slen)
{cout<<"NO"<<endl;
}
}
return 0;
}
