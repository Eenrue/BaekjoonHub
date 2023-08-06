#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;

bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }

    else return p1.second<p2.second;
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++){
        int inp1,inp2;
        cin>>inp1>>inp2;
        v.push_back({inp1,inp2});
    }
    sort(v.begin(),v.end(),cmp);


    int ans=0;
    int e=0;
    for(int i=0;i<v.size();i++){
        if(v[i].first<e) continue;
        ans++;
        e=v[i].second;
    }
    cout<<ans;
}
