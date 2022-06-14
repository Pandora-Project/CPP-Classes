#include "Class.h"
#include <iostream>
#include <string.h>

using namespace std;

Frog::Frog(string color, string sound)
{
    this->color = color;
    this->sound = sound;
    velocity = 0;
    hopDist = 0;
    FrogCounter++;
}

Frog::Frog(string color, string sound, int velocity, int hopDist)
{
    this->color = color;
    this->sound = sound;
    FrogCounter++;
};

void Frog::setvelocity(int velocity)
{
    this->velocity = velocity;
    cout << "How fast frog jumps: " << this->velocity << endl;
};

Frog *Frog::sethopDist(int hopDist)
{
    this->hopDist = hopDist;
    cout << "Set hopDist to: " << this->hopDist << endl;
    return this;
};

Frog &Frog::sethopDist2(int hopDist)
{
    this->hopDist = hopDist;
    cout << "Set hopDist to: " << this->hopDist << endl;
    return *this;
};

Frog::Frog(Frog &var)
{
    color = var.color;
    sound = var.sound;
    velocity = var.velocity;
    hopDist = var.hopDist;
    FrogCounter++;
    cout << "Frog copied" << endl;
};

Frog::~Frog()
{
    cout << "Frog: " << this << " has been destroyed" << endl;
};

void Frog::show()
{
    cout << endl
         << "Frog type: " << endl;
    cout << "Color: " << color << endl;
    cout << "Sound: " << sound << endl;
    cout << "Frog's velocity: " << velocity << endl;
    cout << "Hop distance: " << hopDist << endl;
    cout << "It's: " << FrogCounter << " type Frog" << endl;
};

int Frog::FrogCounter = 0;

bool Frog::equals(Frog &var)
{
    if (this == &var)
    {
        return true;
    }
    else
    {
        return false;
    }
};