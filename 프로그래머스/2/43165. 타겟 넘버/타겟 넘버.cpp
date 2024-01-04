#include <string>
#include <vector>

using namespace std;
int t=0;
int answer = 0;
vector<int> v;
void dfs(int num, int cnt){
    if(cnt==v.size()){
        if(num==t) answer++;
        return;
    }
    dfs(num+v[cnt],cnt+1);
    dfs(num-v[cnt],cnt+1);
}

int solution(vector<int> numbers, int target) {
    v=numbers;
    t=target;
    dfs(0,0);
    
    return answer;
}