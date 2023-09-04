#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v[100001];
int ans;
bool vis[100001];
int dp[100001]={};

int dfs1(int x){
    for(int i=0;i<v[x].size();i++){
        int next=v[x][i].first;
        int nextdis=v[x][i].second;
        if(vis[next])continue;

        vis[next]=true;
        dp[x]=max(dp[x],nextdis+dfs1(next));
        vis[next]=false;
    }
    return dp[x];
}

void dfs2(int x){
    int max1=0;
    int max2=0;
    for(int i=0;i<v[x].size();i++){
        int next=v[x][i].first;
        int nextdis=v[x][i].second;
        if(vis[next])continue;
        int tmp=nextdis+dp[next];
        max2=max(max2,tmp);
        if(max2>max1){
            int sw=max1;
            max1=max2;
            max2=sw;
        }
        vis[next]=true;
        dfs2(next);
        vis[next]=false;
    }
    ans=max(ans,max1+max2);
}


int main()
{

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;

    ans=0;
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
    vis[1]=true;
    dfs1(1);
    vis[1]=false;

    vis[1]=true;
    dfs2(1);
    cout<<ans;
    return 0;
}
