#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    for(int i=2;i<n;i++){
        v.push_back((2*v[i-2]+v[i-1])%10007);
    }
    cout<<v[n-1];
    return 0;
}