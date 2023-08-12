#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int tx,ty;
int ma[1002][1002];
int cnt[1002][1002];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


void bfs(){
    queue<pair<int,int>> q;
    q.push({ty,tx});

    while(q.size()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(!cnt[ny][nx]&&ma[ny][nx]){
                cnt[ny][nx]=cnt[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ma[i][j];
            if(ma[i][j]==2){
                ty=i;
                tx=j;
            }
        }
    }
    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cnt[i][j]==0&&ma[i][j]!=0){
                cnt[i][j]=-1;
            }
        }
    }
    cnt[ty][tx]=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<cnt[i][j]<<" ";
        }
        cout<<'\n';
    }
}
