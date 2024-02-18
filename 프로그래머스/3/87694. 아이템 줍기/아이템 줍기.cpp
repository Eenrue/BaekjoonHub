#include <bits/stdc++.h>
using namespace std;
int mp[101][101];
int dest[2]={};
bool vis[101][101]={};
int dxy[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int ans=987654321;

void dfs(int x,int y,int cnt){
    cout<<'s';
    if(x==dest[0]&&y==dest[1]){
        ans=min(ans,cnt);
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dxy[i][0];
        int ny=y+dxy[i][1];
        if(nx<2||ny<2||nx>100||ny>100||vis[nx][ny])continue;
        if(mp[nx][ny]!=1)continue;
        vis[nx][ny]=true;
        dfs(nx,ny,cnt+1);
        vis[nx][ny]=false;
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for(int i=0;i<rectangle.size();i++){
        int lx=2*rectangle[i][0];
        int ly=2*rectangle[i][1];
        int hx=2*rectangle[i][2];
        int hy=2*rectangle[i][3];
        for(int x=lx;x<=hx;x++){
            for(int y=ly;y<=hy;y++){
                if(x==lx||x==hx||y==ly||y==hy){
                    if(mp[x][y]>=0)mp[x][y]=1;
                }
                else mp[x][y]=-1;
            }
        }
    }
    dest[0]=2*itemX;
    dest[1]=2*itemY;
    dfs(2*characterX,2*characterY,0);
    return ans/2;
}