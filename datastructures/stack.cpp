#include <bits/stdc++.h>
using namespace std;

struct node{
	int x;
	struct node* next;
};

void Push(int a,struct node** headptr){
	if(*headptr == NULL){
		*headptr = new node();
		(*headptr)->x = a;
		(*headptr)->next = NULL;
	}
	else{
		node* tmp = new node();
		tmp->x =a;
		tmp->next = NULL;
		node* tmp1 = *headptr;
		while(tmp1->next!=NULL)
			tmp1 = tmp1->next;
		tmp1->next = tmp;
	}

}

void Pop(struct node** headptr)
{
	node* tmp1 = *headptr;
	node* tmp2 = NULL;
	while(tmp1!=NULL &&tmp1->next!=NULL){
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	if(tmp1==NULL)
		cout<<"Stack is empty";
	else{
		cout<<tmp1->x<<" is popped\n";
		if(tmp2==NULL){
			free(tmp1);
			*headptr = NULL;
		}
		else
		{
			tmp2->next = NULL;
			free(tmp1);
		}
	}
}

void peak(node** headptr)
{
	node* tmp = *headptr;
	while (tmp!=NULL &&tmp->next!=NULL)
	{
		tmp = tmp->next;
	}
	if(tmp==NULL)
	cout<<"Stack is empty";
	else
	cout<<tmp->x<<"\n";
}

void size(node ** headptr)
{
	node* tmp = *headptr;
	int len=0;
	while (tmp!=NULL)
	{
		tmp = tmp->next;
		i++;
	}
	cout<<len<<"\n";
}

int main()
{
	node* start = NULL;
	int a=0;
		while(a!=5){
			cin>>a;
			if(a==1)
			{
				int x;
				cin>>x;
				Push(x,&start);
			}
			if(a==2)
			{
				Pop(&start);
			}
			if(a==3)
			{
				peak(&start);
			}
			if(a==4)
			{
				size(&start);
			}
		}
}
