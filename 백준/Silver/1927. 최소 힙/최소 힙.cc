#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin>>num;

    priority_queue<int,vector <int>,greater<int>> pq;

    for(int i=0;i<num;i++){
        int inp;
        cin>>inp;
        if(inp==0){
            if(pq.size()==0){
                cout<<"0\n";
            }
            else{
                int res=pq.top();
                cout<<res<<'\n';
                pq.pop();
            }
        }
        else{
            pq.push(inp);
        }
    }
    return 0;
}