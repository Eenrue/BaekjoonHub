#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int n,m;
int miro[102][102];
int score[102][102];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void bfs(){
    deque<pair<int,int>> dq;
    dq.push_back({1,1});

    while(1){
        pair<int,int> f=dq.front();
        dq.pop_front();
        int y=f.first;
        int x=f.second;
        if(y==n&&x==m) return;
        for (int i=0;i<4;i++){
            int ny=y+dir[i][0];
            int nx=x+dir[i][1];
            if(miro[ny][nx]&&!score[ny][nx]){
                score[ny][nx]=score[y][x]+1;
                dq.push_back({ny,nx});
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    score[1][1]=1;

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<=m-1;j++){
            miro[i][j+1]=int(tmp[j])-'0';
        }
    }
    bfs();
    cout<<score[n][m];
    return 0;
}