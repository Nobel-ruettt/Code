#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;

struct main_edge
{
    ll u, v, g, s;
    bool operator < (const main_edge& b) const
    {
        return g < b.g;
    }
} edge[50100];

struct auxilliary_edge
{
    ll u, v, s;
    bool operator < (const auxilliary_edge& b) const
    {
        return s < b.s;
    }
} edge2[50010];
ll pr[210];
ll find(ll n)
{
    if (pr[n] == n)
        return n;
    return pr[n] = find(pr[n]);
}

ll edge_size;

ll minst()
{
    sort(edge2, edge2 + edge_size);

    for (ll i = 1; i <= n; i++)
        pr[i] = i;

    ll ans = 0, taken = 0, del = -1;

    for (ll i = 0; i < edge_size; i++)
    {
        ll x = edge2[i].u;
        ll y = edge2[i].v;

        ll p = find(x);
        ll q = find(y);

        if (p != q)
        {
            pr[p] = q;
            ans = max(ans, edge2[i].s);
            taken++;
            // this edge is in MST
        }
        else
        {
            del = i;
        }
    }

    if (del != -1)
        edge2[del] = edge2[--edge_size];

    if (taken == n-1)
        return ans;
    else return -1;
}
int main ()
{
    ll cs, t, i, j, k, x, y, z, q, m, h, w, ag, ans, G, S;

    scanf("%lld%lld%lld%lld",&n,&m,&G,&S);

    for (i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].g,&edge[i].s);
    }

    sort(edge + 1, edge + m + 1);

    edge_size = 0;

    ans = -1;

    for (i = 1; i <= m; i++)
    {
        edge2[edge_size].u = edge[i].u, edge2[edge_size].v = edge[i].v, edge2[edge_size].s = edge[i].s;
        edge_size++;

//        cout << ed[edsz-1].u << " yo " << ed[edsz-1].v << " " << ed[edsz-1].w << " " << edg[i].g << endl;

        x = minst();

  //      cout << x << endl;

        if (x != -1)
        {
            if (ans != -1)
                ans = min(G*edge[i].g + S*x, ans);
            else ans = G*edge[i].g + S*x;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
