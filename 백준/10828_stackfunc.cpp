#include <iostream>
#include <stack>
using namespace std;

int main() {
	int num, elem;
	string word;
	stack<int> stk;
	
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> word;
		if (word == "push") {
			cin >> elem;
			stk.push(elem);
		}
		else if (word == "pop") {
			if (stk.empty())
				cout << -1 << endl;
			else {
				elem = stk.top();
				cout << elem << endl;
				stk.pop();
			}
		}
		else if (word == "size") {
			cout << stk.size() << endl;
		}
		else if (word == "empty") {
			if (stk.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else {
			if (stk.empty())
				cout << -1 << endl;
			else{
				elem = stk.top();
				cout << elem << endl;
			}
		}
	}
	return 0; 
}