#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int n,m;
int mp[101][101];
int sum=0;
int dxy[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool vis[101][101]={};
int outAir[101][101];

void air(int i,int j){
    deque<pair<int,int>> dq;
    dq.push_back({i,j});

    while(!dq.empty()){
        int y=dq.front().first;
        int x=dq.front().second;
        dq.pop_front();

        if(vis[y][x])continue;
        vis[y][x]=true;
        for(int i=0;i<4;i++){
            int ny=y+dxy[i][0];
            int nx=x+dxy[i][1];
            if(nx<0||ny<0||nx>=m||ny>=n) continue;
            if(mp[ny][nx]==1) outAir[ny][nx]++;
            else if(!vis[ny][nx]) dq.push_back({ny,nx});
        }
    }
}

bool day(){
    bool melt=false;
    memset(vis, 0, sizeof(vis));
    memset(outAir, 0, sizeof(outAir));
    air(0,0);
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (outAir[i][j] >= 2)
            {
                mp[i][j] = 0;
                melt=true;
            }
        }
    }
    return melt;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mp[i][j];
            if(mp[i][j]) sum++;
        }
    }
    air(0,0);

    int res=0;
    bool ismelt=true;
    while(1){
        ismelt=day();
        if(ismelt) res++;
        else break;
    }
    cout<<res;
}
