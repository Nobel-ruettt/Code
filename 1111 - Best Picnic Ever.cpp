#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tes,row,column;
string grid[210];
ll copy_grid_fire[210][210];
ll copy_grid_jane[210][210];
deque<pair<ll,ll> >fires;
deque<pair<ll,ll> >jane;
void cle()
{
    for(ll i=0;i<=row;i++)
    {
        grid[i].clear();
        for(ll j=0;j<=column;j++)
        {
            copy_grid_fire[i][j]=LLONG_MAX;
            copy_grid_jane[i][j]=LLONG_MAX;
        }
    }
    fires.clear();
    jane.clear();
}
void in_edge()
{
    for(ll i=0;i<row;i++)
    {
        cin>>grid[i];
        for(ll j=0;j<column;j++)
        {
            if(grid[i][j]=='J')
            {
                copy_grid_jane[i][j]=0;
                jane.push_back(make_pair(i,j));
            }
            if(grid[i][j]=='F')
            {
                copy_grid_fire[i][j]=0;
                fires.push_back(make_pair(i,j));
            }
            if(grid[i][j]=='#')
            {
                copy_grid_jane[i][j]=-9;
                copy_grid_fire[i][j]=-9;
            }
        }
    }
//    for(ll i=0;i<row;i++)
//    {
//        for(ll j=0;j<column;j++)
//        {
//            cout<<copy_grid_fire[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    for(ll i=0;i<row;i++)
//    {
//        for(ll j=0;j<column;j++)
//        {
//            cout<<copy_grid_jane[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
void bfs_of_jane()
{
    ll source_row,source_col;
    while(!jane.empty())
    {
        source_row=jane.front().first;
        source_col=jane.front().second;
        jane.pop_front();
        if(source_row+1<row)
        {
            if(copy_grid_jane[source_row+1][source_col]==LLONG_MAX)
            {
                copy_grid_jane[source_row+1][source_col]=copy_grid_jane[source_row][source_col]+1;
                jane.push_back(make_pair(source_row+1,source_col));
            }
        }
        if(source_row-1>=0)
        {
            if(copy_grid_jane[source_row-1][source_col]==LLONG_MAX)
            {
                copy_grid_jane[source_row-1][source_col]=copy_grid_jane[source_row][source_col]+1;
                jane.push_back(make_pair(source_row-1,source_col));
            }
        }
        if(source_col+1<column)
        {
            if(copy_grid_jane[source_row][source_col+1]==LLONG_MAX)
            {
                copy_grid_jane[source_row][source_col+1]=copy_grid_jane[source_row][source_col]+1;
                jane.push_back(make_pair(source_row,source_col+1));
            }
        }
        if(source_col-1>=0)
        {
            if(copy_grid_jane[source_row][source_col-1]==LLONG_MAX)
            {
                copy_grid_jane[source_row][source_col-1]=copy_grid_jane[source_row][source_col]+1;
                jane.push_back(make_pair(source_row,source_col-1));
            }
        }
    }
//    for(ll i=0;i<row;i++)
//    {
//        for(ll j=0;j<column;j++)
//        {
//            cout<<copy_grid_jane[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
void bfs_of_fire()
{
    ll source_row,source_col;
    while(!fires.empty())
    {
        source_row=fires.front().first;
        source_col=fires.front().second;
        fires.pop_front();
        if(source_row+1<row)
        {
            if(copy_grid_fire[source_row+1][source_col]>copy_grid_fire[source_row][source_col]+1)
            {
                copy_grid_fire[source_row+1][source_col]=copy_grid_fire[source_row][source_col]+1;
                fires.push_back(make_pair(source_row+1,source_col));
            }
        }
        if(source_row-1>=0)
        {
            if(copy_grid_fire[source_row-1][source_col]>copy_grid_fire[source_row][source_col]+1)
            {
                copy_grid_fire[source_row-1][source_col]=copy_grid_fire[source_row][source_col]+1;
                fires.push_back(make_pair(source_row-1,source_col));
            }
        }
        if(source_col+1<column)
        {
            if(copy_grid_fire[source_row][source_col+1]>copy_grid_fire[source_row][source_col]+1)
            {
                copy_grid_fire[source_row][source_col+1]=copy_grid_fire[source_row][source_col]+1;
                fires.push_back(make_pair(source_row,source_col+1));
            }
        }
        if(source_col-1>=0)
        {
            if(copy_grid_fire[source_row][source_col-1]>copy_grid_fire[source_row][source_col]+1)
            {
                copy_grid_fire[source_row][source_col-1]=copy_grid_fire[source_row][source_col]+1;
                fires.push_back(make_pair(source_row,source_col-1));
            }
        }
    }
//    for(ll i=0;i<row;i++)
//    {
//        for(ll j=0;j<column;j++)
//        {
//            cout<<copy_grid_fire[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
ll anss()
{
    ll minimum=LLONG_MAX;
    for(ll i=0;i<column;i++)
    {
        if(copy_grid_jane[0][i]<copy_grid_fire[0][i])
        {
            if(minimum>(copy_grid_jane[0][i]+1))
            {
                minimum=copy_grid_jane[0][i]+1;
            }
        }
    }
//    cout<<minimum<<endl;
    for(ll i=1;i<row;i++)
    {
        if(copy_grid_jane[i][0]<copy_grid_fire[i][0])
        {
            if(minimum>(copy_grid_jane[i][0]+1))
            {
                minimum=copy_grid_jane[i][0]+1;
            }
        }
    }
    for(ll i=1;i<row;i++)
    {
        if(copy_grid_jane[i][column-1]<copy_grid_fire[i][column-1])
        {
            if(minimum>(copy_grid_jane[i][column-1]+1))
            {
                minimum=copy_grid_jane[i][column-1]+1;
            }
        }
    }
    for(ll i=1;i<column-1;i++)
    {
        if(copy_grid_jane[row-1][i]<copy_grid_fire[row-1][i])
        {
            if(minimum>(copy_grid_jane[row-1][i]+1))
            {
                minimum=copy_grid_jane[row-1][i]+1;
            }
        }
    }
//    cout<<minimum<<endl;
    return minimum;
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld%lld",&row,&column);
        cle();
        in_edge();
        bfs_of_jane();
        bfs_of_fire();
        ll ans=anss();
        //cout<<ans<<endl;
        if(ans==LLONG_MAX)
        {
            printf("Case %lld: IMPOSSIBLE\n",i);
            continue;
        }
        else
        {
            printf("Case %lld: %lld\n",i,ans);
        }
    }
}
