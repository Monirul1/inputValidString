#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str);

int main ()
{
    string str;
    
    cout << "Enter a string: ";
    cin >> str;
    if(isValid(str) == 0)
        cout << "The string is not valid" << endl;
    else
        cout << "The string is valid" << endl;
    
    return 0;
}

bool isValid(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i ++) {
        if((str[i] == '(') || (str[i] == '[') || (str[i] == '{'))
            st.push(str[i]);
        else
        {
            char top = st.top();
            
            if(str[i] == ')')
            {
                if(top != '(')
                    return false;
            }
            else if(str[i] == ']')
            {
                if(top != '[')
                    return false;
            }
            else if(str[i] == '}')
            {
                if(top != '{')
                    return false;
            }
            else if (st.size() == 0)
            {
                return false;
            }
            st.pop();
        }
    }
    return st.size() == 0; 
}

/*
 Sample run 1:
 Enter a string: ()
 The string is valid
 Program ended with exit code: 0
 
 Sample run 2:
 
 Enter a string: [
 The string is not valid
 Program ended with exit code: 0
 
 */

