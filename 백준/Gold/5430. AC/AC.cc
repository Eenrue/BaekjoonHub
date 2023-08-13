#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> q;
string str;

void cal(){
    int flag=0;
    int rev=0;
    char fun;
    for(int i=0;i<str.size();i++){
        if(flag) break;
        fun=str[i];
        if(fun=='R'){
            rev=rev^1;
        }
        else if(fun=='D'){
            if(q.size()==0){
                flag=1;
                continue;
            }
            if(rev) q.pop_back();
            else q.pop_front();
        }
    }
    if(flag) cout<<"error\n";
    else{
       cout<<"[";
       if(rev){
            while(q.size()){
                cout<<q.back();
                q.pop_back();
                if(q.size()) cout<<",";
            }
       }
       else{
            while(q.size()){
                cout<<q.front();
                q.pop_front();
                if(q.size()) cout<<",";
            }
        }
        cout<<"]\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        str.clear();
        q.clear();
        cin >> str;
        cin>>n;
        string num;
        cin>>num;
        string tmps="";
        for(int j=0;j<num.size();j++){
            if(n==0) break;
            if('0'<=num[j]&&num[j]<='9') tmps+=num[j];
            if(num[j]==','||num[j]==']') {
                    q.push_back(stoi(tmps));
                    tmps="";
            }
        }
        cal();
    }
}
