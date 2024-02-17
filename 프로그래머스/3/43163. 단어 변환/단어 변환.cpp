#include <bits/stdc++.h>

using namespace std;
#define INF 987654321
int answer = INF;
map<string,int> vis;
vector<string> v;
int n,m;

void dfs(string b, string t, int cnt){
    vis[b]++;
    if(b==t)
    {
        answer=min(answer,cnt);
        vis[b]--;
        return;
    }
    for(int i=0;i<n;i++){
        if(vis[v[i]]>0)continue;
        int flag=0;
        for(int j=0;j<m;j++){
            if(v[i][j]==b[j])continue;
            flag++;
        }
        if(flag==1)dfs(v[i],t,cnt+1);
    }
    vis[b]--;
        
    
    
}


int solution(string begin, string target, vector<string> words) {
    n=words.size();
    m=words[0].size();
    v=words;
    int cnt=0;
    dfs(begin,target,cnt);
    if(answer==INF)answer=0;
    return answer;
}