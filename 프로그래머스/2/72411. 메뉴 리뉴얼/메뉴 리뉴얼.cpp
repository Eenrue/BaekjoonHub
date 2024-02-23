#include <bits/stdc++.h>

using namespace std;
map<string,int> mp;

void dfs(string str, int k,int ind, string tstr){
    if(tstr.size()==k){
        mp[tstr]++;
    }
    
    for(int i=ind;i<str.size();i++){
        dfs(str,k,i+1,tstr+str[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i:course){
        for(int j=0;j<orders.size();j++){
            string str=orders[j];
            sort(str.begin(),str.end());
            dfs(str,i,0,"");
        }
        int mx=0;
        for(auto iter=mp.begin();iter!=mp.end();iter++){
            mx=max(mx,iter->second);
        }
        if(mx<2)continue;
        //cout<<mx<<'s';
        for(auto iter=mp.begin();iter!=mp.end();iter++){
            if(iter->second==mx){
                answer.push_back(iter->first);
            }
        }
        mp.clear();
    }
    sort(answer.begin(),answer.end());
    return answer;
}