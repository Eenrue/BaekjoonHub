#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool islost[32]={};
    bool ishave[32]={};
    for(int i=0;i<lost.size();i++){
        islost[lost[i]]=true;
    }
    for(int i=0;i<reserve.size();i++){
        if(islost[reserve[i]]){
            islost[reserve[i]]=false;
            continue;
        };
        ishave[reserve[i]]=true;
    }
    for(int i=1;i<=n;i++){
        if(islost[i]){
            if(ishave[i-1]){
                //cout<<i<<'a';
                ishave[i-1]=false;
                answer++;
            }
            else if(ishave[i+1]){
                //cout<<i<<'b';

                ishave[i+1]=false;
                answer++;
            }
        }
        else answer++;
    }
    return answer;
}