#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;



int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    vector<pair<int,int>> rv;
    rv.push_back(v[0]);
    for(int i=1;i<v.size();i++){
        int ep=rv[rv.size()-1].second;
        if(v[i].first<ep){
            if(v[i].second>ep){
                rv[rv.size()-1].second=v[i].second;
            }
        }
        else{
            rv.push_back(v[i]);
        }
    }
    int ans=0;
    for(int i=0;i<rv.size();i++){
        ans+=rv[i].second-rv[i].first;
    }
    cout<<ans;
}
