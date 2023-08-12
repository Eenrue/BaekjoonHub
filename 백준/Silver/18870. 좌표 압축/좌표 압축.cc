#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin>>n;
    vector<int> v;
    vector<int> uv;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
        uv.push_back(tmp);
    }
    sort(uv.begin(),uv.end());
    unique(uv.begin(),uv.end());

    map<int,int> m;
    for(int i=0;i<uv.size();i++){
        m.insert({uv[i],i});
    }

    for(int i=0;i<n;i++){
        cout<<m[v[i]]<<' ';
    }
}
