#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int n;

int main(){
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int k=1;
    for(int i=0;i<v.size();i++){
        if(v[i]<=k)k+=v[i];
        else break;
    }
    cout<<k;
}
