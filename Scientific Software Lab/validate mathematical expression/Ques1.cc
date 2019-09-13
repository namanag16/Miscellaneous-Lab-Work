#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

bool validate_exp(char[]);

int main()
{
    char str[100];
    bool result;
    ifstream fin("input1.txt");
    fin.get(str,' ');
    cout << str << endl;
    result = validate_exp(str);
    if(result == false)
    cout << "expression is not valid" << endl;
    else
    cout << "expression is valid" << endl;
}

bool validate_exp(char str[])
{
    stack<char> my_stack;
    short i=0;
    char ch;
    while(str[i]!=0)
    {
        cout << i << endl;
        if(str[i]=='{' || str[i]=='[' || str[i]=='(')
        {

            cout << "inside opening brace" << str[i];
            my_stack.push(str[i]);
            i++;
        }
        else if(str[i]=='}' || str[i]==']' || str[i]==')')
        {
            cout << "inside closing  brace" << str[i] << my_stack.top();
            if(my_stack.empty()== false)
            {
                switch (str[i])
                {
                    case '}':
                                if(my_stack.top() == '{')
                                {
                                    cout << "doing good" << endl;
                                    my_stack.pop();
                                    i++;
                                    continue;
                                }
                                else
                                {
                                    cout << "problem" << endl;
                                    return false;
                                }
                    case ')':
                                if(my_stack.top() == '(')
                                {
                                    cout << "doing good" << endl;
                                    my_stack.pop();
                                    i++;
                                    continue;
                                }
                                else
                                {
                                    cout << "problem" << endl;
                                    return false;
                                }
                    case ']':
                                if(my_stack.top() == '[')
                                {
                                    cout << "doing good" << endl;
                                    my_stack.pop();
                                    i++;
                                    continue;
                                }
                                else
                                {
                                    cout << "problem" << endl;
                                    return false;
                                }
                }
            }
            else
            {
                cout << "got closing brace w/o a matching opening one" << endl;
                return false;
            }
        }
        else
        {
            cout << "continuing" << endl;
            i++;
            continue;
        }
    }
    return true;


}
