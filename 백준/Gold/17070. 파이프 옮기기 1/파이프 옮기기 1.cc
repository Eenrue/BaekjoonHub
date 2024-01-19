#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int mp[18][18];
int n;
int res=0;

void dfs(int y,int x,int cnt){
    if(y>n||x>n)return;
    if(cnt==0){
        if(mp[y][x-1]==1)return;
    }
    if(cnt==1){
        if(mp[y-1][x]==1)return;
    }
    if(cnt==2){
        if(mp[y-1][x-1]||mp[y-1][x]||mp[y][x-1])return;
    }
    if(y==n&&x==n){
        if(mp[n][n])return;
        res++;
        return;
    }
    if(cnt==0){ // 가로
        dfs(y,x+1,0);
        dfs(y+1,x+1,2);
    }
    else if(cnt==1){
        dfs(y+1,x,1);
        dfs(y+1,x+1,2);
    }
    else if(cnt==2){
        dfs(y,x+1,0);
        dfs(y+1,x,1);
        dfs(y+1,x+1,2);
    }

}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }

    dfs(1,2,0);
    cout<<res;
}
