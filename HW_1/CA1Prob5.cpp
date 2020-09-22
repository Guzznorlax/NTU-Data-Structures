/*
*  Calculate a rectangle's area, perimeter and checks whether it is a square
*
*  @author 游子霆
*  @ID B07505051
*  @Department Engineering Science and Ocean Engineering
*  @Affiliation National Taiwan University
*/

#include <iostream>

using namespace std;

class rectangle
{
private:
	double width;
	double length;
	double perimeter;
	double area;

public:
	// Constructor, automatically compute the perimeter and area once it is OK.
	rectangle(double wd, double lg);

	// Set the dimension and automatically update the perimeter and area.
	void setDimension(double wd, double lg);

	// Set the width and automatically update the perimeter and area.
	void setWidth(double wd);

	// Set the length and automatically update the perimeter and area.
	void setLength(double lg);

	// Return the width of the rectangle.
	double getWidth();

	// Return the length of the rectangle.
	double getLength();

	// Return the perimeter of the rectangle.
	double getPerimeter();

	// Return the area of the rectangle.
	double getArea();

	// True, if width = length.
	bool isSquare();
};

rectangle::rectangle(double wd, double lg)
{
	width = wd;
	length = lg;
	perimeter = 2 * (wd + lg);
	area = wd * lg;
}

void rectangle::setDimension(double wd, double lg)
{
	width = wd;
	length = lg;
	perimeter = 2 * (wd + lg);
	area = wd * lg;
}

void rectangle::setWidth(double wd)
{
	width = wd;
	setDimension(wd, length);
}

void rectangle::setLength(double lg)
{
	length = lg;
	setDimension(width, lg);
}

double rectangle::getWidth()
{
	return width;
}

double rectangle::getLength()
{
	return length;
}

double rectangle::getPerimeter()
{
	return perimeter;
}

double rectangle::getArea()
{
	return area;
}

bool rectangle::isSquare()
{
	if (width == length)
	{
		return true;
	}

	return false;
}

/* int main()
{
	rectangle a = rectangle(0, 0);

	cout << "length: " << a.getLength() << "\n";
	cout << "width: " << a.getWidth() << "\n";
	cout << "perimeter: " << a.getPerimeter() << "\n";
	cout << "area: " << a.getArea() << "\n";
	cout << "isSquare: " << a.isSquare() << "\n";

	a.setLength(10);
	a.setWidth(20);

	cout << "length: " << a.getLength() << "\n";
	cout << "width: " << a.getWidth() << "\n";
	cout << "perimeter: " << a.getPerimeter() << "\n";
	cout << "area: " << a.getArea() << "\n";
	cout << "isSquare: " << a.isSquare() << "\n";

	a.setDimension(35, 35);

	cout << "length: " << a.getLength() << "\n";
	cout << "width: " << a.getWidth() << "\n";
	cout << "perimeter: " << a.getPerimeter() << "\n";
	cout << "area: " << a.getArea() << "\n";
	cout << "isSquare: " << a.isSquare() << "\n";

	return 0;
} */
