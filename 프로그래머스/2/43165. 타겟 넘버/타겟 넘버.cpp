#include <string>
#include <vector>

using namespace std;
int answer = 0;
void dfs(vector<int> &v,int &t,int num, int cnt){
    if(cnt==v.size()){
        if(num==t) answer++;
        return;
    }
    dfs(v,t,num+v[cnt],cnt+1);
    dfs(v,t,num-v[cnt],cnt+1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers,target,0,0);
    
    return answer;
}