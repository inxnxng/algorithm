#include <iostream>
#include <string>
#include <deque>
using namespace std;
//push back과 front만 숫자를 받음

void dequecheck(deque<int>& dq, string str) {
	int num;
	if (str == "push_back") {
		cin >> num;
		dq.push_back(num);
	}

	else if (str == "push_front") {
		cin >> num;
		dq.push_front(num);
	}

	else if (str == "pop_front") {
		if (dq.empty()) {
			cout << -1 << endl;
		}
		else {
			cout << dq.front() << endl;
			dq.pop_front();
		}
	}

	else if (str == "pop_back") {
		if (dq.empty()) {
			cout << -1 << endl;
		}
		else {
			cout << dq.back() << endl;
			dq.pop_back();
		}
	}

	else if (str == "size") {
		cout << dq.size() << endl;
	}

	else if (str == "empty") {
		if (dq.empty())
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	else if (str == "front") {
		if (!dq.empty()) {
			cout << dq.front() << endl;
		}
		else
			cout << -1 << endl;
	}

	else {
		if (!dq.empty()) {
			cout << dq.back() << endl;
		}
		else
			cout << -1 << endl;
	}
}



int main() {
	int N;
	string str;
	deque<int> dq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		dequecheck(dq, str);
	}
	return 0;
}