/*
*  A class of flower and its manipulation funcs.
*
*  @author 游子霆
*  @ID B07505051
*  @Department Engineering Science and Ocean Engineering
*  @Affiliation National Taiwan University
*/

#include <iostream>
#include <string>

using namespace std;

class flower
{
private:
	string name;
	int petal;
	double price;

public:
	// Constructor.
	flower(string n, int pt, double pr);

	// Set the name of the flower.
	void setName(string n);

	// Set the petal number of the flower.
	void setPetal(int pt);

	// Set the price of the flower.
	void setPrice(double pr);

	// Return the name of the flower.
	string getName();

	// Return the petal number of the flower.
	int getPetal();

	// Return the price of the flower.
	double getPrice();
};

flower::flower(string n, int pt, double pr)
{
	name = n;
	petal = pt;
	price = pr;
}

void flower::setName(string n)
{
	name = n;
}

void flower::setPetal(int pt)
{
	petal = pt;
}

void flower::setPrice(double pr)
{
	price = pr;
}

string flower::getName()
{
	return name;
}

int flower::getPetal()
{
	return petal;
}

double flower::getPrice()
{
	return price;
}

int main()
{
	flower a = flower("Initial Flower Name", 0, 0);

	a.setName("Nodding Trillium");
	a.setPetal(3);
	a.setPrice(75.3);

	cout << "name: " << a.getName() << "\n";
	cout << "petal number: " << a.getPetal() << "\n";
	cout << "price: " << a.getPrice() << "\n";

	return 0;
}
