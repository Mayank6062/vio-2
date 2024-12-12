#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> sq;
    sq.push_back(1);
    sq.push_back(2);
    sq.push_front(3);
    sq.push_front(4);
    for(auto i : sq){
        cout<<i<<endl;
    }
    sq.pop_back() ;
    sq.pop_front() ;
    for(auto i : sq){
        cout<<i<<endl;
    }

return 0;
}