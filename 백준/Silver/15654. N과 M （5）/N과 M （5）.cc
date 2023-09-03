#include <bits/stdc++.h>
using namespace std;

int n,m;
bool vis[9]={};
vector<int> num;
vector<vector<int>> v;
vector<int> tmp;

void cal1(int cnt){
    if(cnt==m){
        v.push_back(tmp);
        return;
    }

    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        tmp.push_back(num[i]);
        vis[i]=true;
        cal1(cnt+1);
        vis[i]=false;
        tmp.erase(tmp.end()-1);
    }
}



int main()
{

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        num.push_back(tmp);
    }
    sort(num.begin(),num.end());
    cal1(0);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
