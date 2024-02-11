#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> v) {
    bool ph[21][10]={};
    bool answer = true;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++){
        bool flag=true;
        for(int j=0;j<min(v[i].size(),v[i+1].size());j++){
            if(v[i][j]!=v[i+1][j]){
                flag=false;
                break;
            }
        }
        if(flag)answer=false;
    }
    
    return answer;
}