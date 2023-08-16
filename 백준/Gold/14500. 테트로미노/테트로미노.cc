#include <bits/stdc++.h>
using namespace std;

int n,m;
int mp[505][505]={};
int dfs1(int y,int x,int k){
    if(k==4) return mp[y][x];
    return max(dfs1(y+1,x,k+1)+mp[y][x],dfs1(y,x+1,k+1)+mp[y][x]);
}
int dfs2(int y,int x,int k){
    if(y<0) return 0;
    if(k==4) return mp[y][x];
    return max(dfs2(y-1,x,k+1)+mp[y][x],dfs2(y,x+1,k+1)+mp[y][x]);
}
int dfs3(int y,int x,int k){
    if(k==1) return max(dfs3(y+1,x,k+1)+mp[y][x],dfs3(y,x+1,k+1)+mp[y][x]);
    if(k==2) return mp[y][x]+mp[y+1][x]+mp[y][x+1];
}
int dfs4(int y,int x,int k){
    if(y-1<0)return 0;
    int a=mp[y][x]+mp[y][x+1]+mp[y-1][x+1]+mp[y+1][x+1];
    int b=mp[y][x]+mp[y][x+1]+mp[y-1][x+1]+mp[y][x+2];
    return max(a,b);
}

int dfs5(int y,int x){
    return mp[y][x]+ mp[y+1][x]+ mp[y][x+1]+ mp[y+1][x+1];
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp;
            cin>>tmp;
            mp[i][j]=tmp;
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp=max(max(dfs1(i,j,1),dfs2(i,j,1)),max(dfs3(i,j,1),dfs4(i,j,1)));
            tmp=max(tmp,dfs5(i,j));
            if(tmp>res) {
                res=tmp;
            }
        }
    }
    cout<<res;
    return 0;
}