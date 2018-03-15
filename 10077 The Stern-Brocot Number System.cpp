#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll up_or,down_or,prev_lef_up,prev_lef_down,prev_right_up,prev_right_down,node_up,node_down,node_lef_up,node_lef_down,node_right_down,node_right_up;
    double absuleft,absuright,absuorginal;
    string seq;
    while(scanf("%lld%lld",&up_or,&down_or))
    {
        if(up_or==1 && down_or==1)
        {
            break;
        }
        prev_lef_down=1;
        prev_lef_up=0;
        prev_right_down=0;
        prev_right_up=1;
        node_up=1;
        node_down=1;
        seq="";
        absuorginal=(double)(((double)(up_or))/((double)(down_or)));
        while(1)
        {
            if(node_up==up_or && node_down==down_or)
            {
                cout<<seq<<endl;
                break;
            }
            node_lef_up=node_up+prev_lef_up;
            node_lef_down=node_down+prev_lef_down;
            node_right_up=node_up+prev_right_up;
            node_right_down=node_down+prev_right_down;
            if(node_up*down_or> node_down * up_or)
            {
                prev_right_up=node_up;
                prev_right_down=node_down;
                node_up=node_lef_up;
                node_down=node_lef_down;
                seq=seq+"L";
            }
            else
            {
                prev_lef_up=node_up;
                prev_lef_down=node_down;
                node_up=node_right_up;
                node_down=node_right_down;
                seq=seq+"R";
            }
        }
    }
    return 0;
}
