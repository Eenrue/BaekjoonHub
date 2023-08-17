#include <bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int ans=0;
    int party[51][51]={}; // [person][party]
    int res[51]={};
    int vis[51]={};
    int n,m; //n person & m party
    cin>>n>>m;
    int k;
    cin>>k;
    vector<int> know;
    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        know.push_back(tmp);
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        for(int j=0;j<tmp;j++){
            int tmp2;
            cin>>tmp2;
            party[i][tmp2]=1;
        }
    }
    queue<int> q;
    for(int i=0;i<know.size();i++){
        q.push(know[i]);
        vis[know[i]]=1;
    }
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i=0;i<m;i++){
            if(party[i][p]==1&&res[i]==0){
                res[i]=1;
                for(int j=1;j<=n;j++){
                    if(party[i][j]==1&&!vis[j]){
                        q.push(j);
                        vis[j]=1;
                    }
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        if(res[i]==0){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}