#include <bits/stdc++.h>
using namespace std;

int n,m;
bool vis[9]={};
vector<int> num;
int res[9]={};

void cal1(int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout<<res[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        res[cnt]=num[i];
        vis[i]=true;
        cal1(cnt+1);
        vis[i]=false;
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

    return 0;
}
