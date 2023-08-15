#include <bits/stdc++.h>
using namespace std;

char m[101][101]={};
int n;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void bfs(int iy,int ix){

    queue<pair<int,int>> q;
    q.push({iy,ix});
    char color=m[iy][ix];
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=n||m[ny][nx]!=color) continue;
            m[ny][nx]=0;
            q.push({ny,nx});
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<n;j++){
            m[i][j]=str[j];

        }
    }
    int tmp[101][101]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]=='R') tmp[i][j]='G';
            else tmp[i][j]=m[i][j];

        }
    }
    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]!=0){
                bfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<' ';
    ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m[i][j]=tmp[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]!=0){
                bfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}