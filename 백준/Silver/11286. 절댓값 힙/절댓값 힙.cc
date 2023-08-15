#include <bits/stdc++.h>
using namespace std;


struct cmp{
    bool operator()(int i, int j){
        if(abs(i)==abs(j)) return i>j;
        else return abs(i)>abs(j);
    }
};

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    priority_queue<int,vector<int>,cmp> pq;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp==0){
            if(pq.empty()){
                cout<<"0\n";
                continue;
            }
            cout<<pq.top()<<'\n';
            pq.pop();
        }
        else pq.push(tmp);
    }

    return 0;
}
