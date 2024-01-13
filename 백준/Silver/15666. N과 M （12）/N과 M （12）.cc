#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int n,m;
vector<int> v;
vector<int> res;

void dfs(int k,int cnt){

    if(cnt==m){
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    int tmp=-1;
    for(int i=k;i<n;i++){
        if(v[i]==tmp){
            continue;
        }
        tmp=v[i];
        res.push_back(v[i]);
        dfs(i,cnt+1);
        res.pop_back();
    }

}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    dfs(0,0);
}
