#include <iostream>
#include <deque>

using namespace std;

struct myDeq
{
    deque<int> dFront;
    deque<int> dBack;

    void balance() {
        if (dFront.size() > dBack.size() + 1) {
            dBack.push_front(dFront.back());
            dFront.pop_back();
        }
        else if (dBack.size() > dFront.size()) {
            dFront.push_back(dBack.front());
            dBack.pop_front();
        }
    }

    void push_back(int x) {
        dBack.push_back(x);
        balance();
    }

    void push_vip(int x) {
        if ((dFront.size() + dBack.size()) % 2 == 0)
            dFront.push_back(x);
        else
            dBack.push_front(x);
        balance();
    }

    void pop_front() {
        if (!dFront.empty())
        {
            cout << dFront.front() << "\n";
            dFront.pop_front();
        }
        else if (!dBack.empty())
        {
            cout << dBack.front() << "\n";
            dBack.pop_front();
        }

        balance();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    myDeq deq;
    int n; cin >> n;
    char c;
    while (n--)
    {
        cin >> c;
        if (c == '+') {
            int x; cin >> x;
            deq.push_back(x);
        }
        else if (c == '*') {
            int x; cin >> x;
            deq.push_vip(x);
        }
        else {
            deq.pop_front();
        }
    }
    return 0;
}