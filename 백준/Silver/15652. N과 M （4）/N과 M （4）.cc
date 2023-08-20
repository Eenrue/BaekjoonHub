#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[9]={};
void pr(int k, int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=k;i<=n;i++){
        arr[cnt]=i;
        pr(i,cnt+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    pr(1,0);

    return 0;
}
