#include <iostream>
#include <algorithm>
using namespace std;

void prime(int N) {
	int limit = N;
	int key = 2;
	while  (key <= N) {
		if (N == 2) {
			cout << 2 << endl;
			return;
		}
		else if (N == 3) {
			cout << 3 << endl;
			return;
		}

		if (N % key == 0) {
			cout << key << endl;
			N = N / key;
		}
		else
			key++;
	}
}


int main() {
	int N;
	cin >> N;
	prime(N);
	return 0;
}