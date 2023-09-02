#include <bits/stdc++.h>
using namespace std;
int n,m;
char mp[21][21];
int ans;
int dxy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool alp[28];

void dfs(int y, int x,int cnt){
    if(ans<cnt) ans=cnt;
    for(int i=0;i<4;i++){
        int ny=y+dxy[i][0];
        int nx=x+dxy[i][1];
        if(ny<0||ny>=n||nx<0||nx>=m) continue;
        if(alp[mp[ny][nx]-'A']) continue;
        alp[mp[ny][nx]-'A']=true;
        dfs(ny,nx,cnt+1);
        alp[mp[ny][nx]-'A']=false;

    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ans=1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mp[i][j];
        }
    }
    alp[mp[0][0]-'A']=true;
    dfs(0,0,1);


    cout<<ans;
    return 0;
}
