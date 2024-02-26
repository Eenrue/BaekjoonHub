#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> v;
bool vis[10001]={};
int flag=false;
int n;
vector<string> ans;

void dfs(vector<string> sv){
    if(sv.size()==n+1){
        flag=true;
        ans=sv;
        return;
    }
    string last=sv.back();
    for(int i=0;i<n;i++){
        if(flag)return;
        if(v[i][0]==last&&!vis[i]){
            string next=v[i][1];
            vis[i]=true;
            sv.push_back(next);
            dfs(sv);
            sv.pop_back();
            vis[i]=false;
        }
    }
    
}

vector<string> solution(vector<vector<string>> t) {
    vector<string> answer;
    n=t.size();
    sort(t.begin(),t.end());
    v=t;
    dfs({"ICN"});
    return ans;
}