#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
bool can(ll high)
{
    ll dane_faka=n-k;
    ll bame_faka=k-1;
    ll now_tot=m;
    now_tot-=high;
    ll dane_lagbe=high-1;
    ll bame_lagbe=high-1;
    if(dane_faka>dane_lagbe)
    {
        ll baki_ase=(dane_faka-dane_lagbe);  /// extra_gula
        now_tot-=baki_ase;
        ll aro_ase=(dane_lagbe*(dane_lagbe+1))/2;///main_gula
        now_tot-=aro_ase;
    }
    else if(dane_faka==dane_lagbe)
    {
        ll aro_ase=(dane_lagbe*(dane_lagbe+1))/2;///main_gula
        now_tot-=aro_ase;
    }
    else if(dane_faka<dane_lagbe)
    {
        ll bad_dibo=dane_lagbe-dane_faka;
        ll mot_thakbe=(dane_lagbe*(dane_lagbe+1))/2;
        bad_dibo=(bad_dibo*(bad_dibo+1))/2;
        ll baki_thakbe=mot_thakbe-bad_dibo;
        now_tot-=baki_thakbe;
    }
    if(bame_faka>bame_lagbe)
    {
        ll baki_ase=(bame_faka-bame_lagbe);  /// extra_gula
        now_tot-=baki_ase;
        ll aro_ase=(bame_lagbe*(bame_lagbe+1))/2;///main_gula
        now_tot-=aro_ase;
    }
    else if(bame_faka==bame_lagbe)
    {
        ll aro_ase=(bame_lagbe*(bame_lagbe+1))/2;///main_gula
        now_tot-=aro_ase;
    }
    else if(bame_faka<bame_lagbe)
    {
        ll bad_dibo=bame_lagbe-bame_faka;
        ll mot_thakbe=(bame_lagbe*(bame_lagbe+1))/2;
        bad_dibo=(bad_dibo*(bad_dibo+1))/2;
        ll baki_thakbe=mot_thakbe-bad_dibo;
        now_tot-=baki_thakbe;
    }
    if(now_tot<0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    if(m<n)
    {
        cout<<"0"<<endl;
        return 0;
    }
    if(m==n)
    {
        cout<<"1"<<endl;
        return 0;
    }
    ll low=2;
    ll high=m;
    ll ans=1;
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(can(mid))
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
