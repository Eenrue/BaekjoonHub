#include <bits/stdc++.h>
using namespace std;


int mem[1002];

int cnt(int x){
    if(x==1) return 1;
    if(x==2) return 2;
    if(x>2){
        if(mem[x]) return mem[x];
        return mem[x]=(cnt(x-2)+cnt(x-1))%10007;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cnt(n);
    cout<<cnt(n);
}
