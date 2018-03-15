#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10000007
ll a, b, c, d, e, f;
ll fn( ll n ) {
    if( n == 0 ) return a%mod;
    if( n == 1 ) return b%mod;
    if( n == 2 ) return c%mod;
    if( n == 3 ) return d%mod;
    if( n == 4 ) return e%mod;
    if( n == 5 ) return f%mod;
    return( (fn(n-1) %mod+ fn(n-2)%mod + fn(n-3)%mod + fn(n-4)%mod + fn(n-5)%mod + fn(n-6)%mod)%mod );
}
int main() {
    ll n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n) % mod);
    }
    return 0;
}
