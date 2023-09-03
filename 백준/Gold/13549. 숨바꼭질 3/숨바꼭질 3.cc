#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int n,k;
bool vis[100001]={};
int d[100001]={};

void bfs(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,n});
    d[n]=0;
    while(!pq.empty()){
        int dis=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(cur==k){
            cout<<d[cur];
            break;
        }
        if(cur-1>=0){
            if(dis+1<d[cur-1]){
                d[cur-1]=dis+1;
                pq.push({dis+1,cur-1});
            }
        }
        if(cur+1<=100000){
            if(dis+1<d[cur+1]){
                d[cur+1]=dis+1;
                pq.push({dis+1,cur+1});
            }
        }
        if(2*cur<=100000){
            if(dis<d[2*cur]){
                d[2*cur]=dis;
                pq.push({dis,2*cur});
            }
        }
    }
}



int main()
{

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<100001;i++) d[i]=INF;

    bfs();


    return 0;
}
