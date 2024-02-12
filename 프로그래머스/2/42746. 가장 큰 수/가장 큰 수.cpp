#include <bits/stdc++.h>

using namespace std;

bool cmp(string a,string b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(auto num:numbers){
        v.push_back(to_string(num));
    }
    sort(v.begin(),v.end(),cmp);
    if(v[0]=="0")return "0";
    else{
        for(auto num:v){
            answer+=num;
        }
    }
    return answer;
}