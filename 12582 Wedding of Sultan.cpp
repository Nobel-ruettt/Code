#include <bits/stdc++.h>
using namespace std;
vector<char>nodes_in_stack;
map<char,vector<char> >node_connectivity;
map<char,int>how_many_visited;
int main()
{
    int testcase;
    string total_trail;
    cin>>testcase;
    for(int k=1;k<=testcase;k++)
    {
        cin>>total_trail;
        how_many_visited.clear();
        nodes_in_stack.clear();
        node_connectivity.clear();
        nodes_in_stack.push_back(total_trail[0]);
        how_many_visited[total_trail[0]]++;
        for(int i=1;i<total_trail.size();i++)
        {
            if(how_many_visited[total_trail[i]]==0)
            {
//                cout<<"zeta pailam "<<total_trail[i]<<endl;
                for(int j=(nodes_in_stack.size())-1;j>=0;j--)
                {
                    if(how_many_visited[nodes_in_stack[j]]==1)
                    {
//                        cout<<"oitar source "<<nodes_in_stack[j]<<" "<<endl;

                        node_connectivity[total_trail[i]].push_back(nodes_in_stack[j]);

                        node_connectivity[nodes_in_stack[j]].push_back(total_trail[i]);
                        nodes_in_stack.push_back(total_trail[i]);
//                        cout<<"what is in nodes in stack "<<endl;
//                        for(int k=0;k<nodes_in_stack.size();k++)
//                        {
//                            cout<<nodes_in_stack[k]<<" ";
//                        }
//                        cout<<endl;
                        how_many_visited[total_trail[i]]++;
//                        cout<<total_trail[i]<<" "<<how_many_visited[total_trail[i]]<<endl;
                    }
                }
            }
            if(how_many_visited[total_trail[i]]==1)
            {
                how_many_visited[total_trail[i]]++;
            }
        }
        sort(nodes_in_stack.begin(),nodes_in_stack.end());
        for(int i=0;i<nodes_in_stack.size();i++)
        {
            printf("%c = %d\n",nodes_in_stack[i],node_connectivity[nodes_in_stack[i]].size());
        }
    }
    return 0;
}
