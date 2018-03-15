#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
map<int,int>dia;
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        dia[x]++;
    }
    long long max=0;
    map<int,int>::iterator it;
    for(it=dia.begin();it!=dia.end();it++)
    {
        ///cout<<it->second<<endl;
        if(it->second>max)
        {
            max=it->second;
        }
    }
    cout<<max;
    return 0;
}
