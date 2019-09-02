#include <bits/stdc++.h>
using namespace std;
struct node
{
//user id
int id;
//cumulative recharge amount
int cra=0;
};
struct node createnode(int p,int ra)
{

struct node *r;
r=new(node);
r->id=p;
r->cra=ra;
return *r;
}
int main()
{
//number of user
int nu;
//querytype
int qtype;
//recharge amount
int ra;
//recharge list
vector<node> rl;
//number of quries
int nq;
cin>>nq;
   while(nq--)
           {
		cin>>qtype;
		
		if(qtype==1)
			{       
				
				//present id
				int p;
				//present recharge amount
				cin>>p;	
				int ra;	
				cin>>ra;
				struct node temp=createnode(p,ra);
				auto i=rl.begin();
				for( i=rl.begin();i!=rl.end();i++)
					{
						if(i->id==p) break;
					}	
			 	if(i==rl.end())
					{
						struct node temp=createnode(p,ra);
			        		rl.push_back(temp);
						
					}
				else
					{
						i->cra=i->cra+ra ;
					}

														
			}
		else if(qtype==2)
			{   //maximum cumilative recharge
				int maxcra=0;
			//current max index
				int j;
				int i=0;
				if(rl.size()==0)
					cout<<"NO DATA AVAILABLE"<<endl;
				
				else
				{
					for( int i=0;i<rl.size();i++)
					{
						if(rl[i].cra>maxcra)
						{
							j=i;maxcra=rl[i].cra;
						}
					}
				cout<<	rl[j].id<<endl;
				}

			}
		
           }



}

