#include <bits/stdc++.h>

using namespace std;

vector<string> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string,int> map1;
    int n,m; cin >> n >> m;

    for(int i=1;i<n+1;i++){
        string inp;
        cin>>inp;
        map1[inp]++;
    }
    for(int i=0;i<m;i++){
        string inp;
        cin>>inp;
        if(map1.find(inp)!=map1.end()){
            ans.push_back(inp);
        }
    }

    cout<<ans.size()<<'\n';
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<'\n';
    }

    return 0;
}