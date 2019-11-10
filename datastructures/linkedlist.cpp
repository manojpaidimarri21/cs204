#include<iostream>
#include<math.h>
using namespace std;
struct node
{
float x;
float y;
node *next;
};
class list
{
private:
node *head; 
public:
list() 
{
head=NULL;

}
void AddFirst(float x0,float y0)
{
node *temp=new node;
temp->x=x0;
temp->y=y0;
if (head!=NULL){temp->next=head;} else{temp->next=NULL;}
head=temp;
}

void display()
{
node *temp=new node;
if(head!=NULL)
{
  temp=head;
  while(temp!=NULL)
  {
  cout<<"("<<temp->x<<","<<temp->y<<")";
  temp=temp->next;
  }
  cout<<endl;
}
else{cout<<"Empty"<<endl;}
}


void DelFirst()
{
if(head!=NULL)
{
node *temp=new node;
temp=head;
head=head->next;
delete temp;
}
}

void Del(float x0,float y0)
{
if(head->x==x0&&head->y==y0){DelFirst();cout<<"0"<<endl;return;}
node* temp;
temp=head;
if(head==NULL){return ;}
else
{
node* curr=new node;
node* prev=new node;
curr=head;
while(1){
if(curr->x==x0&&curr->y==y0){break;} //found
prev=curr;
curr=curr->next;
if(curr==NULL){cout<<"-1"<<endl;return ;} //not found
         }

prev->next=curr->next;
delete curr;
cout<<"0"<<endl;

}

}

long long int Length()
{
long long int l=0;
node* tmp=head;
while(tmp!=NULL)
{
l++;
tmp=tmp->next;
}
cout<<l<<endl;
return 0;
}

void Search(float x0,float y0)
{
node* temp=head;
while(temp!=NULL)
{
if((temp->x==x0)&&(temp->y==y0))
{cout<<"True"<<endl;return;}
temp=temp->next;
}

{cout<<"False"<<endl;}
}


};



int main(){

list a;


long long int T;
cin>>T;
while(T>0)
{
int x; cin>>x;
switch(x)
{case(1): float p,q; cin>>p>>q;
 a.AddFirst(p,q);
 break;
case(2): a.DelFirst();
break;
case(3): float n,v;
cin>>n>>v;
a.Del(n,v);
break;
case(4):float c,m;cin>>c>>m;
a.Search(c,m);
break;
case(5):a.Length();
break;
case(6):a.display();
break;

}

T--;
}


return 0;
}


/*
input:
3
1 1 0
1 2 1
6
output:
(2,1)(1,0)
*/
