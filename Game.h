#include <iostream>
#include <Windows.h>
using namespace std;


class Pieces
{
    public:

    string shape;
    bool completed;
    int price;

    Pieces(string _shape, bool _completed, int _price)
    {
        shape = _shape;
        completed = _completed;
        price = _price;
    }

    void output()
    {
        if(completed==0)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << shape;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    
};
 
