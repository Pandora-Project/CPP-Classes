#include<iostream>

using namespace std;

extern "C" void HelloC()
{
    cout << "Hello World C" << endl;
}

extern "C" int PlusC(int num_one, int num_two)
{
    return num_one + num_two;
}

void HelloCPP()
{
    cout << "Hello World CPP" << endl;
}

int PlusCPP(int num_one, int num_two)
{
    return num_one + num_two;
}


int ans1;
int ans2;

void UserInput()
{
                cout << "Podaj pierwszą liczbę" << endl;
                cin >> ans1;

                cout << "Podaj drugą liczbę" << endl;
                cin >> ans2;
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++){
        int switch_arg = stoi(argv[i]);
        
        switch (switch_arg){
            case 1:
                HelloC();
                break;
            case 2:
                HelloCPP();
                break;

            case 3:
                UserInput();
                cout << PlusC(ans1, ans2) << endl;
                break;

            case 4:
                UserInput();
                cout << PlusCPP(ans1, ans2) << endl;
                break;

            default:
                cout << "Wrong argument" << endl;
        }
    }

}