#include <bits/stdc++.h>
using namespace std;

int mp[1026][1026]={};
int sum[1026][1026]={};

int main()
{

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=n;j++){
            tmp+=mp[i][j];
            sum[i][j]=tmp+sum[i-1][j];
        }
    }


    vector<pair<int,int>> sv;
    vector<pair<int,int>> ev;
    for(int i=0;i<m;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int tmp=0;
        tmp+=sum[x2][y2];
        tmp-=sum[x1-1][y2];
        tmp-=sum[x2][y1-1];
        tmp+=sum[x1-1][y1-1];
        cout<<tmp<<'\n';
    }
    return 0;
}
