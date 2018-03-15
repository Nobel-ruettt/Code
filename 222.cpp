#include<bits/stdc++.h>
using namespace std;
int N;
map<int, int> factors;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N;
    while(N--)
    {
        int strength;
        cin >> strength;
        int root = sqrt(strength);
        for(int i = 2; i <= root; i++)
        {
            if(strength%i == 0)
                factors[i]++;
            while(strength%i ==0)
            {
                strength/= i;
            }
        }
        if(strength > 1) factors[strength]++;
    }
    int ans = 1;
    map<int,int>:: iterator it;
    for(it = factors.begin(); it != factors.end(); it++)
    {
        ans = max(ans, (*it).second);
    }
    cout << ans << endl;
    return 0;
}

