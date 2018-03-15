#include <bits/stdc++.h>
using namespace std;
#define ll int
#define sc(n) scanf("%d",&n);
#define maxn 100005
ll next[55][maxn];
ll created[maxn];
ll endmark[maxn];
ll sz,n,m;
string words[10005];
void cle()
{
    for(ll i=0; i<maxn; i++)
    {
        for(ll j=0; j<55; j++)
        {
            next[j][i]=0;
        }
        created[i]=0;
        endmark[i]=0;
    }
    sz=0;
}
void insert(string &s)
{
    ll v=0;
    for(ll i=0; i<s.size(); i++)
    {
        ll id;
        if(s[i]>='a' && s[i]<='z')
        {
            id=s[i]-'a';
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            id=s[i]-'A'+26;
        }
        if(created[next[id][v]]==0)
        {
            next[id][v]=++sz;
            created[next[id][v]]=1;
        }
        v=next[id][v];
    }
    endmark[v]++;
}
ll search(string &s)
{
    ll v=0;
    for(ll i=0; i<s.size(); i++)
    {
        ll id;
        if(s[i]>='a' && s[i]<='z')
        {
            id=s[i]-'a';
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            id=s[i]-'A'+26;
        }
        if(created[next[id][v]]==0)
        {
            return 0;
        }
        v=next[id][v];
    }
    return endmark[v];
}
void in_words()
{
    string s;
    for(ll i=1; i<=n; i++)
    {
        cin>>words[i];
        if(words[i].size()==1)
        {
            insert(words[i]);
        }
        else if(words[i].size()==2)
        {
            insert(words[i]);
        }
        else if(words[i].size()>2)
        {
            s.clear();
            s.push_back(words[i][0]);
            for(ll j=1; j<words[i].size()-1; j++)
            {
                s.push_back('a');
            }
            ll sz=words[i].size()-1;
            s.push_back(words[i][sz]);
            insert(s);
        }
    }
}
void in_sentences()
{
    ll sum;
    string sentence,word;
    for(ll i=1; i<=m; i++)
    {
        sum=1;
        getline(cin,sentence);
        if(sentence.size()==0)
        {
            cout<<sentence<<endl;
            printf("1\n");
            continue;
        }
        cout<<sentence<<endl;
        word.clear();
        for(ll i=0; i<sentence.size(); i++)
        {
            if(sentence[i]!=' ')
            {
                word.push_back(sentence[i]);
            }
            else if(sentence[i]==' ')
            {
                if(word.size()<=2)
                {
                    sum*=search(word);
                }
                else if(word.size()>2)
                {
                    string now_s;
                    now_s.push_back(word[0]);
                    for(ll j=1; j<word.size()-1; j++)
                    {
                        now_s.push_back('a');
                    }
                    now_s.push_back(word[word.size()-1]);
                    sum*=search(now_s);
                }
                word.clear();
            }
        }
        if(word.size()<=2)
        {
            sum*=search(word);
        }
        else if(word.size()>2)
        {
            string now_s;
            now_s.push_back(word[0]);
            for(ll j=1; j<word.size()-1; j++)
            {
                now_s.push_back('a');
            }
            now_s.push_back(word[word.size()-1]);
            sum*=search(now_s);
        }
        printf("%d\n",sum);
    }
}
int main()
{
    ll tes;
    sc(tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        cle();
        sc(n);
        printf("Case %d:\n",cas);
        in_words();
        sc(m);
        getchar();
        in_sentences();
    }
    return 0;
}
