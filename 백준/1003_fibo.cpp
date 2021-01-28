#include <iostream>
using namespace std;

int main() {
	int num, elem;
	int a[41]{ 0,1 };

	for (int j = 2; j <= 40; j++) {
		a[j] = a[j - 1] + a[j - 2];
	}

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> elem;
		if (elem == 0)
			cout << "1 0" << endl;
		else
			cout << a[elem-1] << " " << a[elem] << endl;
	}
	return 0;
}