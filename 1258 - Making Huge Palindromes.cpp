#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1000005
char text[maxi];
char pattern[maxi];
ll length_pattern,length_text,maximum_match;
ll lps[maxi];
void computeLPSArray()
{
    ll len = 0;
    lps[0] = 0;
    ll i = 1;
    while (i < length_pattern)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void compute_kmp()
{
    ll i = 0;
    ll j  = 0;
    while (i < length_text)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }
        else if (i < length_text && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    maximum_match=j;
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%s",text);
        maximum_match=0;
        length_text=strlen(text);
        ll in=0;
        for(ll i=length_text-1;i>=0;i--)
        {
            pattern[in]=text[i];
            in++;
        }
        length_pattern=in;
        computeLPSArray();
        compute_kmp();
        printf("Case %lld: %lld\n",cas,2*length_text-maximum_match);
    }
    return 0;
}
