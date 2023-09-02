#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[100001];
bool vis[100001];
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    map<int,int> m;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int n1,n2;
        cin>>n1>>n2;
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }

    queue<int> q;

    q.push(1);
    vis[1]=true;
    while(!q.empty()){
        int par=q.front();
        q.pop();
        for(int i=0;i<g[par].size();i++){
            int chi=g[par][i];
            if(!vis[chi]){
                vis[chi]=true;
                m[chi]=par;
                q.push(chi);
            }
        }
    }
    for(int i=2;i<=n;i++){
        cout<<m[i]<<'\n';
    }

    return 0;
}