#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int n,m;
vector<int> v;
vector<int> res;

void dfs(int k,int cnt){
    if(k==m){
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(i<cnt) continue;
        res.push_back(v[i]);
        dfs(k+1,i);
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

    return 0;
}
