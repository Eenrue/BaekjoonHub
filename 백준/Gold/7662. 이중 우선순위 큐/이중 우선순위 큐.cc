#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        priority_queue<int,vector<int>,greater<int>> minq;
        priority_queue<int> maxq;

        map<int,int> m;
        int n;
        cin>>n;
        int inp;
        char c;
        for(int j=0;j<n;j++){
            cin>>c>>inp;
            if(c=='I'){
                m[inp]++;
                minq.push(inp);
                maxq.push(inp);
            }
            else if(c=='D'){
                if(inp==1){
                    if(maxq.empty()) continue;
                    while(m[maxq.top()]==0&&!maxq.empty()) maxq.pop();
                    if(!maxq.empty())
                    {
                        m[maxq.top()]-=1;
                        maxq.pop();
                    }
                }
                else{
                    if(minq.empty()) continue;
                    while(m[minq.top()]==0&&!minq.empty()) minq.pop();
                    if(!minq.empty())
                    {
                        m[minq.top()]-=1;
                        minq.pop();
                    }
                }
            }
        }
        if(!maxq.empty()){
            while(m[maxq.top()]==0&&!maxq.empty()) maxq.pop();
        }
        if(!minq.empty()){
            while(m[minq.top()]==0&&!minq.empty()) minq.pop();
        }
        if(maxq.empty()) cout<<"EMPTY\n";
        else{
            cout<<maxq.top()<<' '<<minq.top()<<'\n';
        }
    }
    return 0;
}