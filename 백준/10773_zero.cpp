#include <iostream>
#include <stack>
using namespace std;

int main() {
	int num, elem, total = 0;
	cin >> num;
	stack<int> stk;
	for (int i = 0; i < num; i++) {
		cin >> elem;
		if (elem == 0)
			stk.pop();
		else
			stk.push(elem);
	}

	num = stk.size();
	for (int i = 0; i < num; i++) {
		total += stk.top();
		stk.pop();
	}
	cout << total << endl;
	return 0;
}