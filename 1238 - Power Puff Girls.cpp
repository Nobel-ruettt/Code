#include <bits/stdc++.h>
using namespace std;
#define ll long long
string grid[25];
ll copy_grid_b[25][25];
ll copy_grid_c[25][25];
ll copy_grid_a[25][25];
ll tes,row,column,des_row,des_column;
deque<pair<ll,ll> >q_a;
deque<pair<ll,ll> >q_b;
deque<pair<ll,ll> >q_c;
void cle()
{
    for(ll i=0;i<=row;i++)
    {
        grid[i].clear();
        for(ll j=0;j<=column;j++)
        {
            copy_grid_a[i][j]=-1;
            copy_grid_b[i][j]=-1;
            copy_grid_c[i][j]=-1;
        }
    }
    q_a.clear();
    q_b.clear();
    q_c.clear();
}
void in_grid()
{
    for(ll i=0;i<row;i++)
    {
        cin>>grid[i];
        for(ll j=0;j<column;j++)
        {
            if(grid[i][j]=='a')
            {
                copy_grid_a[i][j]=0;
                q_a.push_back(make_pair(i,j));
            }
            if(grid[i][j]=='b')
            {
                copy_grid_b[i][j]=0;
                q_b.push_back(make_pair(i,j));
            }
            if(grid[i][j]=='c')
            {
                copy_grid_c[i][j]=0;
                q_c.push_back(make_pair(i,j));
            }
            if(grid[i][j]=='#')
            {
                copy_grid_a[i][j]=-9;
                copy_grid_c[i][j]=-9;
                copy_grid_b[i][j]=-9;
            }
            if(grid[i][j]=='m')
            {
                copy_grid_a[i][j]=-9;
                copy_grid_c[i][j]=-9;
                copy_grid_b[i][j]=-9;
            }
            if(grid[i][j]=='h')
            {
                des_row=i;
                des_column=j;
            }
        }
    }
}
void bfs_a()
{
    while(!q_a.empty())
    {
        ll source_row=q_a.front().first;
        ll source_column=q_a.front().second;
        q_a.pop_front();
        if(source_row+1<row&&copy_grid_a[source_row+1][source_column]==-1)
        {
            copy_grid_a[source_row+1][source_column]=copy_grid_a[source_row][source_column]+1;
            q_a.push_back(make_pair(source_row+1,source_column));
        }
        if(source_row-1>=0&&copy_grid_a[source_row-1][source_column]==-1)
        {
            copy_grid_a[source_row-1][source_column]=copy_grid_a[source_row][source_column]+1;
            q_a.push_back(make_pair(source_row-1,source_column));
        }
        if(source_column+1<column&&copy_grid_a[source_row][source_column+1]==-1)
        {
            copy_grid_a[source_row][source_column+1]=copy_grid_a[source_row][source_column]+1;
            q_a.push_back(make_pair(source_row,source_column+1));
        }
        if(source_column-1>=0&&copy_grid_a[source_row][source_column-1]==-1)
        {
            copy_grid_a[source_row][source_column-1]=copy_grid_a[source_row][source_column]+1;
            q_a.push_back(make_pair(source_row,source_column-1));
        }
    }
//    for(ll i=0;i<row;i++)
//    {
//        for(ll j=0;j<column;j++)
//        {
//            cout<<copy_grid_a[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
void bfs_b()
{
    while(!q_b.empty())
    {
        ll source_row=q_b.front().first;
        ll source_column=q_b.front().second;
        q_b.pop_front();
        if(source_row+1<row&&copy_grid_b[source_row+1][source_column]==-1)
        {
            copy_grid_b[source_row+1][source_column]=copy_grid_b[source_row][source_column]+1;
            q_b.push_back(make_pair(source_row+1,source_column));
        }
        if(source_row-1>=0&&copy_grid_b[source_row-1][source_column]==-1)
        {
            copy_grid_b[source_row-1][source_column]=copy_grid_b[source_row][source_column]+1;
            q_b.push_back(make_pair(source_row-1,source_column));
        }
        if(source_column+1<column&&copy_grid_b[source_row][source_column+1]==-1)
        {
            copy_grid_b[source_row][source_column+1]=copy_grid_b[source_row][source_column]+1;
            q_b.push_back(make_pair(source_row,source_column+1));
        }
        if(source_column-1>=0&&copy_grid_b[source_row][source_column-1]==-1)
        {
            copy_grid_b[source_row][source_column-1]=copy_grid_b[source_row][source_column]+1;
            q_b.push_back(make_pair(source_row,source_column-1));
        }
    }
//    for(ll i=0;i<row;i++)
//    {
//        for(ll j=0;j<column;j++)
//        {
//            cout<<copy_grid_b[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
void bfs_c()
{
    while(!q_c.empty())
    {
        ll source_row=q_c.front().first;
        ll source_column=q_c.front().second;
        q_c.pop_front();
        if(source_row+1<row&&copy_grid_c[source_row+1][source_column]==-1)
        {
            copy_grid_c[source_row+1][source_column]=copy_grid_c[source_row][source_column]+1;
            q_c.push_back(make_pair(source_row+1,source_column));
        }
        if(source_row-1>=0&&copy_grid_c[source_row-1][source_column]==-1)
        {
            copy_grid_c[source_row-1][source_column]=copy_grid_c[source_row][source_column]+1;
            q_c.push_back(make_pair(source_row-1,source_column));
        }
        if(source_column+1<column&&copy_grid_c[source_row][source_column+1]==-1)
        {
            copy_grid_c[source_row][source_column+1]=copy_grid_c[source_row][source_column]+1;
            q_c.push_back(make_pair(source_row,source_column+1));
        }
        if(source_column-1>=0&&copy_grid_c[source_row][source_column-1]==-1)
        {
            copy_grid_c[source_row][source_column-1]=copy_grid_c[source_row][source_column]+1;
            q_c.push_back(make_pair(source_row,source_column-1));
        }
    }
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld%lld",&row,&column);
        cle();
        in_grid();
        bfs_a();
        bfs_b();
        bfs_c();
        ll maxi=0;
        if(copy_grid_a[des_row][des_column]>maxi)
        {
            maxi=copy_grid_a[des_row][des_column];
        }
        if(copy_grid_b[des_row][des_column]>maxi)
        {
            maxi=copy_grid_b[des_row][des_column];
        }
        if(copy_grid_c[des_row][des_column]>maxi)
        {
            maxi=copy_grid_c[des_row][des_column];
        }
        printf("Case %lld: %lld\n",i,maxi);
    }
    return 0;
}
