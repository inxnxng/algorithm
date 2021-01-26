#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	int package, onlyone, total = 0;
	int min_pack = 1000, min_only = 1000;
	for (int i = 0; i < M; i++) {
		cin >> package >> onlyone;
		if (min_pack > package) {
			min_pack = package;
		}
		if (min_only > onlyone) {
			min_only = onlyone;
		}
	}
	//cout << min_pack << min_only << endl;

	int q = (N / 6);
	int r = (N % 6);
	total = min(min((q * min_pack) + (r * min_only), N*min_only), (q + 1) * min_pack);


	cout << total << endl;
	return 0;
}
