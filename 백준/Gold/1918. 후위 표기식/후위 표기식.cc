#include <bits/stdc++.h>
using namespace std;

string str;

int main()
{

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>str;

    stack<char> st;
    int flag=0;

    for(int i=0;i<str.size();i++){
        char c=str[i];
        if(c>='A'&&c<='Z'){
            cout<<c;
            continue;
        }

        if(c==')'){
            while(st.top()!='('){
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }

        if(c=='*'||c=='/'||c=='+'||c=='-'||c=='('){
            char tmp=c;
            while(!st.empty()){
                int tmp2=st.top();
                if(c=='(')break;
                if(tmp2=='+'||tmp2=='-'){
                    if(c=='*'||c=='/')break;
                }
                if(st.top()=='('){
                    break;
                    }
                cout<<st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }

    return 0;
}
