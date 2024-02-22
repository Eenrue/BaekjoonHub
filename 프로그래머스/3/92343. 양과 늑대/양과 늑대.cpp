#include <string>
#include <vector>
using namespace std;
vector<int> v;
vector<vector<int>> e;
int ans=0;

void dfs(int cur, int par, int vis, int cnt0, int cnt1){
    ans=max(cnt0,ans);
    for(int i=0;i<e.size();i++){
        if(e[i][0]==cur){
            int next=e[i][1];
            if(par==next)continue;
            if((vis&(1<<next))==1<<next){
                dfs(next,cur,vis,cnt0,cnt1);
                continue;
            }
            if(v[next]==0){
                if(cnt0+1>cnt1){
                    dfs(next,cur,vis|1<<next,cnt0+1,cnt1);
                    dfs(cur,next,vis|1<<next,cnt0+1,cnt1);
                }
            }
            else if(v[next]==1){
                if(cnt0>cnt1+1)dfs(next,cur,vis|1<<next,cnt0,cnt1+1);
            }
        }
        if(e[i][1]==cur){
            int next=e[i][0];
            if(par==next)continue;
            if((vis&(1<<next))==1<<next){
                dfs(next,cur,vis,cnt0,cnt1);
                continue;
            }
            if(v[next]==0){
                if(cnt0+1>cnt1){
                    dfs(next,cur,vis|1<<next,cnt0+1,cnt1);
                    dfs(par,cur,vis|1<<next,cnt0+1,cnt1);
                }
            }
            else if(v[next]==1){
                if(cnt0>cnt1+1)dfs(next,cur,vis|1<<next,cnt0,cnt1+1);
            }
        }
    }
    
}


int solution(vector<int> info, vector<vector<int>> edges) {
    v=info;
    e=edges;
    int answer = 0;
    int tmp=1;
    dfs(0,0,tmp,1,0);
    return ans;
}