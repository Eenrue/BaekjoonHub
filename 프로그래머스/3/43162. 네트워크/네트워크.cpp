#include <string>
#include <vector>

using namespace std;
vector<vector<int>> comp;
bool visit[201]={};

void dfs(int n, int num){
    visit[num]=true;
    for(int i=0;i<n;i++){
        if(comp[num][i]==1&&visit[i]==false){
            dfs(n,i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    comp=computers;
    for(int i=0;i<n;i++){
        if(visit[i]==false){
            dfs(n,i);
            answer++;
        }
    }
    
    return answer;
}