#include <bits/stdc++.h>
using namespace std;

map<string,int> imp;
map<string,int> mp;
priority_queue<pair<int,int>> pq[102];
priority_queue<pair<int,string>> tpq;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int ind=0;
    for(int i=0;i<genres.size();i++){
        if(imp[genres[i]]==0)imp[genres[i]]=++ind;
        mp[genres[i]]+=plays[i];
        pq[imp[genres[i]]].push({plays[i],-i});
    }
    for(auto iter=mp.begin();iter!=mp.end();iter++){
        tpq.push({iter->second,iter->first});
    }
    while(!tpq.empty()){
        string genre=tpq.top().second;
        tpq.pop();
        answer.push_back(-pq[imp[genre]].top().second);
        pq[imp[genre]].pop();
        if(!pq[imp[genre]].empty()){
            answer.push_back(-pq[imp[genre]].top().second);
        }
    }
    
    return answer;
}