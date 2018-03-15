#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll alphabet[30],n,k;
string s;
int main()
{
    cin>>n>>k;
    cin>>s;
    for(ll i=0;i<s.size();i++)
    {
        alphabet[s[i]-'a']++;
        if(alphabet[s[i]-'a']>k)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
