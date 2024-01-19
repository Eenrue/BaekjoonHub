#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int dp[100001]={};
int res=0;
int rest=INF;
int n,k;

void bfs(){

    deque<pair<int,int>> dq;
    dq.push_back({n,0});
    while(!dq.empty()){
        //cout<<'s';
        int cur=dq.front().first;
        int cnt=dq.front().second;
        dq.pop_front();
        if(cnt>rest) continue;
        int flag=0;
        if(cur==k){
            if(cnt>rest){
                flag=1;
            }
            rest=cnt;
            res++;
        }
        if(flag==1)break;
        if(cur<100000&&cnt+1<=dp[cur+1]){
            dp[cur+1]=cnt+1;
            dq.push_back({cur+1,cnt+1});
        }
        if(cur>0&&cnt+1<=dp[cur-1]){
            dp[cur-1]=cnt+1;
            dq.push_back({cur-1,cnt+1});
        }
        if(cur*2<=100000&&cnt+1<=dp[cur*2]){
            dp[cur*2]=cnt+1;
            dq.push_back({cur*2,cnt+1});
        }
    }
}


int main()
{
    cin>>n>>k;
    for(int i=0;i<100001;i++){
        dp[i]=INF;
    }
    bfs();
    cout<<rest<<'\n'<<res;
}
