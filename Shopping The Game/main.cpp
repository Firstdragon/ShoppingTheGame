#include "Gameengine.h"

int main ()
{
	cout << "Write length and width" << endl;
	int g,h;
	cin >> g >> h;
	shop lab(g,h);
	Gameengine engine;
	engine.f_out(lab.len, lab.wid, lab.floor);

	system ("pause");
	return 0;
}
