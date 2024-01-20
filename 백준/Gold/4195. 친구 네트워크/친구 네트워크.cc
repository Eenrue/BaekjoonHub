#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int par[200003];
int cnt[200003];
int n;

int find(int x){
    if(x==par[x])return x;
    return par[x]=find(par[x]);
}

void Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    par[y]=x;
    cnt[x]+=cnt[y];
}

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int ind=1;
        map<string,int> mp;
        for(int j=1;j<=2*n;j++){
            par[j]=j;
            cnt[j]=1;
        }
        for(int j=0;j<n;j++){
            string p1,p2;
            cin>>p1>>p2;
            if(mp.find(p1)==mp.end()){
                mp[p1]=ind;
                ind++;
            }
            if(mp.find(p2)==mp.end()){
                mp[p2]=ind;
                ind++;
            }
            Union(mp[p1],mp[p2]);
            cout<<cnt[find(mp[p1])]<<'\n';
        }
    }


}
