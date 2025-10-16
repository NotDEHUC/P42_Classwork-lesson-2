// P42_Classwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Drib {
public:
    int chiselnik;
    int znamennik;

    Drib();
    Drib(int a, int b);

    friend ostream& operator<< (ostream& out, const Drib& d) {
        out << d.chiselnik << "/" << d.znamennik;
        return out;
    }

    friend istream& operator>> (istream& in, Drib& d) {
        in >> d.chiselnik;
        in >> d.znamennik;
        return in;
    }

    friend Drib operator+(const Drib& d1, const Drib& d2) {
        Drib res;

        if (d1.znamennik != d2.znamennik) {
            res.znamennik = d1.znamennik * d2.znamennik;
            res.chiselnik = d1.chiselnik * res.znamennik + d2.chiselnik * res.znamennik;
            return Drib{ res.chiselnik, res.znamennik };
        }
        else {
            res.chiselnik = d1.chiselnik + d2.chiselnik;
            return Drib{ res.chiselnik, d1.znamennik };
        }
    }

    friend Drib operator-(const Drib& d1, const Drib& d2) {
        Drib res;

        if (d1.znamennik != d2.znamennik) {
            res.znamennik = d1.znamennik * d2.znamennik;
            res.chiselnik = d1.chiselnik * res.znamennik - d2.chiselnik * res.znamennik;
            return Drib{ res.chiselnik, res.znamennik };
        }
        else {
            res.chiselnik = d1.chiselnik - d2.chiselnik;
            return Drib{ res.chiselnik, d1.znamennik };
        }
    }
    
    friend bool operator==(Drib& d1, Drib& d2) {
        for (size_t i = 2; i <= d1.chiselnik; i++)
        {
            if (d1.chiselnik % i == 0 && d1.znamennik % i == 0) {
                d1.chiselnik = d1.chiselnik / i;
                d1.znamennik = d1.znamennik / i;
                i = 2;
            }
        }

        for (size_t i = 2; i <= d2.chiselnik; i++)
        {
            if (d2.chiselnik % i == 0 && d2.znamennik % i == 0) {
                d2.chiselnik = d2.chiselnik / i;
                d2.znamennik = d2.znamennik / i;
                i = 2;
            }
        }

        if (d1.chiselnik == d2.chiselnik && d1.znamennik == d2.znamennik) {
            return true;
        }
        else
        {
            return false;
        }
    }

    friend bool operator!=(Drib& d1, Drib& d2) {
        return !(d1 == d2);
    }

    friend Drib operator* (Drib& d1, Drib& d2) {
        Drib res;

        res.znamennik = d1.znamennik * d2.znamennik;
        res.chiselnik = d1.chiselnik * d2.chiselnik;

        return Drib{ res.chiselnik, res.znamennik };
    }

    friend Drib operator/ (Drib& d1, Drib& d2) {
        Drib res;

        res.znamennik = d1.znamennik * d2.chiselnik;
        res.chiselnik = d1.chiselnik * d2.znamennik;

        return Drib{ res.chiselnik, res.znamennik };
    }

    void setChiselnik(int);
    void setZnamennik(int);

    Drib sumDrib(Drib);
    Drib subDrib(Drib);
    Drib mulDrib(Drib);
    Drib divDrib(Drib);
};

Drib::Drib() {};

Drib::Drib(int a, int b) {
    chiselnik = a;
    znamennik = b;
}

void Drib::setChiselnik(int a) {
    chiselnik = a;
}

void Drib::setZnamennik(int b) {
    znamennik = b;
}



Drib Drib::sumDrib(Drib B) {
     Drib res;

     if(znamennik != B.znamennik) { 
         res.znamennik = znamennik * B.znamennik; 
         res.chiselnik = chiselnik * res.znamennik + B.chiselnik * res.znamennik;
         return Drib{ res.chiselnik, res.znamennik };
     }
     else {
         res.chiselnik = chiselnik + B.chiselnik;
         return Drib{ res.chiselnik, znamennik };
     }
}

Drib Drib::subDrib(Drib B) {
    Drib res;

    res.znamennik = znamennik * B.znamennik;
    res.chiselnik = chiselnik * res.znamennik - B.chiselnik * res.znamennik;

    return Drib { res.chiselnik, res.znamennik };
}

Drib Drib::mulDrib(Drib B) {
    Drib res;

    res.znamennik = znamennik * B.znamennik;
    res.chiselnik = chiselnik * B.chiselnik;

    return Drib{ res.chiselnik, res.znamennik };
}

Drib Drib::divDrib(Drib B) {
    Drib res;

    res.znamennik = znamennik * B.chiselnik;
    res.chiselnik = chiselnik * B.znamennik;

    return Drib{ res.chiselnik, res.znamennik };
}


int main()
{
    Drib a{ 2, 4 }, b{ 3, 6 };

    if (a == b) {
        cout << "OK" << endl;
    }
    else {
        cout << "NOT OK" << endl;
    }

    if (a != b) {
        cout << "OK" << endl;
    }
    else {
        cout << "NOT OK" << endl;
    }
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
