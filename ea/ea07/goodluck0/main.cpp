#include <iostream>
#include "goodluck.h"

using namespace std;

int main()
{
    GoodLuck g1("Bolyai Farkas", "Bolyai Janos");
    GoodLuck g2("Neumann Janos");
    g2.setBeneficiary("Neumann Janosne");

    cout << g1.toString() << endl << g2.toString() << endl;

    cout << "Hany jegyet kap: " << GoodLuck::howManyUnits(5000) << endl;
    cout << "Vasarol: " << g1.purchase(5000) << endl;

    cout << "arfolyam: " << GoodLuck::getRate() << endl;
    cout << "vasarlasi koltseg: " << GoodLuck::getPurchaseCost() << endl;
    GoodLuck::setRate(5.4); GoodLuck::setPurchaseCost(600.0);

    cout << "Vagyon: " << g1.value() << endl;
    cout << "Elad: " << g1.sell(5000) << endl;
    cout << "eladasi koltseg: " << GoodLuck::getSalesCost() << endl;
    GoodLuck::setSalesCost(100.0);

    cout << g1.toString() << endl << g2.toString() << endl;

    return 0;
}
