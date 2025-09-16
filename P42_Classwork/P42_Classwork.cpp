// P42_Classwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Drib {
    int chiselnik;
    int znamennik;

public:
    void setChiselnik(int);
    void setZnamennik(int);

    Drib sumDrib(Drib);
    Drib minDrib(Drib);
    Drib mulDrib(Drib);
    Drib divDrib(Drib);
};

void Drib::setChiselnik(int a) {
    chiselnik = a
}

void Drib::setZnamennik(int b) {
    znamennik = b
}



Drib Drib::sumDrib(Drib B) {
     Drib res;

     res.znamennik = znamennik * B.znamennik;
     res.chiselnik = chiselnik * res.znamennik + B.chiselnik * znamennik;

     return res
}

Drib Drib::minDrib(Drib B) {
    Drib res;

    res.znamennik = znamennik * B.znamennik;
    res.chiselnik = chiselnik * res.znamennik - B.chiselnik * znamennik;

    return res
}

Drib Drib::mulDrib(Drib B) {
    Drib res;

    res.znamennik = znamennik * B.znamennik;
    res.chiselnik = chiselnik * B.chiselnik;
}

Drib Drib::divDrib(Drib B) {
    Drib res;

    res.znamennik = znamennik * B.chiselnik;
    res.chiselnik = chiselnik * B.znamennik;
}


int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
