

#include <bits/stdc++.h>

using namespace std;

int
main ()
{
  string str1, str2,  p;
  cout << "enter two numbers" << endl;
  cin >> str1;
  cin >> str2;
  int j, len1 = str1.length ();
  int len2 = str2.length ();
  if (len1 < len2)
    {
	str1.swap(str2)
      len1 = str1.length ();
      len2 = str2.length ();
    }
    string str3="";
  int t, c = 0;
  for (j = len1 - 1; j >= len1 - len2; j--)
    {
      t = (str1[j] - '0') + (str2[j - len1 + len2] - '0') + c;
      if (t >= 10)
	{
	  t = t - 10;
	  c = 1;
	}
      else
	{
	  c = 0;
	}
      str3 = to_string(t) +str3;

    }
  for (j = len1 - len2 - 1; j >= 0; j--)
    {
      t = (str1[j] - '0') + c;
      if (t >= 10)
	{
	  t = t - 10;
	  c = 1;
	}
      else
	{
	  c = 0;
	}
     str3 = to_string(t) +str3;

    }
  if (c == 1)
    {
      str3 = to_string(1) +str3;
    }

    cout<<str3;

  return 0;
}
