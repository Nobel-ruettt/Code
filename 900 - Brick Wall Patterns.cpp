#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const double pi= acos(-1.0);
int c[27][27]={0};
void C()//计算当前字符串长度下的符合规则的排列总数
{
    int i,j;
    for(i=0;i<27;i++){
        c[i][0]=1;
        c[i][i]=1;
    }
    //以下是排列组合的递推公式
    for(i=1;i<27;i++)
    for(j=1;j<27;j++)
        c[i][j]=c[i-1][j-1]+c[i-1][j];
}
int main()
{
    int i,j,k;
    char str[15];
    LL sum;
    int cnt;
    C();
    while(~scanf("%s",str)){
        int len=strlen(str);
        sum=0;
        for(i=0;i<len-1;i++)
        if(str[i]>str[i+1]){
            printf("0\n");
            return 0;
        }
        for(i=1;i<len;i++)
            sum+=c[26][i];//c[26][i]表示长度为i的字符串的排列个数
        for(i=0;i<len;i++){
            if(i==0)
                cnt='a';
            else
                cnt=str[i-1]+1;//根据升序规则，当前位置的cnt至少要比str前一位置的字符大1，因为每一个的排列的开始为a，ab，abc，abcd
            while(cnt<str[i]){//根据升序规则，当前位置的ch最多只能比str这个位置实际上的字符小1
                sum+=c['z'-cnt][len-i-1];//小于等于ch的字符串的排列个数在上面已经计算，所以当前能够选择的字符总数为'z'-cnt
                                         //cnt位置后面（不包括cnt）剩下的位数，就是从'z'-cnt选择len-1-i个字符
                cnt++;
            }
        }
        printf("%lld\n",sum+1);//sum算的是比当前str小的所有的组合数，并不包括其本身，所以在这加1.
    }
    return 0;
}
