#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        deque<char> dq;
        string ans="YES";
        for(int j=0;j<str.size();j++){
            if(str[j]==')'){
                if(!dq.empty()){
                    dq.pop_front();
                }
                else{
                    ans="NO";
                    break;
                }
            }
            else dq.push_back(str[j]);
        }
        if(!dq.empty()) ans="NO";
        cout<<ans<<'\n';

    }

}
