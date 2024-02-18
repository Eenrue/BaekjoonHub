#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int w[16][16];
int dp[16][1<<16];
int n;

int dfs(int cur, int vis){
    if(vis==((1<<n)-1)){
        if(w[cur][0]==0)return INF;
        return w[cur][0];
    }
    if(dp[cur][vis]!=-1)return dp[cur][vis];
    dp[cur][vis]=INF;
    for(int i=0;i<n;i++){
        if(w[cur][i]==0)continue;
        if((vis&(1<<i))==(1<<i))continue;
        dp[cur][vis]=min(dp[cur][vis],w[cur][i]+dfs(i,vis|1<<i));
    }
    return dp[cur][vis];
}

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>w[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));

    cout<<dfs(0,1);
}