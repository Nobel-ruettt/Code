#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    if(n%4==0)
    {
        cout<<"0"<<endl;
    }
    else if(n%4==3)
    {

    }
    else if(n%4==2)
    {
        if(b<2*a)
        {
            cout<<b<<endl;
        }
        else
        {
            cout<<2*a<<endl;
        }
    }
    else if(n%4==1)
    {
        if(c<b+a&&c<3*a)
        {
            cout<<c<<endl;
        }
        else
        {
            if(b+a<3*a)
            {
                cout<<b+a<<endl;
            }
            else
            {
                cout<<3*a<<endl;
            }
        }
    }
    return 0;
}
