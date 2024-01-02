#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inp[1001];
int dp[1001]={};

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>inp[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[j]=max(dp[j],dp[j-i]+inp[i]);
        }
    }
    cout<<dp[n];
}
