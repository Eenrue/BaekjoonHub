#include <bits/stdc++.h>
using namespace std;
int n;
int mp[100002][2];

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<2;j++){
            for(int k=0;k<n;k++){
                cin>>mp[k][j];
            }
        }
        int dp[100002][2];
        dp[0][0]=mp[0][0];
        dp[0][1]=mp[0][1];
        if(n==1){
            cout<<max(dp[n-1][0],dp[n-1][1])<<'\n';
            continue;
        }
        dp[1][0]=dp[0][1]+mp[1][0];
        dp[1][1]=dp[0][0]+mp[1][1];
        for(int j=2;j<n;j++){
            dp[j][0]=max(dp[j-1][1]+mp[j][0],dp[j-2][1]+mp[j][0]);
            dp[j][1]=max(dp[j-1][0]+mp[j][1],dp[j-2][0]+mp[j][1]);
        }
        cout<<max(dp[n-1][0],dp[n-1][1])<<'\n';

    }
    return 0;
}