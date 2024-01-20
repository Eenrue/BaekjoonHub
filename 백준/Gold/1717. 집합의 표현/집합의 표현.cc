#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int par[1000001];
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
    
    for(int i=0;i<m;i++){
        int tmp,x,y;
        cin>>tmp>>x>>y;
        if(tmp==0){
            Union(x,y);
        }
        else if(tmp==1){
            if(find(x)==find(y)){
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
    }

}
