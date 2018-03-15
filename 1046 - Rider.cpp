#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tes,row,column;
string grid[15];
ll level[110][15][15];
struct nod
{
    ll cor_row;
    ll cor_col;
    ll rid;
    nod(){};
	nod(ll cor_row, ll cor_col, ll rid){this->cor_row = cor_row; this->cor_col=cor_col; this->rid = rid;}
};
vector<nod>cor_riders;
void cle()
{
    for(ll i=0;i<=row;i++)
    {
        grid[i].clear();
    }
    cor_riders.clear();
}
void in_grid()
{
    for(ll i=0;i<row;i++)
    {
        cin>>grid[i];
        for(ll j=0;j<column;j++)
        {
            if(grid[i][j]>='1' && grid[i][j]<='9')
            {
                cor_riders.push_back(nod(i,j,(grid[i][j]-'0')));
            }
        }
    }
//    for(ll i=0;i<cor_riders.size();i++)
//    {
//        cout<<cor_riders[i].cor_row<<" "<<cor_riders[i].cor_col<<" "<<cor_riders[i].rid<<endl;
//    }
}
void cle_level()
{
    for(ll i=0;i<=cor_riders.size();i++)
    {
        for(ll j=0;j<row;j++)
        {
            for(ll k=0;k<column;k++)
            {
                level[i][j][k]=-1;
            }
        }
    }
//    for(ll i=0;i<=cor_riders.size();i++)
//    {
//        for(ll j=0;j<row;j++)
//        {
//            for(ll k=0;k<column;k++)
//            {
//                cout<<level[i][j][k]<<" ";
//            }
//            cout<<endl<<endl;
//        }
//        cout<<endl<<endl<<endl;
//    }
}
void main_bfs(ll pos,nod main_source)
{
    ///cout<<pos<<" "<<main_source.cor_row<<" "<<main_source.cor_col<<" "<<main_source.rid<<endl;
//    for(ll i=0;i<row;i++)
//    {
//        for(ll j=0;j<column;j++)
//        {
//            cout<<level[pos][i][j]<<" ";
//        }
//        cout<<endl;
//    }
       ll main_source_node_power=main_source.rid;
       ll source_node_row;
       ll source_node_col;
       ll source_node_remain;
       nod source;
       deque<nod>que;
       level[pos][main_source.cor_row][main_source.cor_col]=0;
       que.push_back(nod(main_source.cor_row,main_source.cor_col,0));
       while(!que.empty())
       {
           source=que.front();
           que.pop_front();
           ///cout<<source.cor_row<<" "<<source.cor_col<<" "<<source.rid<<endl;
           source_node_row=source.cor_row;
           source_node_col=source.cor_col;
           source_node_remain=source.rid;
           if(source_node_remain==0)
           {
               if(source_node_row-1>=0&&source_node_col+2<column&&level[pos][source_node_row-1][source_node_col+2]==-1)
               {
                   level[pos][source_node_row-1][source_node_col+2]=level[pos][source_node_row][source_node_col]+1;
                   ///cout<<source_node_row-1<<"  "<<source_node_col+2<<" "<<main_source_node_power-1<<" "<<level[pos][source_node_row-1][source_node_col+2]<<endl;
                   que.push_back(nod(source_node_row-1,source_node_col+2,main_source_node_power-1));
               }
               if(source_node_row+1<row&&source_node_col+2<column&&level[pos][source_node_row+1][source_node_col+2]==-1)
               {
                   level[pos][source_node_row+1][source_node_col+2]=level[pos][source_node_row][source_node_col]+1;
                   ///cout<<source_node_row+1<<"  "<<source_node_col+2<<" "<<main_source_node_power-1<<" "<<level[pos][source_node_row+1][source_node_col+2]<<endl;
                   que.push_back(nod(source_node_row+1,source_node_col+2,main_source_node_power-1));
               }
               if(source_node_row-1>=0&&source_node_col-2>=0&&level[pos][source_node_row-1][source_node_col-2]==-1)
               {
                   level[pos][source_node_row-1][source_node_col-2]=level[pos][source_node_row][source_node_col]+1;
                   ///cout<<source_node_row-1<<"  "<<source_node_col-2<<" "<<main_source_node_power-1<<" "<<level[pos][source_node_row-1][source_node_col-2]<<endl;
                   que.push_back(nod(source_node_row-1,source_node_col-2,main_source_node_power-1));
               }
               if(source_node_row+1<row&&source_node_col-2>=0&&level[pos][source_node_row+1][source_node_col-2]==-1)
               {
                   level[pos][source_node_row+1][source_node_col-2]=level[pos][source_node_row][source_node_col]+1;
                   ///cout<<source_node_row+1<<"  "<<source_node_col-2<<" "<<main_source_node_power-1<<" "<<level[pos][source_node_row+1][source_node_col-2]<<endl;
                   que.push_back(nod(source_node_row+1,source_node_col-2,main_source_node_power-1));
               }
               if(source_node_row-2>=0&&source_node_col-1>=0&&level[pos][source_node_row-2][source_node_col-1]==-1)
               {
                   level[pos][source_node_row-2][source_node_col-1]=level[pos][source_node_row][source_node_col]+1;
                   ///cout<<source_node_row-2<<"  "<<source_node_col-1<<" "<<main_source_node_power-1<<" "<<level[pos][source_node_row-2][source_node_col-1]<<endl;
                   que.push_back(nod(source_node_row-2,source_node_col-1,main_source_node_power-1));
               }
               if(source_node_row-2>=0&&source_node_col+1<column&&level[pos][source_node_row-2][source_node_col+1]==-1)
               {
                   level[pos][source_node_row-2][source_node_col+1]=level[pos][source_node_row][source_node_col]+1;
                   ///cout<<source_node_row-2<<"  "<<source_node_col+1<<" "<<main_source_node_power-1<<" "<<level[pos][source_node_row-2][source_node_col+1]<<endl;
                   que.push_back(nod(source_node_row-2,source_node_col+1,main_source_node_power-1));
               }
               if(source_node_row+2<row&&source_node_col-1>=0&&level[pos][source_node_row+2][source_node_col-1]==-1)
               {
                   level[pos][source_node_row+2][source_node_col-1]=level[pos][source_node_row][source_node_col]+1;
                   ///cout<<source_node_row+2<<"  "<<source_node_col-1<<" "<<main_source_node_power-1<<" "<<level[pos][source_node_row+2][source_node_col-1]<<endl;
                   que.push_back(nod(source_node_row+2,source_node_col-1,main_source_node_power-1));
               }
               if(source_node_row+2<row&&source_node_col+1<column&&level[pos][source_node_row+2][source_node_col+1]==-1)
               {
                   level[pos][source_node_row+2][source_node_col+1]=level[pos][source_node_row][source_node_col]+1;
                   ///cout<<source_node_row+2<<"  "<<source_node_col+1<<" "<<main_source_node_power-1<<" "<<level[pos][source_node_row+2][source_node_col+1]<<endl;
                   que.push_back(nod(source_node_row+2,source_node_col+1,main_source_node_power-1));
               }
           }
           else if(source_node_remain>0)
           {
               if(source_node_row-1>=0&&source_node_col+2<column&&level[pos][source_node_row-1][source_node_col+2]==-1)
               {
                   level[pos][source_node_row-1][source_node_col+2]=level[pos][source_node_row][source_node_col];
                   ///cout<<source_node_row-1<<"  "<<source_node_col+2<<" "<<source_node_remain-1<<" "<<level[pos][source_node_row-1][source_node_col+2]<<endl;
                   que.push_back(nod(source_node_row-1,source_node_col+2,source_node_remain-1));
               }
               if(source_node_row+1<row&&source_node_col+2<column&&level[pos][source_node_row+1][source_node_col+2]==-1)
               {
                   level[pos][source_node_row+1][source_node_col+2]=level[pos][source_node_row][source_node_col];
                   ////cout<<source_node_row+1<<"  "<<source_node_col+2<<" "<<source_node_remain-1<<" "<<level[pos][source_node_row+1][source_node_col+2]<<endl;
                   que.push_back(nod(source_node_row+1,source_node_col+2,source_node_remain-1));
               }
               if(source_node_row-1>=0&&source_node_col-2>=0&&level[pos][source_node_row-1][source_node_col-2]==-1)
               {
                   level[pos][source_node_row-1][source_node_col-2]=level[pos][source_node_row][source_node_col];
                   ////cout<<source_node_row-1<<"  "<<source_node_col-2<<" "<<source_node_remain-1<<" "<<level[pos][source_node_row-1][source_node_col-2]<<endl;
                   que.push_back(nod(source_node_row-1,source_node_col-2,source_node_remain-1));
               }
               if(source_node_row+1<row&&source_node_col-2>=0&&level[pos][source_node_row+1][source_node_col-2]==-1)
               {
                   level[pos][source_node_row+1][source_node_col-2]=level[pos][source_node_row][source_node_col];
                   ///cout<<source_node_row+1<<"  "<<source_node_col-2<<" "<<source_node_remain-1<<" "<<level[pos][source_node_row+1][source_node_col-2]<<endl;
                   que.push_back(nod(source_node_row+1,source_node_col-2,source_node_remain-1));
               }
               if(source_node_row-2>=0&&source_node_col-1>=0&&level[pos][source_node_row-2][source_node_col-1]==-1)
               {
                   level[pos][source_node_row-2][source_node_col-1]=level[pos][source_node_row][source_node_col];
                   ///cout<<source_node_row-2<<"  "<<source_node_col-1<<" "<<source_node_remain-1<<" "<<level[pos][source_node_row-2][source_node_col-1]<<endl;
                   que.push_back(nod(source_node_row-2,source_node_col-1,source_node_remain-1));
               }
               if(source_node_row-2>=0&&source_node_col+1<column&&level[pos][source_node_row-2][source_node_col+1]==-1)
               {
                   level[pos][source_node_row-2][source_node_col+1]=level[pos][source_node_row][source_node_col];
                   ///cout<<source_node_row-2<<"  "<<source_node_col+1<<" "<<source_node_remain-1<<" "<<level[pos][source_node_row-2][source_node_col+1]<<endl;
                   que.push_back(nod(source_node_row-2,source_node_col+1,source_node_remain-1));
               }
               if(source_node_row+2<row&&source_node_col-1>=0&&level[pos][source_node_row+2][source_node_col-1]==-1)
               {
                   level[pos][source_node_row+2][source_node_col-1]=level[pos][source_node_row][source_node_col];
                   ////cout<<source_node_row+2<<"  "<<source_node_col-1<<" "<<source_node_remain-1<<" "<<level[pos][source_node_row+2][source_node_col-1]<<endl;
                   que.push_back(nod(source_node_row+2,source_node_col-1,source_node_remain-1));
               }
               if(source_node_row+2<row&&source_node_col+1<column&&level[pos][source_node_row+2][source_node_col+1]==-1)
               {
                   level[pos][source_node_row+2][source_node_col+1]=level[pos][source_node_row][source_node_col];
                   ///cout<<source_node_row+2<<"  "<<source_node_col+1<<" "<<source_node_remain-1<<" "<<level[pos][source_node_row+2][source_node_col+1]<<endl;
                   que.push_back(nod(source_node_row+2,source_node_col+1,source_node_remain-1));
               }
           }
       }
//       for(ll i=0;i<row;i<i++)
//       {
//           for(ll j=0;j<column;j++)
//           {
//               cout<<level[pos][i][j]<<" ";
//           }
//           cout<<endl;
//       }
//       cout<<endl<<endl;
}
ll bfs()
{
    ll rider_power;
    ll rider_row;
    ll rider_column;
    for(ll i=0;i<cor_riders.size();i++)
    {
        main_bfs(i,cor_riders[i]);
    }
    ll minimum=LLONG_MAX;
    ll sum;
    for(ll i=0;i<row;i++)
    {
        for(ll j=0;j<column;j++)
        {
            sum=0;
            for(ll k=0;k<cor_riders.size();k++)
            {
               if(level[k][i][j]!=-1)
               {
                   sum+=level[k][i][j];
               }
               else
               {
                   sum=LLONG_MAX;
                   break;
               }
            }
            if(sum<minimum)
            {
                minimum=sum;
            }
        }
    }
    return minimum;
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld%lld",&row,&column);
        cle();
        in_grid();
        cle_level();
        ll ans=bfs();
        if(ans>=LLONG_MAX)
        {
            printf("Case %lld: -1\n",i);
        }
        else
        {
            printf("Case %lld: %lld\n",i,ans);
        }
    }
    return 0;
}
