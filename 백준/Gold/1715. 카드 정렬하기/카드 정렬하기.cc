#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int n;
priority_queue<int,vector<int>,greater<int>> pq;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        pq.push(tmp);
    }
    int ans=0;
    while(pq.size()!=1){
        int t1=pq.top();
        pq.pop();
        int t2=pq.top();
        pq.pop();
        int t3=t1+t2;
        ans+=t3;
        pq.push(t3);
    }
    cout<<ans;
}
