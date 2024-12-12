#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " "; 1 2 3 4 ;
    }
    for (auto i : s)
    {
        cout << i << endl; 1 2  3 4;
    }

    for (auto i = s.rbegin(); i != s.rend(); i++)
    {
        cout << *i << endl; 4 3 2 1 ;
    }
    cout<<s.size(); ->3;

    cout<<*s.lower_bound(1)<<" "; 
    //  1 2 4 4
    cout<<*s.lower_bound(2)<<" ";
    cout<<*s.upper_bound(3)<<" ";
    cout<<*s.upper_bound(6)<<" ";
    s.erase(2);
    s.erase(s.begin()); 
    // 2 and begin element will delete 
}

