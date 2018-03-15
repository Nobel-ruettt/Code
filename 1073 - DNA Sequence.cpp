#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)

char s[20][110];
ll add[20][20];

char temp[110];

ll n;

#define pll pair<ll, ll>

ll dp[65000][17];
pll next[65000][17];

ll solve(ll mask, ll last)
{
    if (mask == (1LL<<n)-1)
        return 0;

    ll &res = dp[mask][last];

    if (res != -1)
        return res;

    res = LLONG_MAX;

    for (ll i = 0; i < n; i++)
    {
        if ( (mask & (1LL<<i)) == 0 )
        {
            if (last == 16)
            {
                ll x = solve(mask|(1LL<<i), i) + strlen(s[i]);

                if (x < res)
                {
                    res = x;
                    next[mask][last] = pll(mask|(1LL<<i), i);
                }
                else if (x == res && strcmp(s[next[mask][last].second], s[i]) > 0)
                {
                    next[mask][last] = pll(mask|(1LL<<i), i);
                }
            }
            else
            {
                ll x = solve(mask|(1LL<<i), i) + add[last][i];

                if (x < res)
                {
                    res = x;
                    next[mask][last] = pll(mask|(1LL<<i), i);
                }
                else if (x == res && strcmp(s[next[mask][last].second], s[i]) > 0)
                {
                    next[mask][last] = pll(mask|(1LL<<i), i);
                }

            }
        }
    }

    return res;
}

char r[20000];

void print(ll mask, ll last)
{
    if (mask == (1LL<<n)-1)
        return ;

    if (last == 16)
    {
        strcpy(r, s[next[mask][last].second]);
    }
    else
    {
        strcat(r, s[next[mask][last].second] + strlen(s[next[mask][last].second]) - add[last][next[mask][last].second]);
    }

    print(next[mask][last].first, next[mask][last].second);
}

int main()
{

//    cout << strcmp("CAT", "ATC") << endl;

    ll cs, t, i, j, k;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (i = 0; i < n; i++)
        {
            scanf("%s", s[i]);
        }

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                strcpy(temp, s[j]);

                ll li = strlen(s[i]);
                ll lj = strlen(temp);
                add[i][j] = lj;

                while(1)
                {
                    if (lj > li)
                    {
                        lj--;
                        if (lj <= 0)
                            break;
                        temp[lj] = 0;
                        continue;
                    }

                    if (!strcmp(temp, s[i] + li - lj))
                    {
                        add[i][j] = strlen(s[j]) - lj;
                        break ;
                    }

                    lj--;
                    if (lj <= 0)
                        break;
                    temp[lj] = 0;
                }
//                cout << i << " " << j << " " << add[i][j] << endl;
            }

        memset(dp, -1, sizeof(dp));

        solve(0, 16);

        print(0, 16);

        printf("Case %lld: %s\n", cs, r);
    }

    return 0;
}
