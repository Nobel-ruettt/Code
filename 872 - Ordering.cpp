#include <bits/stdc++.h>
using namespace std;
string s;
string order;
map<char,int>indegree;
map<char,int>indegree2;
vector<char>nodes;
map<char, vector<char> >node;
vector<char>ans;
void solve()
{
    if(ans.size()==nodes.size())
    {
        printf("%c",ans[0]);
        for(int i=1;i<ans.size();i++)
        {
            printf(" %c",ans[i]);
        }
        printf("\n");
        return ;
    }
    int falsee=0;
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
    int tes;
    char c;
    cin>>tes;
    for(int i=1;i<=tes;i++)
    {
        indegree.clear();
        nodes.clear();
        node.clear();
        ans.clear();
        indegree2.clear();
        scanf("%c",&c);
        cout<<endl;
        getline(cin,s);
        for(int j=0;j<s.size();j++)
        {
            if(s[j]!=' ')
            {
                nodes.push_back(s[j]);
                indegree[s[j]]=0;
            }
        }
        getline(cin,order);
        for(int j=0;j<order.size();j++)
        {
            if(order[j]=='<')
            {
                node[order[j-1]].push_back(order[j+1]);
                indegree[order[j+1]]++;
                indegree2[order[j+1]]++;
            }
        }

        solve();
    }
    return 0;
}
//*ACCEPTED/
