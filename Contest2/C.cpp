# include <iostream>
# include <stack>
# include <string>
# include <sstream>


using namespace std;


int main()
{
    string s;
    getline(cin, s);

    stringstream ss(s);

    stack<int>num;

    string podString;
    while (ss >> podString) {

        if (isdigit(podString[0]) || (podString[0] == '-' && podString.length() > 1))
            num.push(stoi(podString));
        else
        {
            int op2 = num.top(); num.pop();
            int op1 = num.top(); num.pop();

            switch (podString[0])
            {
            case '+':
                num.push(op1 + op2);
                break;
            case '-':
                num.push(op1 - op2);
                break;
            case '*':
                num.push(op1 * op2);
                break;
            }
        }
    }
    cout << num.top();
    return 0;
}