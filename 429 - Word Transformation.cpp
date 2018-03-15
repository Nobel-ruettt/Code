#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<string>words;
map<string,int>mark;
map<string, vector<string> >nodes;
deque<string>node;
map<string,ll>level;
int main()
{
    string word;
    string source_word,sec_word;
    string start,ending;
    ll mismatching;
    ll tes;
    cin>>tes;
    for(int l=1;l<=tes;l++)
    {
        while(1)
        {
            cin>>word;
            if(word=="*")
            {
                break;
            }
            words.push_back(word);
        }
        if(l>1)
        {
            printf("\n");
        }
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(j==i)
                {
                    continue;
                }
                source_word=words[i];
                sec_word=words[j];
                if(source_word.size()!=sec_word.size())
                {
                    continue;
                }
                else if(source_word.size()==sec_word.size())
                {
                    mismatching=0;
                    for(int i=0;i<source_word.size();i++)
                    {
                        if(source_word[i]!=sec_word[i])
                        {
                            mismatching++;
                        }
                    }
                    if(mismatching==1)
                    {
                          nodes[source_word].push_back(sec_word);
                          ///nodes[sec_word].push_back(source_word);
                    }
                }
            }
        }
        string line;
        map<string, int> dict;
        /**map<string, vector<string> >:: iterator it;
        for(it=nodes.begin();it!=nodes.end();it++)
        {
            cout<<"node  "<<it->first<<"  :   ";
            for(int i=0;i<it->second.size();i++)
            {
                cout<<it->second[i]<<"  ";
            }
            cout<<endl;
        }*/
        while(1)
        {
            getline(cin, line);
            if (line == "" || cin.eof())
               break;
            int space = line.find(" ");
            string start = line.substr(0, space);
            string ending = line.substr(space + 1);
            assert(dict.find(start) != dict.end());
            assert(dict.find(ending) != dict.end());
            string source_node=start;
            level[source_node]=0;
            node.push_back(source_node);
            mark[source_node]=1;
            while(!node.empty())
            {
                source_node=node.front();
                node.pop_front();
                if(source_node==ending)
                {
                    break;
                }
                for(int i=0;i<nodes[source_node].size();i++)
                {
                    if(mark[nodes[source_node][i]]==0)
                    {
                        level[nodes[source_node][i]]=level[source_node]+1;
                        mark[nodes[source_node][i]]=1;
                        node.push_back(nodes[source_node][i]);
                    }
                }
            }
            cout<<start<<" "<<ending<<" "<<level[ending]<<endl;
            node.clear();
            level.clear();
            mark.clear();
        }
        nodes.clear();
        words.clear();
    }
    return 0;
}
