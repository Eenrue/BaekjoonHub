#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    while(!pq.empty()&&pq.top()<K){
        if(pq.size()==1){
            answer=-1;
            break;
        }
        answer++;
        int m1=pq.top();
        pq.pop();
        int m2=pq.top();
        pq.pop();
        pq.push(m1+m2*2);
    }
    return answer;
}