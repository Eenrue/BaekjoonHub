#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int t,n,k,tar;
int w[1001];
int maxw[1001];
int deg[1001];
int ans=0;


void tsort(vector<int> v[1001]){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0)q.push(i);
    }
    for(int i=0;i<n;i++){
        if(q.empty()) break;
        int cur=q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next=v[cur][i];
            maxw[next]=max(maxw[next],maxw[cur]+w[next]);
            if(--deg[next]==0) q.push(next);

        }
    }

}

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>t;
    for(int i=0;i<t;i++){
        ans=0;
        cin>>n>>k;
        fill_n(deg,1001,0);
        vector<int> v[1001];
        for(int j=1;j<=n;j++){
            cin>>w[j];
        }
        for(int j=0;j<k;j++){
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            v[tmp1].push_back(tmp2);
            deg[tmp2]++;
        }
        cin>>tar;
        fill_n(maxw,1001,0);


        for(int j=1;j<=n;j++){
            maxw[j]=w[j];
        }
        tsort(v);
        cout<<maxw[tar]<<'\n';
    }


}
