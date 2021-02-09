#include<iostream>
#include <queue>
#include <cstring>
using namespace std;

void solution(queue<int>& que, string& cmd) {
	if (cmd=="push") {
		int num;
		cin >> num;
		que.push(num);
	}
	else if (cmd == "pop") {
		if (!que.empty()) {
			cout << que.front() << endl;
			que.pop();
		}
		else {
			cout << -1 << endl;
		}
	} 
	else if (cmd == "size") {
		cout << que.size() << endl;
	}
	else if (cmd == "front") {
		if (!que.empty()) {
			cout << que.front() << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	else if (cmd == "empty") {
		if (!que.empty()) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	else {
		if (!que.empty()) {
			cout << que.back() << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return;
}



int main() {
	int N;
	string cmd;
	queue<int> que;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd;
		solution(que, cmd);
	}

	return 0;
}