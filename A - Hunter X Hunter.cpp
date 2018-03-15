#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};
int pr[10000];
vector<edge> e;
vector<edge>mini;
vector<edge>other_than_mini;
int find(int r)
{
    return (pr[r] == r) ? r : find(pr[r]);
}
int mst(int n)
{
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++)
        pr[i] = i;

    int count = 0, s = 0;
    for (int i = 0; i < (int)e.size(); i++)
    {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v)
        {
            pr[u] = v;
            count++;
            s += e[i].w;
            mini.push_back(e[i]);
            if (count == n - 1)
                break;
        }
        else
        {
            other_than_mini.push_back(e[i]);
        }
    }
    return s;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge get;
        get.u = u;
        get.v = v;
        get.w = w;
        e.push_back(get);
    }
    cout << mst(n) << endl;
    for(int i=0;mini.size();i++)
    {
        cout<<mini[i].u<<" "<<mini[i].v<<" "<<mini[i].w<<endl;
    }
    return 0;
}
/*
7 10
1 2 2
1 3 2
2 3 3
1 4 2
2 4 2
2 5 4
3 5 5
3 6 2
3 7 4
6 7 3
*/
