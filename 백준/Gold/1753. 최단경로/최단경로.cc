#include <bits/stdc++.h>
using namespace std;
int n,m;
#define INF 987654321
vector<pair<int,int>> v[20010];
int d[20010]={};
void dstra(int start){
    d[start]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        int dis=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(d[cur]<dis)continue;
        for(int i=0;i<v[cur].size();i++){
            int next=v[cur][i].first;
            int nextdis=v[cur][i].second+dis;
            if(nextdis<d[next]){
                d[next]=nextdis;
                pq.push({-nextdis,next});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;

    int start;
    cin>>start;
    for(int i=0;i<m;i++){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        v[n1].push_back({n2,n3});
    }

    for(int i=1;i<=n;i++){
        d[i]=INF;
    }
    dstra(start);
    for(int i=1;i<=n;i++){
        if(d[i]==INF)cout<<"INF\n";
        else cout<<d[i]<<'\n';
    }

    return 0;
}