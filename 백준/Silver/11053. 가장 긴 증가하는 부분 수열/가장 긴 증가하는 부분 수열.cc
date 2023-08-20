#include <bits/stdc++.h>
using namespace std;
int tmp;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    int arr[1001];
    int dp[1001];

    int ans=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        int tmp;
        cin>>tmp;
        arr[i]=tmp;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }

    cout<<ans;
    return 0;
}