#include <bits/stdc++.h>
using namespace std;
int k=0;
int ans=0;
deque<int> aq;
int mem[100003]={0,};

int bfs(int x) {
    deque<pair<int,int>> q;
    q.push_back({x,0});
	if(x==k) return 0;
	while(1){
        int num=q.front().first;
        if(num==k)return q.front().second;
        int cnt=q.front().second;
        q.pop_front();
        if(num*2<=100000){
                if(!mem[num*2]) q.push_back({num*2,cnt+1});
                mem[num*2]=1;
        }
        if(num+1<=100000){
                if(!mem[num+1]) q.push_back({num+1,cnt+1});
                mem[num+1]=1;
        }
        if(num-1>=0){
                if(!mem[num-1]) q.push_back({num-1,cnt+1});
                mem[num-1]=1;
        }
    }
}

int main() {
	int n;
	cin >> n>>k;
	mem[n]=1;
	cout<<bfs(n);
	return 0;
}
