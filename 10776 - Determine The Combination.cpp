#include <iostream>
//#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

string str;
int n;

void choose_ch (vector<char> &ans,int start)
{
    if (ans.size() == n) {
       for(int i=0;i<ans.size();i++)
       {
           cout<<ans[i];
       }
        cout << endl;
        return;
    }
    for (int i = start; i < str.size(); ){
        char c = str[i];
        ans.push_back(c);
        choose_ch (ans, i+1);
        ans.pop_back();
        while (str[i] == c) i++;
    }
}
int  main ()
{
    ios::sync_with_stdio(false);
   // freopen ("input.txt","rt",stdin);
    while (cin >> str >> n){
        sort(str.begin(),  str.end());
        vector<char> ans;
        choose_ch(ans, 0);
    }
    return 0;
}
