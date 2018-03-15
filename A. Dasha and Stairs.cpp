#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int a,b;
    scanf("%lld%lld",&a,&b);
    if(fabs(a-b)<=1 && a+b>0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
