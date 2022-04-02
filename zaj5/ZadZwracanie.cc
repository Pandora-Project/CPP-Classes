#include <iostream>

using namespace std;

void funVar(int a)
{
    a = a * 2;
}

void funWsk(int *a)
{
    *a = *a * 3;
}

void funRef(int &a)
{
    a = a * 4;
}

void funTab(int tab[])
{
    for (int i = 0; i < 3; i++)
    {
        tab[i] = tab[i] * 2;
    }
}

int main()
{
    int a = 2;
    int *a_value = &a;
    cout << "Wartość a:" << a << endl;
    funVar(a);
    cout << "Wartość a:" << a << endl;
    funRef(a);
    cout << "Wartość a:" << a << endl;
    funWsk(a_value);
    cout << "Wartość a:" << a << endl;

    int tab[] = {2, 2, 2};
    funTab(tab);
    for (int i = 0; i < 3; i++)
    {
        cout << tab[i] << endl;
    }
    cout << endl;
    return 1;
}