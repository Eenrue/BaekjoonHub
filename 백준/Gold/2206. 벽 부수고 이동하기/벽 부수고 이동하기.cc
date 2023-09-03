#include <bits/stdc++.h>
using namespace std;
int n,m;
int mp[1001][1001];
bool vis[1001][1001][2];
int ans;
int dxy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void bfs(){

    queue<pair<pair<int,int>,int>> q;
    queue<int> dq;
    q.push({{0,0},0});
    dq.push(1);
    while(!q.empty()){
        int y=q.front().first.first;
        int x=q.front().first.second;
        int cnt=q.front().second;
        int dis=dq.front();
        dq.pop();
        q.pop();
        if(y==n-1&&x==m-1){
            ans=dis;
            break;
        }

        for(int i=0;i<4;i++){
            int ny=y+dxy[i][0];
            int nx=x+dxy[i][1];
            if(ny<0||ny>=n||nx<0||nx>=m) continue;
            if(vis[ny][nx][0]||vis[ny][nx][cnt]) continue;

            if(mp[ny][nx]==0){
                vis[ny][nx][cnt]=true;
                dq.push(dis+1);
                q.push({{ny,nx},cnt});
            }
            else{
                if(cnt)continue;
                int tmp=1;
                vis[ny][nx][tmp]=true;
                dq.push(dis+1);
                q.push({{ny,nx},tmp});
            }
        }
    }

}


int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ans=-1;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        string str;
        cin>>str;

        for(int j=0;j<m;j++){
            char c=str[j];
            mp[i][j]=atoi(&c);
        }
    }

    bfs();
    cout<<ans;
    return 0;
}