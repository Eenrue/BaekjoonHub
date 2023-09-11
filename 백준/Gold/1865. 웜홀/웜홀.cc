#include <bits/stdc++.h>
using namespace std;
int n,m,w;
#define INF 987654321
vector<pair<int,pair<int,int>>> e;
int d[501]={};
int ans=0;
bool Bford(int start){
    d[start]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<e.size();j++){
            int cur=e[j].first;
            int to=e[j].second.first;
            int cost=e[j].second.second;

            if(d[cur]==INF)continue;

            if(cost+d[cur]<d[to]){
                d[to]=cost+d[cur];
                if(i==n)return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        ans=0;
        cin>>n>>m>>w;

        for(int j=0;j<m;j++){
            int n1,n2,n3;
            cin>>n1>>n2>>n3;
            e.push_back({n1,{n2,n3}});
            e.push_back({n2,{n1,n3}});
        }
        for(int j=0;j<w;j++){
            int n1,n2,n3;
            cin>>n1>>n2>>n3;
            e.push_back({n1,{n2,-n3}});
        }
        for(int j=1;j<=n;j++){
            d[i]=INF;
        }
        if(Bford(n)) cout<<"YES\n";
        else cout<<"NO\n";
        e.clear();
    }


    return 0;
}
