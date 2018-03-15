#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<char>vow;
vector<char>cons;
void consss()
{
    vow.push_back('A');
    vow.push_back('U');
    vow.push_back('E');
    vow.push_back('O');
    vow.push_back('I');
//    for(ll i=0;i<vow.size();i++)
//    {
//        cout<<vow[i]<<endl;
//    }
    cons.push_back('J');
    cons.push_back('S');
    cons.push_back('B');
    cons.push_back('K');
    cons.push_back('T');
    cons.push_back('C');
    cons.push_back('L');
    cons.push_back('D');
    cons.push_back('M');
    cons.push_back('V');
    cons.push_back('N');
    cons.push_back('W');
    cons.push_back('F');
    cons.push_back('X');
    cons.push_back('G');
    cons.push_back('P');
    cons.push_back('Y');
    cons.push_back('H');
    cons.push_back('Q');
    cons.push_back('Z');
    cons.push_back('R');
}
int main()
{
    ll tes,length;
    consss();
    scanf("%lld",&tes);
    for(ll k=1;k<=tes;k++)
    {
        scanf("%lld",&length);
        ll prev_vow=0;
        ll prev_cons=0;
        ll now_vow=0;
        ll now_cons=0;
        printf("Case %lld: ",k);
        for(ll i=1;i<=length;i++)
        {
            if(i%2==0)
            {
                if(prev_cons==5)
                {
                    now_cons++;
                    prev_cons=0;
                    printf("%c",cons[now_cons]);
                }
                else if(prev_cons<5)
                {
                    prev_cons++;
                    printf("%c",cons[now_cons]);
                }
            }
            else if(i%2==1)
            {
                if(prev_vow==21)
                {
                    now_vow++;
                    prev_vow=0;
                    printf("%c",vow[now_vow]);
                }
                else if(prev_vow<21)
                {
                    prev_vow++;
                    printf("%c",vow[now_vow]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
