#include <bits/stdc++.h>
using namespace std;

int n,m;
int rel[1002][1002];

void bfs(int x){
    queue<int> q;
    q.push(x);
    while(q.size()){
        int fir=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(rel[fir][i]==1){
                q.push(i);
                rel[fir][i]=2;
                rel[i][fir]=2;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        rel[i][i]=1;
    }
    for(int i=0;i<m;i++){
        int n1,n2;
        cin>>n1>>n2;
        rel[n1][n2]=1;
        rel[n2][n1]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(rel[i][j]==1){
                ans++;
                bfs(i);
            }
        }
    }
    cout<<ans;
}
