#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s ;
    stack<char> st;
    bool ans =false; 
    cin>>s;
    for(int i = 0 ; i<s.size() ; i++){
        if(s[i]  == '+' or s[i] == '-' or s[i] == '*' or s[i]=='/'){
            st.push(s[i]);
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.top() == '('){
                ans = true; 
            }
            if(st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/'){
                st.pop();
            }
            st.pop() ;
        }
    }
    cout<<ans ;
return 0;
}