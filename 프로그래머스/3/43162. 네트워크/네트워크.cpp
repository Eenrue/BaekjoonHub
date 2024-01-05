#include <string>
#include <vector>

using namespace std;
bool visit[201]={};

void dfs(int n, int num,vector<vector<int>> &comp){
    visit[num]=true;
    for(int i=0;i<n;i++){
        if(comp[num][i]==1&&visit[i]==false){
            dfs(n,i,comp);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(visit[i]==false){
            dfs(n,i,computers);
            answer++;
        }
    }
    
    return answer;
}