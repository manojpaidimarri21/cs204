
#include <iostream>

using namespace std;

int main()
{
    string s1,s2,s3;
    cin>>s1;
    cin>>s2;
    int s1len=s1.length();
    int s2len=s2.length();
    int j,t;
    s3="";
    for(j=s1len-1;j>=s1len-s2len;j--)
    {
        if(s1[j]<s2[j-s1len+s2len])
        {
            s1[j-1]-=1;
            s1[j]+=10;
            t=(s1[j]-'0')-(s2[j-s1len+s2len]-'0');
            s3=to_string(t)+s3;
        }
        else
        { t=(s1[j]-'0')-(s2[j-s1len+s2len]-'0');
          s3=to_string(t)+  s3;
            
        }
    }
    for(j=s1len-s2len-1;j>=0;j--)
    {   if(s1[j]<s2[j-s1len+s2len])
        {
            s1[j-1]-=1;
            s1[j]+=10;
            t=(s1[j]-'0');
            s3=to_string(t)+s3;
        }
        else
        { t=(s1[j]-'0');
          s3=to_string(t)+  s3;
            
        }
        
    }
    cout<<s3;
    
    return 0;
}
