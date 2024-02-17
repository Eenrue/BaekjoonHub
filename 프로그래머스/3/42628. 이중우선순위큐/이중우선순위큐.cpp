#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int,vector<int>,greater<int>> minpq;
    priority_queue<int> maxpq;
    map<int,int> mp;
    for(int i=0;i<operations.size();i++){
        string op=operations[i];
        int num=stoi(op.substr(2));
        
        if(op[0]=='I'){
            minpq.push(num);
            maxpq.push(num);
            mp[num]++;
            
        }
        else if(op[0]=='D'){
            if(minpq.empty())continue;
            if(num==1)mp[maxpq.top()]--;
            else if(num==-1)mp[minpq.top()]--;
            while(!minpq.empty()){
                if(mp[minpq.top()]!=0)break;
                minpq.pop();
            }
            while(!maxpq.empty()){
                if(mp[maxpq.top()]!=0)break;
                maxpq.pop();
            }
        }
    }
    if(minpq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(maxpq.top());
        answer.push_back(minpq.top());
    }
    return answer;
}