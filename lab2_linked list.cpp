

#include <bits/stdc++.h>

using namespace std;

struct node
{
  int x, y;
  struct node *ptr;
} *start;

class singly_linkedlist
{
public:
  singly_linkedlist ()
  {
    start = NULL;
  }
  void AddFirst (int x, int y);
  void DelFirst ();
  void Del (int x, int y);
  void find (int d);
  void search (int x, int y);
  void Length ();

};


void
singly_linkedlist::AddFirst (int x, int y)
{
  struct node *temp;
  temp = new (struct node);
  temp->x = x;
  temp->y = y;
  temp->ptr = start;
  start = temp;
}

void
singly_linkedlist::DelFirst ()
{
  if (start == NULL)
    {
      cout << "List is empty" << endl;
      return;
    }
  else
    {
      struct node *temp;
      temp = start;
      start = temp->ptr;
      free (temp);
    }

}

void
singly_linkedlist::Del (int x, int y)
{
  struct node *temp, *prev;
  temp = start, prev = NULL;
  if (temp == NULL)
    return;
  while (!(temp->x == x && temp->y == y))
    {
      prev = temp;
      temp = temp->ptr;
    }
  if (prev != NULL)
    {

      prev->ptr = temp->ptr;
      free (temp);
    }
  else
    DelFirst ();
}

void
singly_linkedlist::find (int d)
{
  struct node *temp;
  temp = start;
  while (temp!= NULL)
    {
      int t = (temp->x) * (temp->x) + (temp->y) * (temp->y);
      if (t <= d * d)
	{
	  cout << "(" << temp->x << "," << temp->y << ")";
	}
      temp = temp->ptr;
    }

}

void
singly_linkedlist::search (int x, int y)
{
  struct node *temp;
  temp = start;
  while (temp != NULL)
    {
      if (temp->x == x && temp->y == y)
	break;
      else
	temp = temp->ptr;
    }
  if (temp == NULL)
    cout << "False";
  else
    cout << "true";

}

void
singly_linkedlist::Length ()
{
  int j = 0;
  struct node *temp;
  temp = start;
  while (temp != NULL)
    {
      j++;
      temp = temp->ptr;
    }
  cout << j;
}

int
main ()
{
  singly_linkedlist sl;
  start = NULL;
  int x, y, d;
  int q;
  cin >> q;
  while (q <= 6 && q >= 1)
    {

      switch (q)
	{
	case 1:
	  cin >> x;
	  cin >> y;
	  sl.AddFirst (x, y);
	  break;
	case 2:
	  sl.DelFirst ();
	  break;
	case 3:
	  cin >> x;
	  cin >> y;
	  sl.Del (x, y);
	  break;
	case 4:
	  cin >> d;
	  sl.find (d);
	  break;
	case 5:
	  cin >> x;
	  cin >> y;
	  sl.search (x, y);
	  break;
	case 6:
	  sl.Length ();
	  break;

	}
      cin >> q;
    }


}
