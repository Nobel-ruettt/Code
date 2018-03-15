#include <bits/stdc++.h>
using namespace std;
vector<string>word;
vector<string>ans;
vector<string>rules;
int words[110][300];
int digit[8][11];
int tot_word;
int tot_rule;
void take_input()
{
    ///cout<<"dhukse "<<endl;
    word.clear();
    rules.clear();
    ans.clear();
    string str,str2;
    for(int i=0;i<tot_word;i++)
    {
        cin>>str;
        word.push_back(str);
    }
    cin>>tot_rule;
    for(int i=0;i<tot_rule;i++)
    {
        cin>>str2;
        rules.push_back(str2);
    }
    ///cout<<"kaj korse"<<endl;
}
void clearer()
{
    ///cout<<"dhukse "<<endl;
    for(int i=0;i<=tot_word;i++)
    {
        for(int j=0;j<300;j++)
        {
           words[i][j]=0;
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<11;j++)
        {
            digit[i][j]=0;
        }
    }
    ///cout<<"kaj korse"<<endl;
}
string s;
void backtrack(int rule_number,int pos)
{
    if(pos>=rules[rule_number].size())
    {
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i];
        }
        cout<<endl;
        return ;
    }
    if(rules[rule_number][pos]=='#')
    {
        for(int i=0;i<word.size();i++)
        {
            if(words[i][pos]==0)
            {
                words[i][pos]=1;
                ans.push_back(word[i]);
                backtrack(rule_number,pos+1);
                ans.pop_back();
                words[i][pos]=0;
            }
        }
    }
    if(rules[rule_number][pos]=='0')
    {
        ///cout<<"thirdtate dhukse"<<endl;
        for(int i=0;i<10;i++)
        {
            if(digit[i][pos]==0)
            {
                digit[i][pos]=1;
                s=i+'0';
                ans.push_back(s);
                backtrack(rule_number,pos+1);
                ans.pop_back();
                digit[i][pos]=0;
            }
        }
    }
}
int main()
{
    while(scanf("%d",&tot_word)==1)
    {
        cout<<"--"<<endl;
        take_input();
        clearer();
        for(int i=0;i<rules.size();i++)
        {
            backtrack(i,0);
        }
    }
    return 0;
}
