#include<bits/stdc++.h>
#include<cmath>
using namespace std;
//declare a struct point data type
 struct point
{
int x;
int y;
};
float distance(struct point t)
{
   return sqrt(t.x*t.x+t.y*t.y);
}
  
void insertionsort(float * t,int s)
{ 
  float key;
  int i;
	for(int j=1;j<s;j++)
		{
			key=t[j];
			i=j-1;
			while(i>=0 && t[i]>key)
				{
					t[i+1]=t[i];
					i=i-1;
				}
			t[i+1]=key;
		}				
}
int partition(float *d,int p,int r,float q)
{
	int i,j;
	float t;
	i=p-1;
	for(j=p;j<r+1;j++)
	{
		if(d[j]<=q)
		{
			i=i+1;
			t=d[i];
			d[i]=d[j];
			d[j]=t;
		}
	}
	return i+1-p;
}
float blum(float * d,int p,int r,int w)
{
if(p==r)
{
 return d[p];
}
else
{
	//number of groups
	int g,j,i;
	g=(r-p+1)/5;
	for( i=1;i<=g;i++)
		{	
			j=i-1;
			j=j*5;
			insertionsort(d+p+j,5);
		
			
		}
	if((r-p+1-g*5)!=0)
	insertionsort(d+p+g*5 ,r-p+1-g*5);
	float y[g+2];
	for( i=1;i<=g;i++)
	{
		y[i]=d[p+5*(i-1)+2];	
	
	}
	if(r-p+1-g*5>0)
		y[g+1]=d[p+g*5+(r-p-g*5)/2];
	float q;
	if(r-p+1-g*5<=0)
	{
		 q=blum(y,1,g,(g+1)/2);
	}
	else {
		 q=blum(y,1,g+1 ,(g+2)/2);
	}
	int k=partition(d,p,r,q);
	if(k==w)
	 return q;
	else if(k>w)
	 return blum(d,p,p+k-1,w);
	else if(k<w)
	 return blum(d,p+k,r,w-k);  
}
}
int main()
{
//number of test cases
int tc;
cin>>tc;
for(int i=0;i<tc;i++)
	{
 		//number of points in each test case
		int k;
		cin>>k;
		struct point t[k];
		for(int l=0;l<k;l++)
		{
			cin>>t[l].x;
			cin>>t[l].y;
		}
	float d[k];
	for(int l=0;l<k;l++)
		{
			d[l]=distance(t[l]);
    	}
    	cout<<blum(d,0,k-1,(k+1)/2);
	}
return 0;
}  
