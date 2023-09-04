#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v[100001];
bool vis[100001];
int maxdis;
int k;
int dp[100001]={};

void dfs(int p,int dis){
    if(dis>maxdis){
        maxdis=dis;
        k=p;
    }
    vis[p]=true;
    for(int i=0;i<v[p].size();i++){
        int next=v[p][i].first;
        if(vis[next])continue;
        dfs(next,dis+v[p][i].second);
    }
    vis[p]=false;
}


int main()
{

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;

    for(int i=0;i<n;i++){
        int n1;
        cin>>n1;
        while(1){
            int n2,n3;
            cin>>n2;
            if(n2==-1) break;
            cin>>n3;
            v[n1].push_back({n2,n3});
        }
    }
    dfs(1,0);
    memset(vis,0,sizeof(vis));
    dfs(k,0);
    cout<<maxdis;
    return 0;
}
