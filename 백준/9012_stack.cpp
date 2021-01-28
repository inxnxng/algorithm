#include <iostream>
#include <stack>
using namespace std;


bool isVps(stack<char>& st, string& w) {
	int sizes = w.size();
	for (int i = 0; i < sizes; i++) {
		if (w[i] == '(')
			st.push('(');
		else {
			if (st.empty())
				return false;
			st.pop();
		}
	}
	if (st.empty())
		return true;
	else
		return false;
}

int main() {
	int n; string word;
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> stk;
		cin >> word;
		if (isVps(stk, word))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}