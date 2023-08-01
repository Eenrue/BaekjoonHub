#include <bits/stdc++.h>
using namespace std;
int n;
int rel[101][101];
vector<int> a[101];
int keb(int num){
    deque<int> deq;
    int score[101]={0,};
    for(int i=1;i<=n;i++){
        if(rel[num][i]!=0)
        {
            score[i]=1;
            deq.push_back(i);
        }
    }

    int res=0;

    while(deq.size()){
        int fir=deq.front();
        deq.pop_front();
        for(int i=1;i<=n;i++){
            if(rel[fir][i]==1&&score[i]==0){
                score[i]=score[fir]+1;
                deq.push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        res+=score[i];
    }
    return res;
}


int main() {
	int m;
	cin>>n>>m;

	for(int i;i<m;i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        rel[tmp1][tmp2]=1;
        rel[tmp2][tmp1]=1;
	}

	int mi=keb(1);
	int ans=1;
	for(int i=1;i<=n;i++){
        if(mi>keb(i)){
            mi=keb(i);
            ans=i;
        }
	}

	cout<<ans;
}
