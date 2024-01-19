#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

vector<pair<int,int>> v[1001];
int n,m;
int s,e;
int ans;
vector<int> ansv;

void dijk(){
    int d[1001];
    int bac[1001];
    for(int i=1;i<=n;i++){
        d[i]=INF;
    }
    priority_queue<pair<int,int>> pq;
    d[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int dis=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(d[cur]<dis)continue;
        for(int i=0;i<v[cur].size();i++){
            int next=v[cur][i].first;
            int nextd=v[cur][i].second+dis;
            if(nextd<d[next]){
                bac[next]=cur;
                d[next]=nextd;
                pq.push({-nextd,next});
            }
        }
        //cout<<'1';
    }
    int tmp=e;
    cout<<d[e]<<'\n';
    deque<int> dq;

    while(1){
        dq.push_front(tmp);
        if(tmp==s)break;
        tmp=bac[tmp];

    }
    cout<<dq.size()<<'\n';

    while(!dq.empty()){
        cout<<dq.front()<<' ';
        dq.pop_front();
    }

}


int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        v[t1].push_back({t2,t3});
    }
    cin>>s>>e;

    dijk();
}
