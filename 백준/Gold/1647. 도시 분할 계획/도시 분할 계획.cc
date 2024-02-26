#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int par[100001];
vector<pair<int,pair<int,int>>> v;


int find(int x){
    if(x==par[x])return x;
    return par[x]=find(par[x]);
}

void Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    par[y]=x;
}


int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        par[i]=i;
    }
    for(int i=0;i<m;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        v.push_back({t3,{t1,t2}});
    }
    sort(v.begin(),v.end());
    int cnt=0;
    int ans=0;
    int mx=0;
    for(int i=0;i<m;i++){
        int w=v[i].first;
        mx=max(mx,w);
        int n1=v[i].second.first;
        int n2=v[i].second.second;
        if(find(n1)==find(n2))continue;
        Union(n1,n2);
        cnt++;
        ans+=w;
        if(cnt==n-1)break;
    }
    cout<<ans-mx;
}
