#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,s,pos_row,pos_column,total;
    char maze[110][110];
    char dir;
    char ins[5*10005];
    while(scanf("%lld%lld%lld",&n,&m,&s))
    {
        total=0;
        if(n==0&&m==0&&s==0)
        {
            break;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",maze[i]);
            for(int j=0;j<m;j++)
            {
                if(maze[i][j]=='N' || maze[i][j]=='S' || maze[i][j]=='L' || maze[i][j]=='O')
                {
                       pos_row=i;
                       pos_column=j;
                       if(maze[i][j]=='N')
                       {
                            dir='U';
                       }
                       else if(maze[i][j]=='S')
                       {
                            dir='N';
                       }
                       else if(maze[i][j]=='L')
                       {
                            dir='D';
                       }
                       else if(maze[i][j]=='O')
                       {
                            dir='B';
                       }
                }
            }
        }
        ///printf("pos_row %lld pos_column %lld dir %c\n",pos_row,pos_column,dir);
        scanf("%s",ins);
        for(int i=0;i<s;i++)
        {
            if(ins[i]=='D')
            {
                 if(dir=='U')
                 {
                     dir='D';
                 }
                 else if(dir=='D')
                 {
                     dir='N';
                 }
                 else if(dir=='N')
                 {
                     dir='B';
                 }
                 else if(dir=='B')
                 {
                     dir='U';
                 }
            }
            else if(ins[i]=='E')
            {
                 if(dir=='U')
                 {
                     dir='B';
                 }
                 else if(dir=='D')
                 {
                     dir='U';
                 }
                 else if(dir=='N')
                 {
                     dir='D';
                 }
                 else if(dir=='B')
                 {
                     dir='N';
                 }
            }
            else if(ins[i]=='F')
            {
                if(dir=='U')
                {
                    if(pos_row==0|| maze[pos_row-1][pos_column]=='#')
                    {
                        pos_row=pos_row;
                        pos_column=pos_column;
                    }
                    else if(pos_row>0)
                    {
                        pos_row--;
                        pos_column=pos_column;
                        if(maze[pos_row][pos_column]=='*')
                        {
                            total++;
                            maze[pos_row][pos_column]='.';
                        }
                    }
                }
                else if(dir=='D')
                {
                    if(pos_column==m-1 || maze[pos_row][pos_column+1]=='#')
                    {
                        pos_row=pos_row;
                        pos_column=pos_column;
                    }
                    else if(pos_column<m-1)
                    {
                        pos_row=pos_row;
                        pos_column++;
                        if(maze[pos_row][pos_column]=='*')
                        {
                            total++;
                            maze[pos_row][pos_column]='.';
                        }
                    }
                }
                else if(dir=='B')
                {
                     if(pos_column==0 || maze[pos_row][pos_column-1]=='#')
                    {
                        pos_row=pos_row;
                        pos_column=pos_column;
                    }
                    else if(pos_column>0)
                    {
                        pos_row=pos_row;
                        pos_column--;
                        if(maze[pos_row][pos_column]=='*')
                        {
                            total++;
                            maze[pos_row][pos_column]='.';
                        }
                    }
                }
                else if(dir=='N')
                {
                 if(pos_row==n-1 || maze[pos_row+1][pos_column]=='#')
                    {
                        pos_row=pos_row;
                        pos_column=pos_column;
                    }
                    else if(pos_row<n-1)
                    {
                        pos_row++;
                        pos_column=pos_column;
                        if(maze[pos_row][pos_column]=='*')
                        {
                            total++;
                            maze[pos_row][pos_column]='.';
                        }
                    }
                }
             }
            }
            printf("%lld\n",total);
        }
        return 0;
}
