#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int n,e;
vector<pair<int,int>> mp[801];

ll dijk(int a,int b){
    vector<ll> dis(n+1,INF);

    priority_queue<pair<ll,ll>> pq;
    dis[a]=0;
    pq.push({0,a});
    while(!pq.empty()){
        int cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(cost>dis[cur]) continue;
        for(int i=0;i<mp[cur].size();i++){
            int ncur=mp[cur][i].first;
            int ncost=mp[cur][i].second;
            if(dis[ncur]>cost+ncost){
                dis[ncur]=cost+ncost;
                pq.push({-dis[ncur],ncur});
            }
        }
    }
    return dis[b];
}


int main()
{

    cin>>n>>e;
    for(int i=0;i<e;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        mp[t1].push_back({t2,t3});
        mp[t2].push_back({t1,t3});
    }
    int v1,v2;
    cin>>v1>>v2;
    if(min((dijk(1,v1)+dijk(v1,v2)+dijk(v2,n)),(dijk(1,v2)+dijk(v2,v1)+dijk(v1,n)))>=INF){
        cout<<"-1";
        return 0;
    }
    cout<<min((dijk(1,v1)+dijk(v1,v2)+dijk(v2,n)),(dijk(1,v2)+dijk(v2,v1)+dijk(v1,n)));
}
