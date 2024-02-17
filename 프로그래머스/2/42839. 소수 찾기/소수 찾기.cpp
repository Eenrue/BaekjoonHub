#include <bits/stdc++.h>
using namespace std;
int k=0;
bool vis[8]={};
map <int,int> mp;
string tmp="";
string str="";
bool check(int n){
    if(n==1||n==0)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}

void dfs(int len,int cnt){
    if(cnt==len){
        if(mp[stoi(tmp)]!=0)return;
        mp[stoi(tmp)]++;
        cout<<tmp<<' ';
        if(check(stoi(tmp)))k++;
        return;
    }
    for(int i=0;i<str.size();i++){
        if(vis[i])continue;
        vis[i]=true;
        tmp+=str[i];
        dfs(len,cnt+1);
        tmp=tmp.substr(0,cnt);
        vis[i]=false;
    }
}

int solution(string numbers) {
    str=numbers;
    for(int i=1;i<=numbers.size();i++){
        dfs(i,0);
    }
    return k;
}