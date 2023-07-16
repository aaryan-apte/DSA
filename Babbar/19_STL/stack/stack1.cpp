#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> st;
    st.push("Jay Shree Ram!");
    st.push("Jay Shree Vaman!");
    st.push("Jay Shree Nrsimha!");
    st.push("Jay Shree Balram!");
    st.push("Jay Shree Krishna!");
    cout << endl
         << st.size() << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl; // NOthin to print!

    cout << st.size();

    return 0;
}

// 5
// Jay Shree Krishna!
// Jay Shree Balram!
// 4