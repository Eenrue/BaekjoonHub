#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
int n,m,x;
int d[1001][2];

vector<pair<int,int>> v[1001][2];


void dij(int ver){
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<1001;i++) d[i][ver]=INF;
    pq.push({0,x});
    d[x][ver]=0;
    while(!pq.empty()){
        int cur=pq.top().second;
        int dis=-pq.top().first;
        pq.pop();
        if(d[cur][ver]<dis) continue;

        for(int i=0;i<v[cur][ver].size();i++){
            int next=v[cur][ver][i].first;
            int nextdis=v[cur][ver][i].second+dis;
            if(nextdis<d[next][ver]){
                d[next][ver]=nextdis;
                pq.push({-nextdis,next});
            }
        }
    }
}


int main()
{

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>x;
    for(int i=0;i<m;i++){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        v[n1][0].push_back({n2,n3});
        v[n2][1].push_back({n1,n3});
    }


    int ans=0;
    dij(0);
    dij(1);
    for(int i=1;i<=n;i++){
        ans=max(ans,d[i][0]+d[i][1]);
    }
    cout<<ans;

    return 0;
}
