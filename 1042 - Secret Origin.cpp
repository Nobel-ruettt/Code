#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<limits>
#include<climits>
#include<cmath>
#include<functional>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<typeinfo>

using namespace std;

typedef long long int ll;
typedef short int i16;
typedef unsigned long long int u64;
typedef unsigned int u32;
typedef unsigned short int u16;
typedef unsigned char u8;

int n;

string s;

void input()
{
    s.clear();
    scanf("%d", &n);
}

void solve()
{
    while(n)
    {
        s+=((n%2)+'0');
        n>>=1;
    }
    cout<<s<<'\n';
    s+='0';
    cout<<s<<'\n';
    int i,j,ones=0;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='1')
        {
            ones++;
        }
        if(s[i]=='1' && s[i+1]=='0')
        {
            ones--;
            swap(s[i],s[i+1]);
            for(j=0; j<i && ones; j++)
            {
                ones--;
                s[j]='1';
            }
            break;
        }
        else
        {
            s[i]='0';
        }
        cout<<s<<endl;
    }
    cout<<s<<endl;
    int ans=0,curr=1;
    for(i=0; i<s.size(); i++)
    {
        ans+=curr*(s[i]-'0');
        curr<<=1;
    }
    printf("%d\n", ans);
}

int main()
{
    int i,t;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        input();
        printf("Case %d: ", i);
        solve();
    }
    return 0;
}
