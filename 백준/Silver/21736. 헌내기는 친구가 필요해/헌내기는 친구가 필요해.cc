#include <bits/stdc++.h>
using namespace std;

int n,m;
char mp[601][601]={};
int iy,ix;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(){
    bool vis[601][601]={};
    queue<pair<int,int>> q;
    q.push({iy,ix});
    vis[iy][ix]=true;
    int res=0;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=m||ny<0||ny>=n||vis[ny][nx]||mp[ny][nx]=='X') continue;
            if(mp[ny][nx]=='P') res++;
            q.push({ny,nx});
            vis[ny][nx]=true;
        }
    }
    if(res==0) cout<<"TT";
    else cout<<res;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            mp[i][j]=str[j];
            if(mp[i][j]=='I'){
                iy=i;
                ix=j;
            }
        }
    }
    dfs();

    return 0;
}
