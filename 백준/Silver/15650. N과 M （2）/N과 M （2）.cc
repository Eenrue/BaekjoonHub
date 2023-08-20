#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
void pr(int k, int cnt){
    if(cnt==0){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=k;i<=n;i++){
        v.push_back(i);
        pr(i+1,cnt-1);
        v.erase(v.end()-1);
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    pr(1,m);

    return 0;
}