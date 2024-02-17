#include <bits/stdc++.h>
using namespace std;
int k=0;
bool vis[8]={};
set<int> s;
string str="";
bool check(int n){
    if(n==1||n==0)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}

void dfs(string num){
    if(num!=""){
        if(check(stoi(num)))s.insert(stoi(num));
    }
    for(int i=0;i<str.size();i++){
        if(vis[i])continue;
        vis[i]=true;
        dfs(num+str[i]);
        vis[i]=false;
    }
}

int solution(string numbers) {
    str=numbers;
    dfs("");
    return s.size();
}