#include <bits/stdc++.h>
using namespace std;
int g[101][101]={};
int ans[101][101]={};
int n;
void dfs(int x, int t){
    ans[x][t]=1;
    for(int i=0;i<n;i++){
        if(ans[t][i]==1){
            if(ans[x][i]==0){
                dfs(x,i);
            }
        }
    }


}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
            ans[i][j]=g[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]==1)dfs(i,j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<"\n";
    }
    return 0;
}