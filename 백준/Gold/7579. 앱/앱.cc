#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int n,m;

int b[101];
int c[101];
int sum=0;
int dp[101][10001];


int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        sum+=c[i];
    }
    for(int i=1;i<=n;i++){
        int bi=b[i];
        int ci=c[i];
        for(int j=0;j<=sum;j++){
            if(ci<=j)dp[i][j]=max(dp[i-1][j],dp[i-1][j-ci]+bi);
            else dp[i][j]=dp[i-1][j];
        }
    }
    for(int j=0;j<=sum;j++){
        if(dp[n][j]>=m){
            cout<<j;
            break;
        }
    }
}
