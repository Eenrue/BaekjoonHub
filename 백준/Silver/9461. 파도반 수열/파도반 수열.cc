#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    long long ans[101]={};
    ans[1]=1;
    ans[2]=1;
    ans[3]=1;
    ans[4]=2;
    ans[5]=2;
    for(int i=6;i<101;i++){
        ans[i]=ans[i-1]+ans[i-5];
    }

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int tmp;
        cin>>tmp;
        cout<<ans[tmp]<<'\n';
    }
    return 0;
}