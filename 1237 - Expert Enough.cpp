#include <bits/stdc++.h>
using namespace std;
vector<string>company;
vector<pair<long,long> >ranges;
vector<string>ans;
int main()
{
    int tes,database,query;
    long low,high,price;
    string str;
    scanf("%d",&tes);
    for(int i=1;i<=tes;i++)
    {
        scanf("%d",&database);
        for(int j=0;j<database;j++)
        {
            cin>>str>>low>>high;
            company.push_back(str);
            ranges.push_back(make_pair(low,high));
        }
        scanf("%d",&query);
        for(int j=0;j<query;j++)
        {
            scanf("%ld",&price);
            for(int k=0;k<ranges.size();k++)
            {
                if(price>=ranges[k].first&&price<=ranges[k].second)
                {
                    ans.push_back(company[k]);
                }
            }
            if(ans.size()!=1)
            {
                printf("UNDETERMINED\n");
            }
            else
            {
                cout<<ans[0]<<endl;
            }
            ans.clear();
        }
        company.clear();
        ranges.clear();
    }
    return 0;
}
