#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int tes,r,c,m,n,w,source_row,source_column,next1_row,next1_column,mara_row,mara_col;
int grid[110][110];
deque<pi>que;
void grid_clear()
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            grid[i][j]=1000000;
        }
    }
}
void mara()
{
    for(int i=0; i<w; i++)
    {
        scanf("%d%d",&mara_row,&mara_col);
        grid[mara_row][mara_col]=-1;
    }
}
void bfs()
{
    que.clear();
    pi source=make_pair(0,0);
    que.push_back(source);
    int count1;
    while(!que.empty())
    {
        count1=0;
        source=que.front();
        que.pop_front();
        source_row=source.first;
        source_column=source.second;
        printf("source [%d][%d] : \n",source_row,source_column);
        next1_row=source_row+m;
        next1_column=source_column+n;
        if(next1_row>=0 && next1_row<=(r-1)&&next1_column>=0&&next1_column<=(c-1) && grid[next1_row][next1_column]!=-1)
        {
            count1++;
            printf("[%d][%d]\n",next1_row,next1_column);
            if(grid[next1_row][next1_column]==1000000)
            {
                grid[next1_row][next1_column]=1;
                que.push_back(make_pair(next1_row,next1_column));
            }
        }
        next1_row=source_row+m;
        next1_column=source_column-n;
        if(next1_row>=0 && next1_row<=r-1&&next1_column>=0&&next1_column<=c-1&&grid[next1_row][next1_column]!=-1&&n!=0)
        {
            count1++;
            printf("[%d][%d]\n",next1_row,next1_column);
            if(grid[next1_row][next1_column]==1000000)
            {
                grid[next1_row][next1_column]=1;
                que.push_back(make_pair(next1_row,next1_column));
            }
        }
        next1_row=source_row-m;
        next1_column=source_column+n;
        if(next1_row>=0 && next1_row<=r-1&&next1_column>=0&&next1_column<=c-1&&grid[next1_row][next1_column]!=-1&&m!=0)
        {
            count1++;
            printf("[%d][%d]\n",next1_row,next1_column);
            if(grid[next1_row][next1_column]==1000000)
            {
                grid[next1_row][next1_column]=1;
                que.push_back(make_pair(next1_row,next1_column));
            }
        }
        next1_row=source_row-m;
        next1_column=source_column-n;
        if(next1_row>=0 && next1_row<=r-1&&next1_column>=0&&next1_column<=c-1&&grid[next1_row][next1_column]!=-1&&m!=0&&n!=0)
        {
            count1++;
            printf("[%d][%d]\n",next1_row,next1_column);
            if(grid[next1_row][next1_column]==1000000)
            {
                grid[next1_row][next1_column]=1;
                que.push_back(make_pair(next1_row,next1_column));
            }
        }
        if(m!=n)
        {
            next1_row=source_row+n;
            next1_column=source_column+m;
           if(next1_row>=0 && next1_row<=r-1&&next1_column>=0&&next1_column<=c-1&&grid[next1_row][next1_column]!=-1)
            {
                count1++;
                printf("[%d][%d]\n",next1_row,next1_column);
                if(grid[next1_row][next1_column]==1000000)
                {
                    grid[next1_row][next1_column]=1;
                    que.push_back(make_pair(next1_row,next1_column));
                }
            }
            next1_row=source_row+n;
            next1_column=source_column-m;
            if(next1_row>=0 && next1_row<=r-1&&next1_column>=0&&next1_column<=c-1&&grid[next1_row][next1_column]!=-1)
            {
                printf("[%d][%d]\n",next1_row,next1_column);
                count1++;
                if(grid[next1_row][next1_column]==1000000)
                {
                    grid[next1_row][next1_column]=1;
                    que.push_back(make_pair(next1_row,next1_column));
                }
            }
            next1_row=source_row-n;
            next1_column=source_column+m;
            if(next1_row>=0 && next1_row<=r-1&&next1_column>=0&&next1_column<=c-1&&grid[next1_row][next1_column]!=-1&&m!=0&&n!=0)
            {
                count1++;
                printf("[%d][%d]\n",next1_row,next1_column);
                if(grid[next1_row][next1_column]==1000000)
                {
                    grid[next1_row][next1_column]=1;
                    que.push_back(make_pair(next1_row,next1_column));
                }
            }
            next1_row=source_row-n;
            next1_column=source_column-m;
            if(next1_row>=0 && next1_row<=r-1&&next1_column>=0&&next1_column<=c-1&&grid[next1_row][next1_column]!=-1&&m!=0&&n!=0)
            {
                count1++;
                printf("[%d][%d]\n",next1_row,next1_column);
                if(grid[next1_row][next1_column]==1000000)
                {
                    grid[next1_row][next1_column]=1;
                    que.push_back(make_pair(next1_row,next1_column));
                }
            }
        }
        if(count1%2==0)
        {
            grid[source_row][source_column]=2;
        }
        else
        {
            grid[source_row][source_column]=3;
        }
    }
}
int main()
{
    scanf("%d",&tes);
    for(int i=1; i<=tes; i++)
    {
        scanf("%d%d%d%d",&r,&c,&m,&n);
        grid_clear();
        scanf("%d",&w);
        mara();
        bfs();
        int odd=0;
        int even=0;
        for(int k=0;k<r;k++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<grid[k][j]<<" ";
            }
            cout<<endl;
        }
        for(int k=0; k<r; k++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[k][j]==2)
                {
                    even++;
                }
                else if(grid[k][j]==3)
                {
                    odd++;
                }
            }
        }
        printf("Case %d: %d %d\n",i,even,odd);
    }
    return 0;
}
