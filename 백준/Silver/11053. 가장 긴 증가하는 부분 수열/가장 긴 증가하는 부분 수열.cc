#include <bits/stdc++.h>
using namespace std;
int tmp;
bool cmp(int a, int b){
    if(a>b)return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        vector<int> tv;
        for(int j=0;j<v.size();j++){
            if(v[j].first<tmp)tv.push_back(v[j].second);
        }
        if(tv.size()){
            sort(tv.begin(),tv.end(),cmp);
            v.push_back({tmp,tv[0]+1});
        }
        else v.push_back({tmp,1});
        if(v.back().second>ans) ans=v.back().second;
    }
    cout<<ans;
    return 0;
}