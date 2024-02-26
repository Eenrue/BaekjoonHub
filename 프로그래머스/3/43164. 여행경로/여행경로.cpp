#include <string>
#include <vector>
using namespace std;
map<string,vector<string>> mp;
int flag=false;

vector<string> solution(vector<vector<string>> t) {
    vector<string> answer;
    sort(t.begin(),t.end());
    for(int i=0;i<t.size();i++){
        mp[t[i][0]].push_back(t[i][1]);
    }
    for(auto iter=mp.begin();iter!=mp.end();iter++){
        string str=iter->first;
    }
    return answer;
}