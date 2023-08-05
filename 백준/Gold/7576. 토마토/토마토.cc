#include <bits/stdc++.h>

using namespace std;

int tom[1002][1002];
vector<pair<int,int>> eq;
deque<pair<int,int>> dq;

int m,n;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int ma=0;

void bfs(){
    while(dq.size()){
        int y=dq.front().first;
        int x=dq.front().second;
        dq.pop_front();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<1||nx<1||ny>n||nx>m) continue;
            if(tom[ny][nx]) continue;
            else{
                tom[ny][nx]=tom[y][x]+1;
                dq.push_back({ny,nx});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>tom[i][j];
            if(tom[i][j]==1) dq.push_back({i,j});
        }
    }
    bfs();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(tom[i][j]==0){
                cout<<"-1";
                return 0;
            }
            if(tom[i][j]>ma) ma=tom[i][j];
        }
    }
    cout<<ma-1;

    return 0;
}