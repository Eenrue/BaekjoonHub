#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    ll lo=1;
    ll hi=*max_element(v.begin(),v.end());
    ll res=0;
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i]/mid;
        }
        if(sum<m){
            hi=mid-1;
        }
        else{
            res=mid;
            lo=mid+1;
        }
    }
    cout<<res;
}
