#ifndef Class_h
#define Class_h 1

#include <iostream>
#include <string.h>

using namespace std;

class Frog
{
public:
        Frog(){};

        Frog(string color, string sound);

        Frog(string color, string sound, int velocity, int hopDist);

        void setvelocity(int velocity);

        Frog *sethopDist(int hopDist);

        Frog &sethopDist2(int hopDist);

        Frog(Frog &var);

        ~Frog();

        void show();

        bool equals(Frog &var);

protected:
private:
        static int FrogCounter;
        string color;
        string sound;
        int velocity;
        int hopDist;
};

#endif