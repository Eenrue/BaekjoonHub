#include <bits/stdc++.h>

using namespace std;

int tom[102][102][102];
deque<tuple<int,int,int>> dq;

int m,n,h;
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int ma=0;

void bfs(){
    while(dq.size()){
        int z=get<0>(dq.front());
        int y=get<1>(dq.front());
        int x=get<2>(dq.front());
        dq.pop_front();

        for(int i=0;i<6;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            int nz=z+dz[i];
            if(ny<1||nx<1||nz<1||ny>n||nx>m||nz>h) continue;
            if(tom[nz][ny][nx]) continue;
            else{
                tom[nz][ny][nx]=tom[z][y][x]+1;
                dq.push_back({nz,ny,nx});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n>>h;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>tom[i][j][k];
                if(tom[i][j][k]==1) dq.push_back({i,j,k});
            }
        }
    }
    bfs();
    for(int i=1;i<=h;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                if(tom[i][j][k]==0){
                cout<<"-1";
                return 0;
                }
                if(tom[i][j][k]>ma) ma=tom[i][j][k];
            }
        }
    }
    cout<<ma-1;

    return 0;
}