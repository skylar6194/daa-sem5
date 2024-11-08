#include <iostream>
using namespace std;
int power(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }

    int temp = power(x, y / 2);
    if (y % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        return x * temp * temp;
    }
}
int main()
{
    int num, exp;
    cout << "Enter the number whose power you want to find:\n";
    cin >> num;
    cout << "Enter the power you want to find:\n";
    cin >> exp;
    cout << "The result is: " << power(num, exp);
    return 0;
}