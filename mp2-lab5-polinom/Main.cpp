#include <iostream>
#include "TPolinom.h"
#include "TMonom.h"
using namespace std;

void main() {
	TPolinom pol1;
	TMonom m;

	cout << "pol1 \n monom 1: " << endl;
	cin >> m;
	pol1.AddMonom(m);

	cout << "monom 2: " << endl;
	cin >> m;
	pol1.AddMonom(m);

	cout << "monom 3: " << endl;
	cin >> m;
	pol1.AddMonom(m);

	TPolinom pol2;

	cout << "pol2 \n monom 1: " << endl;
	cin >> m;
	pol2.AddMonom(m);

	cout << "monom 2: " << endl;
	cin >> m;
	pol2.AddMonom(m);

	cout << "monom 3: " << endl;
	cin >> m;
	pol2.AddMonom(m);

	pol1 = pol1 + pol2;
	cout << pol1;
}