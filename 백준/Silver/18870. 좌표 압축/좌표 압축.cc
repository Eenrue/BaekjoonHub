#include <bits/stdc++.h>
using namespace std;

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
    uv.erase(unique(uv.begin(),uv.end()),uv.end());

    for(int i=0;i<n;i++){
        cout<<lower_bound(uv.begin(),uv.end(),v[i])-uv.begin()<<' ';
    }
}
