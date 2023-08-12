#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int lo=0;
    int hi=*max_element(v.begin(),v.end());
    int res=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        long long int sum=0;
        for(int i=0;i<n;i++){
            if(mid<v[i]) sum+=v[i]-mid;
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
