#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int n=0;
char c=0;
vector<int> v;

char s(int cnt){
    if(cnt==1)return 'm';
    if(cnt==2)return 'o';
    if(cnt==3)return 'o';
    for(int i=0;i<v.size();i++){
        if(v[i]<cnt&&v[i+1]>=cnt){
            if(cnt-v[i]==1)return 'm';
            if(cnt-v[i]<=i+4)return 'o';
            return s(cnt-v[i]-(i+4));
        }
    }

}

int main(){
    cin>>n;
    v.push_back(3);
    int k=4;
    while(n-1>=v[v.size()-1]){
        int tmp=v[v.size()-1]*2+k;
        v.push_back(tmp);
        k++;
    }

    cout<<s(n);
}
