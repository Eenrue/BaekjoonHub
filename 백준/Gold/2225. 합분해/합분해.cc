#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[201][201]={};

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        dp[i][1]=1;
    }
    for(int i=2;i<=k;i++){
        for(int j=0;j<=n;j++){
            if(dp[j][i-1]){
                for(int k=0;k<=n;k++){
                    if(j+k>n) continue;
                    dp[j+k][i]+=dp[j][i-1];
                    dp[j+k][i]%=1000000000;
                }
            }
        }
    }
    cout<<dp[n][k]%1000000000;
}
