#include <iostream>
#include "goodluck.h"
#include "badluck.h"

using namespace std;

int main()
{
    GoodLuck g("Bolyai Farkas", "Bolyai Janos");
    BadLuck  b("Riesz Frigyes");

    cout << g.toString() << endl;
    cout << b.toString() << endl << endl;

    cout << "GoodLuck rate: " << GoodLuck::_condition.getRate() << endl;
    cout << "BaddLuck rate: " << BadLuck::_condition.getRate() << endl << endl;

    cout << "Vasarol: " << g.purchase(5000) << endl;
    cout << "Vasarol: " << b.purchase(5000) << endl << endl;

    cout << g.toString() << endl;
    cout << b.toString() << endl;

    GoodLuck::_condition.setRate(8.9);
    BadLuck::_condition.setRate(1.2);

    cout << "GoodLuck rate: " << GoodLuck::_condition.getRate() << endl;
    cout << "BaddLuck rate: " << BadLuck::_condition.getRate() << endl << endl;

    cout << "Elad: " << g.sell(5000) << endl;
    cout << "Elad: " << b.sell(2000) << endl << endl;

    cout << g.toString() << endl;
    cout << b.toString() << endl;

    return 0;
}
