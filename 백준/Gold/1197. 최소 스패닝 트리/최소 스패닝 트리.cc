#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int par[10001];
int v,e;
vector<pair<int,pair<int,int>>> vec;

int find(int x){
    if(x==par[x])return x;
    return par[x]=find(par[x]);
}

void Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    par[y]=x;
}

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>v>>e;
    for(int i=1;i<=v;i++){
        par[i]=i;
    }
    for(int i=0;i<e;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        vec.push_back({t3,{t1,t2}});
    }
    sort(vec.begin(),vec.end());
    int cnt=0;
    int ans=0;
    for(int i=0;i<e;i++){

        int w=vec[i].first;
        int n1=vec[i].second.first;
        int n2=vec[i].second.second;
        if(find(n1)==find(n2))continue;
        ans+=w;
        cnt++;
        Union(n1,n2);
        if(cnt==v-1)break;

    }
    cout<<ans;
}
