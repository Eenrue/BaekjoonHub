#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin>>n;
    int dp[50001]={};
    for(int i=1;i<=n;i++){
        int mini=5;
        for(int j=1;j*j<=i;j++){
            int tmp=i-j*j;
            mini=min(mini,dp[tmp]);
        }
        dp[i]=mini+1;
    }
    cout<<dp[n];
    return 0;
}