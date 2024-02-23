#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
vector<pair<int,int>> mp[201];

void dijk(int s, vector<int> &dis){
    priority_queue<pair<int,int>> pq;
    pq.push({0,s});
    dis[s]=0;
    while(!pq.empty()){
        int cdis=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(dis[cur]<cdis)continue;
        for(int i=0;i<mp[cur].size();i++){
            int next=mp[cur][i].first;
            int ndis=mp[cur][i].second+cdis;
            if(dis[next]>ndis){
                dis[next]=ndis;
                pq.push({-ndis,next});
            }
        }
    }
    
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for(int i=0;i<fares.size();i++){
        mp[fares[i][0]].push_back({fares[i][1],fares[i][2]});
        mp[fares[i][1]].push_back({fares[i][0],fares[i][2]});
    }
    vector<int> dis1(n+1,INF);
    dijk(s,dis1);
    vector<int> dis2(n+1,INF);
    dijk(a,dis2);
    vector<int> dis3(n+1,INF);
    dijk(b,dis3);
    
    for(int i=1;i<=n;i++){
        if(dis1[i]==INF||dis2[i]==INF||dis3[i]==INF)continue;
        answer=min(answer,dis1[i]+dis2[i]+dis3[i]);
    }
    
    return answer;
}