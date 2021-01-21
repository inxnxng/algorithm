#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void secondfunc(queue<int>& que); 

void thirdfunc(queue<int>& que);

int main() {
	int num, out, answer = 0;
	cin >> num >> out;
	
	queue<int> que;
	for (int i = 1; i <= num; i++) {
		que.push(i);
	}

	int key;
	while (out != 0) {
		int idx = -1;
		cin >> key;

		int total = que.size();
		int mid = (total / 2);
		
		//인덱스 찾고
		for (int j = 0; j < total; j++) {		
			int elmt = que.front();	
			if (key == elmt)
				idx = j;
			que.pop();
			que.push(elmt);
		}

		//중간보다 앞에 있으면
		if (idx <= mid ) {
			for (int i = 0; i < idx; i++) {
				secondfunc(que);
				answer++;
			}
		}
		//중간보다 뒤에 있으면 
		else {
			for (int i = idx; i <total; i++) {
				thirdfunc(que);
				answer++;
			}
		}

		//제거 : 1번째 함수
		que.pop();
		out--;
	}
	cout << answer << endl;
	return 0;
}


void secondfunc(queue<int>& que) {
	int tmp = que.front();
	que.pop();
	que.push(tmp);
}

void thirdfunc(queue<int>& que) {
	int tmp = que.back();
	int num = que.size() - 1;
	queue<int> temp;
	temp.push(tmp);
	int front;
	for (int i = 0; i< num; i++) {
		front = que.front();
		temp.push(front);
		que.pop();
	}
	while (!que.empty()) {
		que.pop();
	}
	for (int i = 0; i < num + 1; i++) {
		front = temp.front();
		que.push(front);
		temp.pop();
	}
}