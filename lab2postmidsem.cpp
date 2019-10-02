#include<bits/stdc++.h>
#include <stack> 
using namespace std;
struct point
{
  int x;
  int y;
};
//global variable p0
struct point p0;
int
crossproduct (struct point p1, struct point p2)
{
  return p1.x * p2.y - p2.x * p1.y;
}
float
dis(struct point p1,struct point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool
ispolaranglenotequal(struct point p1,struct point p2)
{
	struct point u, v;
  u.x = p2.x - p0.x;
  u.y = p2.y - p0.y;
  v.x = p1.x - p0.x;
  v.y = p1.y - p0.y;
  if(u.y*v.x-u.x*v.y==0)
  return false;
  else return true;
}
//compare polar and distance
bool
compare(struct point p1,struct point p2)
{
  struct point u, v;
  u.x = p2.x - p0.x;
  u.y = p2.y - p0.y;
  v.x = p1.x - p0.x;
  v.y = p1.y - p0.y;
  if(u.y*v.x-u.x*v.y>0)
  {
	return true;
  }
  else if(u.y*v.x-u.x*v.y<0) 
    return false;
  else
  {
  	if(dis(p2,p0)>dis(p1,p0))
  	{
  		return true;
	}
	else return false;
  }
}

//nonleftturn returns 1 if non left turn
int
nonleftturn (struct point g, struct point p1, struct point p2)
{
  struct point u, v;
  u.x = p2.x - g.x;
  u.y = p2.y - g.y;
  v.x = p1.x - g.x;
  v.y = p1.y - g.y;
  if (crossproduct (u, v) < 0)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}
//n is array size
//return bottom left most point
struct point
selectbottommost(struct point * arr,int n)
 {   struct point best;
     best.x=arr[0].x;
     best.y=arr[0].y;
	for(int i=1;i<n;i++)
	{
		if((arr[i]).y<(best).y)
		{   
		    best=arr[i];
		}
		else if ((arr[i]).y==(best).y)
		{
			if((arr[i]).x<(best).x)
			{
				best=arr[i];
			}
		}
	}
	return best;
}
void
swap(struct point* p,struct point *q)
{
	struct point u;
	u=*p;
	*p=*q;
	*q=u;
}
struct point
nexttotop(stack <struct point> s)
{
	struct point r=s.top();
	s.pop();
	struct point k=s.top();
	s.push(r);
	return k;
}
vector<struct point> stacktovector(stack <struct point> s) 
{   vector<struct point> v;
    while (!s.empty()) 
    {   
        v.push_back(s.top());
        s.pop(); 
    } 
    return v;
} 
int
main ()
{
//number of points
  int t;
  cin >> t;
  struct point q[t];
  for (int i = 0; i < t; i++)
    {
      cin >> q[i].x;
      cin >> q[i].y;
    }
    ::p0=selectbottommost(q,t);
    for(int i=0;i<t;i++)
    {
    	if((q[i].x==p0.x)&&(q[i].y==p0.y))
    	{
    		swap(q+i,q);
		}
	}
    sort(q+1,q+t,compare);
    vector<struct point> p;
    p.push_back(p0);
    for(int i=1;i<t-1;i++)
    {
    	if(ispolaranglenotequal(q[i],q[i+1]))
    	p.push_back(q[i]);
    }
	p.push_back(q[t-1]);
	stack <struct point> s;
	s.push(p[0]);
	s.push(p[1]);
	s.push(p[2]);
	int m=p.size();
	for(int i=3;i<m;i++)
	{
		while(nonleftturn(nexttotop(s),s.top(),p[i]))
		{
			s.pop();
		}
		s.push(p[i]);
	}
	vector<struct point> v=stacktovector(s);
	cout<<v.size()<<endl;
	int l=v.size();
	int pos=0;
	for(int i=0;i<l;i++)
    {
        if(v[i].x<v[pos].x) pos=i;
        else if(v[i].x==v[pos].x && v[i].y<v[pos].y) pos=i;
    }
    for(int i=pos;i<l;i++)
    {
        cout<<v[i].x<<" "<<v[i].y<<endl;
    }
    for(int i=0;i<pos;i++)
    {
        cout<<v[i].x<<" "<<v[i].y<<endl;
    }
    return 0; 
	
	
}
