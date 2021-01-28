#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n) {
	if (n <= 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if ((n % i) == 0)
			return false;
	}
	return true;
}

int main() {
	int num, elem, total = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> elem;
		if (prime(elem))
			total++;
	}
	cout << total << endl;
	
	return 0; 
}
