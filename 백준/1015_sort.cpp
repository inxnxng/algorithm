#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num, elem;
	cin >> num;
	vector<int> A; 
	vector<int> P;
	vector<int> tmp;
	for (int i = 0; i < num; i++) {
		cin >> elem;
		A.push_back(elem);
	}
	tmp.assign(A.begin(), A.end());

	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < num; i++) {
		int key = (find(tmp.begin(), tmp.end(), A[i]) - tmp.begin());
		tmp[key] = -1;
		P.push_back(key);
	}

	for (int i = 0; i < num; i++)
		cout << P[i] << " ";
	return 0;
}