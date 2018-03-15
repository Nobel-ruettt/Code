#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct point
{
	ll x;
	ll y;
	ll z;

	point(){};
	point(ll x, ll y, ll z){this->x = x; this->y = y; this->z = z;}
};
ll visited[30][30][30];
ll tes,constraint;
string source,des;
deque<point>que;
void in_constraint()
{
    string s1,s2,s3;
    for(ll i=1;i<=constraint;i++)
    {
        cin>>s1>>s2>>s3;
        for(ll j=0;j<s1.size();j++)
        {
            for(ll k=0;k<s2.size();k++)
            {
                for(ll l=0;l<s3.size();l++)
                {
                    visited[s1[j]-'a'][s2[k]-'a'][s3[l]-'a']=-2;
                }
            }
        }
    }
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        cin>>source;
        cin>>des;
        cin>>constraint;
        memset(visited,-1,sizeof(visited));
        in_constraint();
        if(visited[source[0]-'a'][source[1]-'a'][source[2]-'a']==-2)
        {
            printf("Case %lld: -1\n",i);
            continue;
        }
        que.clear();
        ll first,second,third;
        point main_source;
        ll flag=0;
        visited[source[0]-'a'][source[1]-'a'][source[2]-'a']=0;
        que.push_back(point(source[0]-'a',source[1]-'a',source[2]-'a'));
        while(!que.empty())
        {
            main_source=que.front();
            que.pop_front();
            first=main_source.x;
            second=main_source.y;
            third=main_source.z;
            if(des[0]-'a'==first&&des[1]-'a'==second&&des[2]-'a'==third)
            {
                flag=1;
                break;
            }
            if(first+1>25)
            {
                if(visited[(first+1)%26][second][third]==-1)
                {
                       visited[(first+1)%26][second][third]=visited[first][second][third]+1;
                       que.push_back(point(((first+1)%26),second,third));
                }
            }
            else
            {
                if(visited[first+1][second][third]==-1)
                {
                       visited[first+1][second][third]=visited[first][second][third]+1;
                       que.push_back(point(first,second,third));
                }
            }
            if(second+1>25)
            {
                if(visited[first][(second+1)%25][third]==-1)
                {
                       visited[first][(second+1)%25][third]=visited[first][second][third]+1;
                       que.push_back(point(first,((second+1)%25),third));
                }
            }
            else
            {
                if(visited[first][second+1][third]==-1)
                {
                       visited[first][second+1][third]=visited[first][second][third]+1;
                       que.push_back(point(first,second+1,third));
                }
            }
            if(third+1>25)
            {
                if(visited[first][second][(third+1)%25]==-1)
                {
                       visited[first][second][(third+1)%25]=visited[first][second][third]+1;
                       que.push_back(point(first,second,((third+1)%25)));
                }
            }
            else
            {
                if(visited[first][second][third+1]==-1)
                {
                       visited[first][second][third+1]=visited[first][second][third]+1;
                       que.push_back(point(first,second,third+1));
                }
            }
            if(third-1<0)
            {
                if(visited[first][second][third-1+26]==-1)
                {
                       visited[first][second][third-1+26]=visited[first][second][third]+1;
                       que.push_back(point(first,second,third-1+26));
                }
            }
            else
            {
                if(visited[first][second][third-1]==-1)
                {
                       visited[first][second][third-1]=visited[first][second][third]+1;
                       que.push_back(point(first,second,third-1));
                }
            }
            if(second-1<0)
            {
                if(visited[first][second-1+26][third]==-1)
                {
                       visited[first][second-1+26][third]=visited[first][second][third]+1;
                       que.push_back(point(first,second-1+26,third));
                }
            }
            else
            {
                if(visited[first][second-1][third]==-1)
                {
                       visited[first][second-1][third]=visited[first][second][third]+1;
                       que.push_back(point(first,second-1,third));
                }
            }
            if(first-1<0)
            {
                if(visited[first-1+26][second][third]==-1)
                {
                       visited[first-1+26][second][third]=visited[first][second][third]+1;
                       que.push_back(point(first-1+26,second,third));
                }
            }
            else
            {
                if(visited[first-1][second][third]==-1)
                {
                       visited[first-1][second][third]=visited[first][second][third]+1;
                       que.push_back(point(first-1,second,third));
                }
            }
        }
        if(flag) printf("Case %lld: %lld\n", i,visited[des[0]-'a'][des[1]-'a'][des[2]-'a']);
		else printf("Case %lld: -1\n", i, -1);
    }
    return 0;
}
