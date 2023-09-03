#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int n,k;
bool vis[100001]={};

void bfs(){
    deque<pair<int,int>> dq;
    dq.push_back({n,0});

    while(!dq.empty()){
        int cur=dq.front().first;
        int dis=dq.front().second;
        dq.pop_front();
        if(cur==k){
            cout<<dis;
            break;
        }
        if(cur*2<100001){
            if(!vis[cur*2]){
                vis[cur*2]=true;
                dq.push_front({cur*2,dis});
            }
        }
        if(cur-1>=0){
            if(!vis[cur-1]){
                vis[cur-1]=true;
                dq.push_back({cur-1,dis+1});
            }
        }
        if(cur+1<100001){
            if(!vis[cur+1]){
                vis[cur+1]=true;
                dq.push_back({cur+1,dis+1});
            }
        }

    }
}



int main()
{

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;

    bfs();


    return 0;
}