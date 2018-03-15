#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll arr[1000005];
vector<ll>pos_of_first;
vector<pair<ll,ll> >st;
ll highest_size;
void cle()
{
    pos_of_first.clear();
    st.clear();
    highest_size=0;
}
void kahini0()
{
    for(ll i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            pos_of_first.push_back(i);
            if(pos_of_first.size()>highest_size)
            {
                highest_size=pos_of_first.size();
            }
            arr[i]=2;
        }
        else if(s[i]==')')
        {
            pos_of_first.pop_back();
            arr[i]=3;
        }
        else if(s[i]=='F')
        {
            arr[i]=0;
        }
        else if(s[i]=='T')
        {
            arr[i]=1;
        }
    }
}
void kahini1()
{
    st.push_back(make_pair(2,1));
    for(ll i=1; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            st.push_back(make_pair(2,st[st.size()-1].second+1));
        }
        else if(s[i]=='F' || s[i]=='T')
        {
            ll top_bit;
            if(s[i]=='F')
            {
                top_bit=0;
            }
            else
            {
                top_bit=1;
            }
            if(st[st.size()-1].first==2)
            {
                st.push_back(make_pair(top_bit,st[st.size()-1].second));
            }
            else
            {
                if(st[st.size()-1].second%2==1)
                {
                    ll dhukbe=st[st.size()-1].second;
                    ll stack_top_bit=st[st.size()-1].first;
                    st.pop_back();
                    st.push_back(make_pair(stack_top_bit&top_bit,dhukbe));
                }
                else if(st[st.size()-1].second%2==0)
                {
                    ll dhukbe=st[st.size()-1].second;
                    ll stack_top_bit=st[st.size()-1].first;
                    st.pop_back();
                    st.push_back(make_pair(stack_top_bit|top_bit,dhukbe));
                }
            }
        }
        else if(s[i]==')')
        {
            if(st[st.size()-1].first==2)
            {
                st.pop_back();
            }
            else
            {
                ll top_bit=st[st.size()-1].first;
                st.pop_back();
                st.pop_back();
                if(st.size()==0)
                {
                    st.push_back(make_pair(top_bit,1));
                }
                else if(st.size()>0)
                {
                    if(st[st.size()-1].first==2)
                    {
                        st.push_back(make_pair(top_bit,st[st.size()-1].second));
                    }
                    else
                    {
                        if(st[st.size()-1].second%2==1)
                        {
                            ll dhukbe=st[st.size()-1].second;
                            ll stack_top_bit=st[st.size()-1].first;
                            st.pop_back();
                            st.push_back(make_pair(stack_top_bit&top_bit,dhukbe));
                        }
                        else if(st[st.size()-1].second%2==0)
                        {
                            ll dhukbe=st[st.size()-1].second;
                            ll stack_top_bit=st[st.size()-1].first;
                            st.pop_back();
                            st.push_back(make_pair(stack_top_bit|top_bit,dhukbe));
                        }
                    }
                }
            }
        }
    }
}
void kahini2()
{
    st.push_back(make_pair(2,1));
    for(ll i=1; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            st.push_back(make_pair(2,st[st.size()-1].second+1));
        }
        else if(s[i]=='F' || s[i]=='T')
        {
            ll top_bit;
            if(s[i]=='F')
            {
                top_bit=0;
            }
            else
            {
                top_bit=1;
            }
            if(st[st.size()-1].first==2)
            {
                st.push_back(make_pair(top_bit,st[st.size()-1].second));
            }
            else
            {
                if(st[st.size()-1].second%2==1)
                {
                    ll dhukbe=st[st.size()-1].second;
                    ll stack_top_bit=st[st.size()-1].first;
                    st.pop_back();
                    st.push_back(make_pair(stack_top_bit|top_bit,dhukbe));
                }
                else if(st[st.size()-1].second%2==0)
                {
                    ll dhukbe=st[st.size()-1].second;
                    ll stack_top_bit=st[st.size()-1].first;
                    st.pop_back();
                    st.push_back(make_pair(stack_top_bit&top_bit,dhukbe));
                }
            }
        }
        else if(s[i]==')')
        {
            if(st[st.size()-1].first==2)
            {
                st.pop_back();
            }
            else
            {
                ll top_bit=st[st.size()-1].first;
                st.pop_back();
                st.pop_back();
                if(st.size()==0)
                {
                    st.push_back(make_pair(top_bit,1));
                }
                else if(st.size()>0)
                {
                    if(st[st.size()-1].first==2)
                    {
                        st.push_back(make_pair(top_bit,st[st.size()-1].second));
                    }
                    else
                    {
                        if(st[st.size()-1].second%2==1)
                        {
                            ll dhukbe=st[st.size()-1].second;
                            ll stack_top_bit=st[st.size()-1].first;
                            st.pop_back();
                            st.push_back(make_pair(stack_top_bit|top_bit,dhukbe));
                        }
                        else if(st[st.size()-1].second%2==0)
                        {
                            ll dhukbe=st[st.size()-1].second;
                            ll stack_top_bit=st[st.size()-1].first;
                            st.pop_back();
                            st.push_back(make_pair(stack_top_bit&top_bit,dhukbe));
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    ll tes=1;
    while(1)
    {
        cin>>s;
        if(s=="()")
        {
            break;
        }
        cle();
        kahini0();
        if(highest_size%2==1)
        {
            kahini1();
        }
        else if(highest_size%2==0)
        {
            kahini2();
        }
        if(st[st.size()-1].first==1)
        {
            printf("%lld. true\n",tes);
        }
        else
        {
            printf("%lld. false\n",tes);
        }
        tes++;
    }
    return 0;
}
