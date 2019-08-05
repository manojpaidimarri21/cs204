#include <bits/stdc++.h>
using namespace std;
string
add (string str1, string str2)
{
  string p;
  int j, len1 = str1.length ();
  int len2 = str2.length ();
  if (len1 < len2)
    {
      str1.swap (str2);
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

  return str3;
}
string product_single_digit(string str1,char str2)
{   int i,t;
    int len1=str1.length();
    int str2_int=str2 -'0';
    string str3="";
    int carry=0;
    for(i=len1-1;i>=0;i--)
    {
        t=str1[i]-'0';
        t=t*str2_int+carry;
        carry=t/10;
        str3=to_string(t%10)+str3;
    }
    str3=to_string(carry)+str3;
    return str3;
}

int main()
{   int k;
cin>>k;
for(int m=0;m<k;m++)
{

	string str1,str2,str3,str4;
    cin>>str1;
    cin>>str2;
    int str2_len=str2.length();
    int j;
    str3="";
    for(j=str2_len-1;j>=0;j--)
    {
        str4=product_single_digit(str1,str2[j]);
        for(int k=2;k<=str2_len-j;k++)
        {
            str4=str4+"0";
        }
        str3=add(str3,str4);
    }
    cout<<str3;
 }   
    
    return 0;
}
