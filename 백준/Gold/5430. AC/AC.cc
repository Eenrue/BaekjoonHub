#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        bool err=false;
        deque <int> arr;
        string cmd,input;
        cin>>cmd;
        cin>>n;
        cin>>input;
        string tmp="";
        if(n!=0){
            for(int j=0;j<input.length();j++){
                if(input[j]=='[' || input[j]==']' || input[j]==','){
                    if(input[j]!='[') arr.push_back(stoi(tmp));
                    tmp="";
                    continue;
                }
                tmp+=input[j];
            }
        }
        int rev = 1;
        for(int j=0;j<cmd.length();j++){
            if(cmd[j]=='R'){
                rev *= -1;
            }
            else{
                if(arr.size()==0) {
                    cout<<"error"<<"\n";
                    err=true;
                    break;
                }
                if(rev==1) arr.pop_front();
                else arr.pop_back();
            }
        }
        if(!err){
            cout<<"[";
            if(rev==1){
                while(!arr.empty()){
                    if(arr.size()!=1) cout<<arr.front()<<",";
                    else cout<<arr.front();
                    arr.pop_front();
                }
            }
            else{
                while(!arr.empty()){
                    if(arr.size()!=1) cout<<arr.back()<<",";
                    else cout<<arr.back();
                    arr.pop_back();
                }
            }
            cout<<"]\n";
        }
    }
    return 0;
}