#include <iostream>
#include <array>

using namespace std;

void funTab(const std::array<int, 4> tab)
{

    cout << "Size of array:" << tab.size() << endl
         << "Elements:" << endl;
    ;
    for (int i = 0; i < tab.size(); i++)
    {
        cout << tab[i] << endl;
    }
}

int main()
{
    std::array<int, 4> tab_A = {10, 20, 30, 40};
    std::array<int, 4> tab_B = tab_A;

    funTab(tab_B);
    return 1;
}