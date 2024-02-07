#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0;i<progresses.size();i++){
        int progress=progresses[i];
        int speed=speeds[i];
        int k;
        if((100-progress)%speed==0)k=(100-progress)/speed;
        else k=(100-progress)/speed+1;
        if(q.size()==0)q.push(k);
        else if(k<=q.front())q.push(k);
        else{
            answer.push_back(q.size());
            while(!q.empty())q.pop();
            q.push(k);
        }
    }
    if(!q.empty())answer.push_back(q.size());
    
    
    return answer;
}