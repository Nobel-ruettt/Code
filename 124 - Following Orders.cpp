#include <bits/stdc++.h>
using namespace std;
vector<char>nodes;
vector<char>ad;
map<char,int>indegree;
map<char, vector<char> >node;
vector<char>ans;
void solve()
{
    if(ans.size()==nodes.size())
    {
        printf("%c",ans[0]);
        for(int i=1;i<ans.size();i++)
        {
            printf("%c",ans[i]);
        }
        printf("\n");
        return ;
    }
    for(int i=0;i<nodes.size();i++)
    {
        if(indegree[nodes[i]]==0)
        {
            indegree[nodes[i]]=-1;
            for(int k=0;k<node[nodes[i]].size();k++)
            {
                indegree[node[nodes[i]][k]]--;
            }
            ans.push_back(nodes[i]);
            solve();
            ans.pop_back();
            indegree[nodes[i]]=0;
            for(int k=0;k<node[nodes[i]].size();k++)
            {
                indegree[node[nodes[i]][k]]++;
            }
        }
    }
}
int main()
{
    string s;
    while(getline(cin,s))
    {
         nodes.clear();
         for(int i=0;i<s.size();i++)
         {
             if(s[i]>='a'&&s[i]<='z')
             {
                 nodes.push_back(s[i]);
                 indegree[s[i]]=0;
             }
         }
         sort(nodes.begin(),nodes.end());
         s.clear();
         getline(cin,s);
         ad.clear();
         for(int i=0;i<s.size();i++)
         {
             if(s[i]>='a'&&s[i]<='z')
             {
                 ad.push_back(s[i]);
             }
         }
         node.clear();
         for(int i=0;i<ad.size();i+=2)
         {
             node[ad[i]].push_back(ad[i+1]);
             indegree[ad[i+1]]++;
         }
         solve();
    }
    return 0;
}
