#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
int n,m,x;
int d[1001];
int xd[1001];

vector<pair<int,int>> v[1001];

int dij(int start){
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<1001;i++) d[i]=INF;
    pq.push({0,start});
    d[start]=0;
    while(!pq.empty()){
        int cur=pq.top().second;
        int dis=-pq.top().first;
        pq.pop();
        if(d[cur]<dis) continue;

        for(int i=0;i<v[cur].size();i++){
            int next=v[cur][i].first;
            int nextdis=v[cur][i].second+dis;
            if(nextdis<d[next]){
                d[next]=nextdis;
                pq.push({-nextdis,next});
            }
        }
    }
    return d[x];
}


void xdij(){
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<1001;i++) xd[i]=INF;
    pq.push({0,x});
    xd[x]=0;
    while(!pq.empty()){
        int cur=pq.top().second;
        int dis=-pq.top().first;
        pq.pop();
        if(xd[cur]<dis) continue;
        for(int i=0;i<v[cur].size();i++){
            int next=v[cur][i].first;
            int nextdis=v[cur][i].second+dis;
            if(nextdis<xd[next]){
                xd[next]=nextdis;
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
        v[n1].push_back({n2,n3});
    }


    int ans=0;
    xdij();
    for(int i=1;i<=n;i++){
        ans=max(ans,dij(i)+xd[i]);
    }
    cout<<ans;

    return 0;
}
