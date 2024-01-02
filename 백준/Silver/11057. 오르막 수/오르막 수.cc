#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1001][10];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<10;i++) dp[1][i]=1;

    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++){
                dp[i][j]+=dp[i-1][k];
                dp[i][j]%=10007;
            }
        }
    }

    int res=0;
    for(int i=0;i<10;i++){
        res+=dp[n][i];
    }
    cout<<res%10007;
}
