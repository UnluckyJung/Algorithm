#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int price, count, money;
    cin >> price >> count >> money;

    if (money < price * count)
    {
        cout << price * count - money;
    }
    else
    {
        cout << 0;
    }

    return 0;
}