// P42_Classwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Drib {
public:
    int chiselnik;
    int znamennik;

    Drib();
    Drib(int a, int b);

    void setChiselnik(int);
    void setZnamennik(int);

    Drib sumDrib(Drib);
    Drib subDrib(Drib);
    Drib mulDrib(Drib);
    Drib divDrib(Drib);
};

Drib::Drib() {};

Drib::Drib(int a, int b) {
    
    int  c = sproshennya(a, b);

    chiselnik = a / c;
    znamennik = b / c;
}

int sproshennya(int x, int y) {
    int i = x;

    while (i != 0)
    {
        if (x % i == 0 && y % i == 0) {
            return i;
        }
        else
        {
            i--;
        }
    }
}

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

     return Drib a{ res.chiselnik, res.znamennik };
}

Drib Drib::subDrib(Drib B) {
    Drib res;

    res.znamennik = znamennik * B.znamennik;
    res.chiselnik = chiselnik * res.znamennik - B.chiselnik * znamennik;

    return Drib a{ res.chiselnik, res.znamennik };
}

Drib Drib::mulDrib(Drib B) {
    Drib res;

    res.znamennik = znamennik * B.znamennik;
    res.chiselnik = chiselnik * B.chiselnik;

    return Drib a{ res.chiselnik, res.znamennik };
}

Drib Drib::divDrib(Drib B) {
    Drib res;

    res.znamennik = znamennik * B.chiselnik;
    res.chiselnik = chiselnik * B.znamennik;

    return Drib a{ res.chiselnik, res.znamennik };
}


int main()
{
    Drib a{ 2, 4 };
    Drib b{ 4, 8 };

    a.mulDrib(b);
    
    std::cout << a.chiselnik << " " << a.znamennik;
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
