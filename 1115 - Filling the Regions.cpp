#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
string grid[55];
char ans_grid[55][55];
ll emne_grid[55][55];
map<char,ll>colour_visited;
map<ll,char>decifing_colour;
vector<char>colours;
ll max_grid[55][30];
void in_grid()
{
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<30;j++)
        {
            max_grid[i][j]=LLONG_MIN;
        }
    }
    colour_visited.clear();
    colours.clear();
    decifing_colour.clear();
    ll count1=1;
    for(ll i=0; i<n; i++)
    {
        cin>>grid[i];
        for(ll j=0; j<grid[i].size(); j++)
        {
            if(grid[i][j]!='.')
            {
                if(colour_visited[grid[i][j]]==0)
                {
                    colour_visited[grid[i][j]]=count1;
                    decifing_colour[count1]=grid[i][j];
                    count1++;
                    colours.push_back(grid[i][j]);
                }
            }
        }
    }
//    for(ll i=0;i<colours.size();i++)
//    {
//        cout<<colours[i]<<" "<<colour_visited[colours[i]]<<endl;
//    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(grid[i][j]!='.')
            {
                if(max_grid[i][colour_visited[grid[i][j]]]<j)
                {
                    max_grid[i][colour_visited[grid[i][j]]]=j;
                }
            }
        }
    }
//    for(ll i=0;i<n;i++)
//    {
//        cout<<"row "<<i<<endl;
//        for(ll j=1;j<=26;j++)
//        {
//            if(max_grid[i][j]!=LLONG_MIN)
//            {
//                printf("%c %lld\n",decifing_colour[j],max_grid[i][j]);
//            }
//        }
//        cout<<endl;
//    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            ans_grid[i][j]='.';
        }
    }
}
deque<pair<ll,ll> >bfs_deq;
void bfs(char now_colour)
{
    while(!bfs_deq.empty())
    {
        ll source_row=bfs_deq.front().first;
        ll source_column=bfs_deq.front().second;
        bfs_deq.pop_front();
        if(source_row+1<n)
        {
            if(grid[source_row+1][source_column]!=now_colour)
            {
                if(emne_grid[source_row+1][source_column]==-1)
                {
                    emne_grid[source_row+1][source_column]=1;
                    bfs_deq.push_back(make_pair(source_row+1,source_column));
                }
            }
        }
        if(source_row-1>=0)
        {
            if(grid[source_row-1][source_column]!=now_colour)
            {
                if(emne_grid[source_row-1][source_column]==-1)
                {
                    emne_grid[source_row-1][source_column]=1;
                    bfs_deq.push_back(make_pair(source_row-1,source_column));
                }
            }
        }
        if(source_column+1<m)
        {
            if(grid[source_row][source_column+1]!=now_colour)
            {
                if(emne_grid[source_row][source_column+1]==-1)
                {
                    emne_grid[source_row][source_column+1]=1;
                    bfs_deq.push_back(make_pair(source_row,source_column+1));
                }
            }
        }
        if(source_column-1>=0)
        {
            if(grid[source_row][source_column-1]!=now_colour)
            {
                if(emne_grid[source_row][source_column-1]==-1)
                {
                    emne_grid[source_row][source_column-1]=1;
                    bfs_deq.push_back(make_pair(source_row,source_column-1));
                }
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(emne_grid[i][j]==-1)
            {
                if(ans_grid[i][j]=='.')
                {
                    ans_grid[i][j]=now_colour;
                }
                else
                {
                    if(max_grid[i][colour_visited[ans_grid[i][j]]]<max_grid[i][colour_visited[now_colour]])
                    {
                        ans_grid[i][j]=now_colour;
                    }
                }
            }
        }
    }
//    for(ll i=0;i<n;i++)
//    {
//        for(ll j=0;j<m;j++)
//        {
//            cout<<ans_grid[i][j];
//        }
//        cout<<endl;
//    }
//    cout<<endl;
}
void colouring()
{
    for(ll i=0; i<colours.size(); i++)
    {
        char now_colour=colours[i];
//        cout<<now_colour<<endl;
        memset(emne_grid,-1,sizeof(emne_grid));
        bfs_deq.clear();
        for(ll j=0;j<n;j++)
        {
            if(grid[j][0]!=now_colour)
            {
                emne_grid[j][0]=1;
                bfs_deq.push_back(make_pair(j,0));
            }
            if(grid[j][m-1]!=now_colour)
            {
                emne_grid[j][m-1]=1;
                bfs_deq.push_back(make_pair(j,m-1));
            }
        }
        for(ll j=1; j<m-1; j++)
        {
            if(grid[0][j]!=now_colour)
            {
                emne_grid[0][j]=1;
                bfs_deq.push_back(make_pair(0,j));
            }
            if(grid[n-1][j]!=now_colour)
            {
                emne_grid[n-1][j]=1;
                bfs_deq.push_back(make_pair(n-1,j));
            }
        }
//        for(ll k=0; k<n; k++)
//        {
//            for(ll l=0; l<m; l++)
//            {
//                cout<<emne_grid[k][l];
//            }
//            cout<<endl;
//        }
        bfs(now_colour);
        ///cout<<endl<<endl;
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld%lld",&n,&m);
        in_grid();
        colouring();
        printf("Case %lld:\n",cas);
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                cout<<ans_grid[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
