#include <bits/stdc++.h>
using namespace std;
int n,m;
int mp[51][51]={};
int h,c;
vector<pair<int,int>> chi;
vector<pair<int,int>> hou;
int mi;
vector<int> dis[2500]; // dis[ith chick][ith house]
bool vis[2500]; // shows dis[ith house]


void cal(int cnt,int ind){
    if(cnt==m){
        int tmp[2500]={};
        for(int i=0;i<c;i++){
            if(vis[i]==true){
                for(int j=0;j<h;j++){
                    if(tmp[j]==0||dis[i][j]<tmp[j]) tmp[j]=dis[i][j];
                }
            }
        }
        int res=0;
        for(int j=0;j<h;j++) res+=tmp[j];
        if(mi==0)mi=res;
        else mi=min(mi,res);
        return;
    }

    for(int i=ind;i<c;i++){
        vis[i]=true;
        cal(cnt+1,i+1);
        vis[i]=false;
    }

}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    h=0;
    c=0;
    mi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mp[i][j];
            if(mp[i][j]==1){
                h++;
                hou.push_back({i,j});
            }
            if(mp[i][j]==2){
                c++;
                chi.push_back({i,j});
            }
        }
    }
    for(int i=0;i<c;i++){
        int y=chi[i].first;
        int x=chi[i].second;
        for(int j=0;j<h;j++){
            int hy=hou[j].first;
            int hx=hou[j].second;
            int tmp=abs(y-hy)+abs(x-hx);
            dis[i].push_back(tmp);
        }

    }


    cal(0,0);
    cout<<mi;
    return 0;
}
