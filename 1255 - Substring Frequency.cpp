#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1000005
char text[maxi];
char pattern[maxi];
ll length_pattern,length_text,count1;
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
        if (j == length_pattern)
        {
            count1++;
            j = lps[j-1];
        }
        else if (i < length_text && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%s",text);
        scanf("%s",pattern);
        length_pattern=strlen(pattern);
        length_text=strlen(text);
        count1=0;
        computeLPSArray();
        compute_kmp();
        printf("Case %lld: %lld\n",i,count1);
    }
    return 0;
}
