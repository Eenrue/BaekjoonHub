#include <bits/stdc++.h>
using namespace std;

int n,k,r;
int road[101][101][4]={};//북동남서
int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
vector<pair<int,int>> cow;
int mp[101][101]={};
bool vis[101][101]={};

void bfs(int sy, int sx){
    queue<pair<int,int>> q;
    q.push({sy,sx});
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        if(vis[y][x])continue;
        vis[y][x]=true;
        for(int i=0;i<4;i++){
            int ny=y+dxy[i][0];
            int nx=x+dxy[i][1];
            if(ny<1||nx<1||ny>n||nx>n||vis[ny][nx])continue;
            if(road[y][x][i])continue;
            q.push({ny,nx});
        }
    }
}

int main(){
    cin>>n>>k>>r;

    for(int i=0;i<r;i++){
        int r1,r2,c1,c2;
        cin>>r1>>c1>>r2>>c2;
        for(int j=0;j<4;j++){
            int nr=r1+dxy[j][0];
            int nc=c1+dxy[j][1];
            if(nr==r2&&nc==c2){
                road[r1][c1][j]=1;
                road[r2][c2][(j+2)%4]=1;
            }
        }

    }
    for(int i=0;i<k;i++){
        int r1,c1;
        cin>>r1>>c1;
        cow.push_back({r1,c1});
    }
    int ans=0;
    for(int i=0;i<k;i++){
        memset(vis,0,sizeof(vis));
        bfs(cow[i].first,cow[i].second);
        for(int j=i+1;j<k;j++){
            if(vis[cow[j].first][cow[j].second]==false)ans++;
        }
    }
    cout<<ans;
}
