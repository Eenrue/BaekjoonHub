#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321
int n;
vector<int> v[501];
int t[501];
int mt[501];
int indeg[501]={};

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        t[i]=tmp;
        while(1){
            cin>>tmp;
            if(tmp==-1)break;
            v[tmp].push_back(i);
            indeg[i]++;
        }
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            mt[i]=t[i];
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur=q.front();
        //cout<<'s';
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next=v[cur][i];
            mt[next]=max(mt[next],mt[cur]+t[next]);
            if(--indeg[next]==0)q.push(next);
        }
    }
    for(int i=1;i<=n;i++)cout<<mt[i]<<'\n';
}
