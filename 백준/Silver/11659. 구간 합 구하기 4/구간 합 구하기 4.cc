#include <bits/stdc++.h>
using namespace std;

int num[100002];
int sum[100002];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n;
    cin>>m;
    cin>>num[1];
    sum[1]=num[1];
    for(int i=2;i<=n;i++){
        cin>>num[i];
        sum[i]+=sum[i-1]+num[i];
    }
    for(int i=0;i<m;i++){
        int n1,n2;
        cin>>n1>>n2;
        cout<<sum[n2]-sum[n1-1]<<'\n';
    }

}