#include <iostream>

using namespace std;

void funTab(int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        tab[i] = tab[i] * 2;
    }
}

int main()
{
    int tab[] = {2, 2, 2};
    int tabSize = sizeof(tab) / sizeof(tab[0]);
    funTab(tab, tabSize);

    for (int i = 0; i < 3; i++)
    {
        cout << tab[i] << endl;
    }
    cout << endl;
    return 1;
}