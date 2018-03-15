#include <bits/stdc++.h>
using namespace std;

/*------- Constants---- */
#define LMT                     100
#define ll                      long long
#define ull                     unsigned long long
#define mod                     1000000007
#define MEMSET_INF              63
#define MEM_VAL                 1061109567
#define FOR(i,n)                for( int i=0 ; i < n ; i++ )
#define mp(i,j)                 make_pair(i,j)
#define lop(i,a,b)              for( int i = (a) ; i < (b) ; i++)
#define pb(a)                   push_back((a))
#define gc                      getchar_unlocked
#define PI                      acos(-1.0)
#define inf                     1<<30
#define lc                      ((n)<<1LL)
#define rc                      ((n)<<1LL |1)
/* -------Global Variables ------ */
ll euclid_x,euclid_y,d;

/*---- short Cuts ------- */
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))
typedef pair<int, int> ii;
typedef vector<int > vi ;
/*------ template functions ------ */
#define sc(n) scanf("%lld",&(n))

/*************************** END OF TEMPLATE ****************************/

int  n , w;
int iA[35];
int lim  ;
vector<ll> L , H ;
void cal(int i,ll sum ,bool fl )
{
    ///cout<<fl<<endl;
    if(sum > w) return ;
    if( i > lim ){
        if(sum <= w) {
            if(fl )L.push_back(sum);
            else H.push_back(sum);
        }
        return;
    }
    cal(i + 1, sum ,fl );
    cal(i + 1, sum + iA[i],fl );
}
int bs(ll val)
{
    int low = 0 , high =(int ) H.size() - 1 , mid , ans =low -1;
    while (low <= high ) {
        mid = (low + high ) >>1;
        if(H[mid] <= val) {
            ans = mid ;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans ;
}

int main()
{

    int tc , cs = 0 ;
    sc(tc);
    while (tc -- ) {
        sc(n); sc(w);
        FOR(i , n) sc(iA[i]);
        lim = n / 2;
        cal(0 , 0,true );
        for(ll i=0;i<L.size();i++)
        {
            printf("%lld ",L[i]);
        }
        cout<<endl;
        lim = n - 1 ;
        cal(n / 2 + 1 , 0 ,false );
        for(ll i=0;i<H.size();i++)
        {
            printf("%lld ",H[i]);
        }
        cout<<endl;
        sort(L.begin(), L.end());
        sort(H.begin(), H.end());
        int ans = 0;
        for(int i = 0; i < L.size() ; i ++ ) {
            int k =  bs ( w - L[i]);
            ans += k +1;
        }

        printf("Case %d: %d\n",++cs , ans );
        L.clear();
        H.clear();
    }
    return 0;
}
