#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int main()
{
    ios::sync_with_stdio(false);
    while(getline(cin,s))
    {
        if(s=="END")
        {
            break;
        }
        if(s=="1")
        {
            cout<<"1"<<endl;
            continue;
        }
        ll length=s.size();
        ll length2;
        ll sum=0;
        sum++;
        while(length!=1)
        {
            length2=(long long)(log10(length)+0.000000001);
            length2++;
            length=length2;
            sum++;
        }
        sum++;
        cout<<sum<<endl;
    }
    return 0;
}
