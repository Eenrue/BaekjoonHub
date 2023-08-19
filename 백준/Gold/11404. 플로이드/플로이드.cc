#include <bits/stdc++.h>
using namespace std;
int n,m;
#define INF 987654321
int mp[101][101]={};

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]==0)mp[i][j]=INF;
        }
    }

    for(int i=0;i<m;i++){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        mp[n1][n2]=min(mp[n1][n2],n3);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mp[i][k]==INF||mp[k][j]==INF)continue;
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)cout<<"0 ";
            else if(mp[i][j]>=INF) cout<<"0 ";
            else cout<<mp[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
