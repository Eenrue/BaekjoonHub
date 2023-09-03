#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    int arr[1002]={};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int dp[1002][2]={};
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
        for(int j=1;j<i;j++){
            if(arr[j]<arr[i])dp[i][0]=max(dp[i][0],dp[j][0]+1);
        }
    }
    for(int i=n;i>=1;i--){
        dp[i][1]=1;
        for(int j=n;j>i;j--){
            if(arr[j]<arr[i])dp[i][1]=max(dp[i][1],dp[j][1]+1);
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        ans=max(ans,dp[i][0]+dp[i][1]);
    }
    cout<<ans-1;
    return 0;
}
