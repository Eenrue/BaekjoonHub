#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int par[201];
int n,m;

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
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        par[i]=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tmp;
            cin>>tmp;
            if(tmp==1)Union(i,j);
        }
    }
    vector<int> v;
    string ans="YES";
    for(int i=0;i<m;i++){
        int inp;
        cin>>inp;
        v.push_back(inp);
        if(v.size()>1){
            if(find(v[i])!=find(v[i-1])){
                ans="NO";
            }
        }
    }
    cout<<ans;

}
