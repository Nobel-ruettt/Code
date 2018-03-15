#include <bits/stdc++.h>
using namespace std;
map<string,int>indegree;
map<string,vector<string> >node;
vector<string>seq;
vector<string>real_seq;
vector<string>nodess;
void clearr()
{
    indegree.clear();
    node.clear();
    seq.clear();
    real_seq.clear();
    nodess.clear();
}
int main()
{
    int n,count1=1,m;
    string nodes,node1,node2,source,adj;
    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++)
        {
            cin>>nodes;
            nodess.push_back(nodes);
            indegree[nodes]=0;
        }
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            cin>>node1>>node2;
            node[node1].push_back(node2);
            indegree[node2]++;
        }
        while(1)
        {
            for(int i=0; i<nodess.size(); i++)
            {
                if(indegree[nodess[i]]==0)
                {
                    seq.push_back(nodess[i]);
                    indegree[nodess[i]]=-1;
                }
            }
            if(seq.size()!=0)
            {
                for(int i=0; i<seq.size(); i++)
                {
                    real_seq.push_back(seq[i]);
                    source=seq[i];
                    for(int i=0; i<node[source].size(); i++)
                    {
                        adj=node[source][i];
                        indegree[adj]--;
                    }
                }
            }
            else if(seq.size()==0)
            {
                break;
            }
            seq.clear();
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ",count1);
        cout<<real_seq[0];
        for(int i=1;i<real_seq.size();i++)
        {
            cout<<" "<<real_seq[i];
        }
        count1++;
        cout<<endl;
        cout<<endl;
        clearr();
    }
    return 0;
}
