#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1001];
int res;
int tmps[1001];
vector<int> v[27];
bool b[27];

void check(int x){
    int tmp;
    if(x==0){
        tmp=1;
    }
    else{
        tmp=dp[x-1]+1;
    }
    for(int i=x;i<n;i++){
        if(tmp>dp[i]){
            tmps[i]=tmp;
        }
        else break;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    res=0;
    string str1,str2;
    cin>>str1>>str2;
    n=str1.size();
    for(int i=0;i<str2.size();i++){
        char c;
        c=str2[i];
        int ic=int(c-'A');
        if(b[ic]){
            for(int j=0;j<v[ic].size();j++){
                check(v[ic][j]);
            }
        }
        else{
            b[ic]=true;
            for(int j=0;j<n;j++){
                if(c==str1[j]){
                check(j);
                    v[ic].push_back(j);
                }
            }
        }
        for(int j=0;j<n;j++){
            dp[j]=tmps[j];
        }
    }
    res=dp[n-1];
    cout<<res;
    return 0;
}