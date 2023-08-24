#include <bits/stdc++.h>
using namespace std;
int n,m;
int mp[8][8]={};
int dxy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int ans;
vector<pair<int,int>> vir;

void bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<vir.size();i++){
        q.push(vir[i]);
    }
    int vis[8][8]={};
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dxy[i][0];
            int nx=x+dxy[i][1];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(mp[ny][nx]!=0) continue;
            mp[ny][nx]=3;
            q.push({ny,nx});
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]==0)res++;
        }
    }
    ans=max(ans,res);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]==3)mp[i][j]=0;
        }
    }
}

void wall(int y,int x,int cnt){
    if(cnt==3){
        bfs();
        return;
    }
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==y&&j==x)flag=1;
            if(mp[i][j]!=0||!flag) continue;
            mp[i][j]=1;
            wall(i,j,cnt+1);
            mp[i][j]=0;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mp[i][j];
            if(mp[i][j]==2){
                vir.push_back({i,j});
            }
        }
    }
    ans=0;
    wall(0,0,0);
    cout<<ans;
    return 0;
}