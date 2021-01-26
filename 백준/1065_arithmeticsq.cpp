#include <iostream>
using namespace std;

int main() {
	int N, count = 0;
	cin >> N;
	if (N >= 100) {
		count = 99;
		for (int i = 100; i <= N; i++) {
			int a = i / 100;
			int b = i / 10 % 10;
			int c = i % 10;

			if (a - b == b - c)
				count++;
		}
	}
	else {
		count = N;
	}	
	cout << count << endl;
}