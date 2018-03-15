#include<bits/stdc++.h>
#define mx 1000005
#define ll long long
#define ull unsigned long long
using namespace std;
struct simplehash
{
    int len;
    long long base, mod;
    vector <int> P, H, R;

    simplehash() {}
    simplehash(const char* str, long long b, long long m)
    {
        base = b, mod = m, len = strlen(str);
        P.resize(len + 3, 1), H.resize(len + 3, 0), R.resize(len + 3, 0);

        for (int i = 1; i <= len; i++) P[i] = (P[i - 1] * base) % mod;
        for (int i = 1; i <= len; i++) H[i] = (H[i - 1] * base + str[i - 1] + 1007) % mod;
        for (int i = len; i >= 1; i--) R[i] = (R[i + 1] * base + str[i - 1] + 1007) % mod;
    }

    inline int range_hash(int l, int r)
    {
        int hashval = H[r + 1] - ((long long)P[r - l + 1] * H[l] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }

    inline int reverse_hash(int l, int r)
    {
        ;
        int hashval = R[l + 1] - ((long long)P[r - l + 1] * R[r + 2] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }
};
struct stringhash
{
    simplehash sh1, sh2;
    stringhash() {}
    stringhash(const char* str)
    {
        sh2 = simplehash(str, 1997293877, 2117566807);
    }

    inline long long range_hash(int l, int r)
    {
        return ((long long)sh2.range_hash(l, r));
    }

    inline long long reverse_hash(int l, int r)
    {
        return ((long long)sh2.reverse_hash(l, r));
    }
} S1,S2;
char str1[mx],str2[mx];
bool solve(ll first_left,ll first_right,ll second_left,ll second_right)
{
    if(S1.range_hash(first_left,first_right)==S2.range_hash(second_left,second_right))
    {
        return 1;
    }
    else
    {
        ll sizee=(first_right-first_left+1);
        if(sizee%2==1)
        {
            return 0;
        }
        if(sizee%2==0)
        {
            ll mid_first=(first_left+first_right)/2;
            ll first_half1_left=first_left;
            ll first_half1_right=mid_first;
            ll first_half2_left=mid_first+1;
            ll first_half2_right=first_right;
            ll mid_second=(second_left+second_right)/2;
            ll second_half1_left=second_left;
            ll second_half1_right=mid_second;
            ll second_half2_left=mid_second+1;
            ll second_half2_right=second_right;
            return ((solve(first_half1_left,first_half1_right,second_half1_left,second_half1_right)&&solve(first_half2_left,first_half2_right,second_half2_left,second_half2_right))||(solve(first_half1_left,first_half1_right,second_half2_left,second_half2_right)&&solve(first_half2_left,first_half2_right,second_half1_left,second_half1_right)));
        }
    }
}
int main()
{
    int len1,len2;
    scanf("%s",str1);
    scanf("%s",str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    S1 = stringhash(str1);
    S2 = stringhash(str2);
    bool ans=solve(0,len1-1,0,len2-1);
    if(ans)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
