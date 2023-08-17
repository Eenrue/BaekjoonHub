#include <bits/stdc++.h>
using namespace std;
int mp[110]={};
int n,m;
int res;

int bfs(){
    queue<pair<int,int>> q;
    q.push({1,0});

    while(!q.empty()){
        int x=q.front().first;
        int cnt=q.front().second;
        q.pop();
        while(mp[x]){
            x=mp[x];
        }
        if(x>=100) return cnt;
        int tmp=0;
        for(int i=6;i>0;i--){
            if(mp[x+i]>0) {
                q.push({mp[x+i],cnt+1});
                continue;
            }
            if(tmp) continue;
            tmp=1;
            q.push({x+i,cnt+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    res=105;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        mp[a]=b;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mp[a]=b;
    }
    cout<<bfs();
    return 0;
}