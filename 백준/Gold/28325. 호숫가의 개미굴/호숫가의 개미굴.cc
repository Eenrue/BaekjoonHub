#include <bits/stdc++.h>
using namespace std;
int main()
{

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int dp[250001];
	int ans=0;
	int n;
	int mp[250001]={};

	cin>>n;
	for(int i=0;i<n;i++){
        cin>>mp[i];
	}

	dp[0]=0;
	dp[1]=mp[0]+1;
	dp[2]=dp[0]+mp[1];
	for(int i=3;i<n;i++){
        dp[i]=max((dp[i-2]+mp[i-1]+1),dp[i-3]+mp[i-2]+mp[i-1]+1);
	}
	ans=dp[n-1];

	dp[0]=1;
	dp[1]=mp[0]+1;
	dp[2]=dp[0]+mp[1];
	for(int i=3;i<n-1;i++){
        dp[i]=max((dp[i-2]+mp[i-1]+1),dp[i-3]+mp[i-2]+mp[i-1]+1);
	}
	dp[n-1]=dp[n-2]+mp[n-1];

	cout<<max(ans,dp[n-1]);

	return 0;
}
