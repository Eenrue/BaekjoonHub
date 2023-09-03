#include <bits/stdc++.h>
using namespace std;

int n,m;
int num[9]={};
vector<vector<int>> v;
int tmp[9]={};
bool vis[9]={};

void cal(int cnt){
    if(cnt==m){
        vector<int> tmpv;
        for(int i=0;i<m;i++){
            tmpv.push_back(tmp[i]);
        }
        v.push_back(tmpv);
    }
    for(int i=0;i<n;i++){
        if(vis[i])continue;
        vis[i]=true;
        tmp[cnt]=num[i];
        cal(cnt+1);
        vis[i]=false;
    }
}


int main()
{

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    cal(0);
    sort(v.begin(),v.end());

    vector<int> tmp;
    for(int i=0;i<v.size();i++){

        if(i>0){
            if(tmp==v[i]) continue;
        }
        tmp=v[i];
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<' ';
        }
        cout<<'\n';
    }


    return 0;
}