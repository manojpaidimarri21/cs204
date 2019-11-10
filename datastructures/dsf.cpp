#include <iostream> 
using namespace std; 
class DisjSet { 
	int *rank, *parent, n; 

public: 
	DisjSet(int n) 
	{ 
		rank = new int[n]; 
		parent = new int[n]; 
		this->n = n; 
		makeSet(); 
	} 
	void makeSet() 
	{ 
		for (int i = 0; i < n; i++) { 
			parent[i] = i; 
		} 
	} 
		int find(int x) 
	{ 
	
		if (parent[x] != x) { 

		
			parent[x] = find(parent[x]); 

		
		} 

		return parent[x]; 
	} 
	void Union(int x, int y) 
	{ 
	
		int xset = find(x); 
		int yset = find(y); 

	
		if (xset == yset) 
			return; 


		if (rank[xset] < rank[yset]) { 
			parent[xset] = yset; 
		} 
		else if (rank[xset] > rank[yset]) { 
			parent[yset] = xset; 
		} 

		else { 
			parent[yset] = xset; 
			rank[xset] = rank[xset] + 1; 
		} 
	} 
};
int main() 
{   int k,a,b;
     cin>>k;
	DisjSet obj(k);
	int q;//number of unions
	cin>>q;
	for(int i=0;i<q;i++)
	{ 
	    cin>>a;
	    cin>>b;
	    obj.Union(a,b);
	    
	}
	int p;//number of quireies
	cin>>p;
	for(int i=0;i<p;i++)
	{    
	    cin>>a;
	    cin>>b;
	    	if (obj.find(a) == obj.find(b)) 
		cout << "Yes\n"; 
			else
		cout << "No\n"; 
		
	    
	}
	

	return 0; 
} 
/*sample input
5
3
0 2
4 2
3 1
2
4 0
1 0
output:
*/
