#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=2004;
int n;
int a[maxn];
int sum[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1; i<=n; i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=n-1; i>=1; i--)
        if(sum[i]<=a[n])
        {
            cout<<i+1<<endl;
            return 0;
        }
    cout<<"1"<<endl;
    return 0;
}
