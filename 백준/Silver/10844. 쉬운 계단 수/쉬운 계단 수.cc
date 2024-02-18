#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;
ll dp[101][10]={0,};

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    dp[1][0]=0;
    for(int i=1;i<10;i++)dp[1][i]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            if(j==0)dp[i][0]=dp[i-1][1];
            else if(j==9)dp[i][9]=dp[i-1][8];
            else{
                dp[i][j]=(dp[i-1][j+1]+dp[i-1][j-1])%1000000000;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<10;i++)ans=(ans+dp[n][i])%1000000000;
    cout<<ans;
}

