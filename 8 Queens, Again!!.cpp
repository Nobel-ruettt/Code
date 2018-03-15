#include <iostream>
#include <stdio.h>
using namespace std;
int row[9],column[9],diagonal[9][9];
void reset()
{
    for(int i=0;i<9;i++)
    {
        row[i]=0;
        column[i]=0;
        for(int j=0;j<9;j++)
        {
            diagonal[i][j]=0;
        }
    }
}
int main()
{
    int tes;
    string s;
    scanf("%d",&tes);
    for(int i=0;i<tes;i++)
    {
        for(int j=1;j<=8;j++)
        {
            cin>>s;
            int sec=s[1]-'0';
            int first=s[0]-'A'+1;
            cout<<first<<sec;
        }
    }
}
