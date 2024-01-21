#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

vector<int> v[32001];
bool vis[32001];
int n,m;

void Find(int k){
    vis[k]=true;
    if(v[k].size()==0){
        cout<<k<<" ";
    }
    else{
        for(int i=0;i<v[k].size();i++){
            int num=v[k][i];
            if(!vis[num]){
                Find(num);

            }
        }
        cout<<k<<" ";
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        Find(i);

    }
}
