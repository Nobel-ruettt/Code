#include<bits/stdc++.h>
using namespace std;
long long arr[100010];
map<long long ,long long>ase;
int main()
{
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    long long count1=0;
    for(long long i=0;i<n;i++)
    {
         long long node=arr[i]^m;
         if(ase.find(node)!=ase.end())
         {
             count1+=ase[node];
         }
         ase[arr[i]]++;
    }
    cout<<count1<<endl;
    return 0;
}
