#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int i=0;
    queue<int> q;
    int tmp=0;
    for(int i=0;i<bridge_length;i++) q.push(0);
    
    while(i<truck_weights.size()){
        while(tmp-q.front()+truck_weights[i]>weight){
            tmp-=q.front();
            q.pop();
            q.push(0);
            answer++;
        }
        tmp-=q.front();
        q.pop();
        q.push(truck_weights[i]);
        tmp+=truck_weights[i];
        answer++;
        i++;
    }
    while(tmp!=0){
        tmp-=q.front();
        q.pop();
        q.push(0);
        answer++;
    }
    return answer;
}