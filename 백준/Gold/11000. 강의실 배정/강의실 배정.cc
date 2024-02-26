#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int n;
vector<vector<int>> v;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int t1,t2;
        cin>>t1>>t2;
        v.push_back({t1,t2});
    }
    sort(v.begin(),v.end());
    int ans=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(v[0][1]);
    ans++;
    for(int i=1;i<n;i++){
        int tmp=pq.top();
        if(tmp<=v[i][0]){
            pq.pop();
            pq.push(v[i][1]);
        }
        else{
            ans++;
            pq.push(v[i][1]);
        }
    }
    cout<<ans;
}