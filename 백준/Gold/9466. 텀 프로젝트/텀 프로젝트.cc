#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int mp[100001];
bool vis[100001];
bool done[100001];
int cyc=0;
void check(int k){
    if(done[k])return;
    if(!vis[k]){
        vis[k]=true;
        check(mp[k]);

    }
    else{
        cyc++;
        for(int i=mp[k];i!=k;i=mp[i]){
            cyc++;
        }
    }
    //cout<<'s';
    done[k]=true;
}

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> v;
        cyc=0;
        for(int j=1;j<=n;j++){
            int tmp;
            cin>>tmp;
            mp[j]=tmp;
        }
        for(int j=1;j<=n;j++){
            check(j);
        }
        cout<<n-cyc<<'\n';
        memset(vis,0,sizeof(vis));
        memset(done,0,sizeof(done));
    }
}
