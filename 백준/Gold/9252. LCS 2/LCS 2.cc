#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int dp[1001][1001];

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string str1;
    string str2;
    cin>>str1>>str2;
    if(str1[0]==str2[0])dp[0][0]=1;
    for(int i=1;i<str1.size();i++){
        if(dp[0][i-1])dp[0][i]=1;
        else if(str1[i]==str2[0])dp[0][i]=1;
    }
    for(int i=1;i<str2.size();i++){
        if(dp[i-1][0])dp[i][0]=1;
        else if(str1[0]==str2[i])dp[i][0]=1;
    }
    for(int j=1;j<str2.size();j++){
        for(int i=1;i<str1.size();i++){
            if(str1[i]==str2[j]){
                dp[j][i]=dp[j-1][i-1]+1;
            }
            else{
                dp[j][i]=max(dp[j-1][i],dp[j][i-1]);
            }
        }
    }
    cout<<dp[str2.size()-1][str1.size()-1]<<'\n';
    int i=str1.size()-1;
    int j=str2.size()-1;
    string ans="";
    while(ans.size()!=dp[str2.size()-1][str1.size()-1]){
        int f=1;
        while(i>0&&dp[j][i]==dp[j][i-1]){
            i--;
        }
        while(j>0&&dp[j][i]==dp[j-1][i]){
            j--;
        }
        ans+=str1[i];
        i--;
        j--;
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }

}
