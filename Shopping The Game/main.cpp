#include "shop.h"

int main ()
{
	cout << "Write length and width" << endl;
	int g,h;
	cin >> g >> h;
	shop lab(g,h);
	lab.f_out();

	system ("pause");
	return 0;
}