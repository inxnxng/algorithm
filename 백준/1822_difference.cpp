#include <iostream>
#include <set>
using namespace std;

int main() {
	int a_n, b_n, elem;
	cin >> a_n >> b_n;
	set<int> a;
	for (int i = 0; i < a_n; i++) {
		cin >> elem;
		a.insert(elem);
	}
	for (int i = 0; i < b_n; i++) {
		cin >> elem;
		auto it = a.find(elem);
		if (it == a.end())
			continue;
		else
			a.erase(it);
	}
	cout << a.size() << endl;
	if (a.size() != 0) {
		for (auto elem : a)
			cout << elem << " ";
	}cout << endl;
	return 0;
}
