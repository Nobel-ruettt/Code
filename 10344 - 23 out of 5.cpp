#include <bits/stdc++.h>
using namespace std;
int tuples[6];
bool possible;
bool searchs(int n,long t)
{
    if(n==5)
    {
        if(t==23)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return searchs(n+1,t+tuples[n])||searchs(n+1,t-tuples[n])||searchs(n+1,t*tuples[n]);
    }
}
int main()
{
    while(scanf("%d%d%d%d%d",&tuples[0],&tuples[1],&tuples[2],&tuples[3],&tuples[4]))
    {
        if(tuples[0]==0&&tuples[1]==0&&tuples[2]==0&&tuples[3]==0&&tuples[4]==0)
        {
            break;
        }
        sort(tuples,tuples+5);
        possible=false;
        do
        {
            if(searchs(1,tuples[0]))
            {
                possible=true;
                break;
            }
        }while(next_permutation(tuples,tuples+5));
        if(possible)
        {
            printf("Possible\n");
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}
