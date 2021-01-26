#include <iostream>
using namespace std;

int  count(int n) {
	if (n == 0 || n == 1)return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	return count(n - 1) + count(n - 2) + count(n - 3);
}

int main() {
	int N, elem;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> elem;
		cout << count(elem) << endl;
	}
	return 0;
}
