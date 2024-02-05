#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int mp[1001][3];


int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int r,g,b;
        cin>>r>>g>>b;
        mp[i][0]=r;
        mp[i][1]=g;
        mp[i][2]=b;
    }
    int ans=INF;
    for(int i=0;i<3;i++){
        int dp[1001][3];
        for(int j=0;j<3;j++){
            if(i==j){
                dp[0][i]=mp[0][i];
                continue;
            }
            dp[0][j]=INF;
        }
        for(int j=1;j<n;j++){
            dp[j][0]=min(dp[j-1][1],dp[j-1][2])+mp[j][0];
            dp[j][1]=min(dp[j-1][0],dp[j-1][2])+mp[j][1];
            dp[j][2]=min(dp[j-1][0],dp[j-1][1])+mp[j][2];
        }

        for(int j=0;j<3;j++){
            if(i==j){
                continue;
            }
            ans=min(ans,dp[n-1][j]);
        }
    }
    cout<<ans;
}
