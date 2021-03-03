#include<iostream>
#include<queue>
using namespace std;

int main() {
	int N;
	queue<int> que;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		que.push(i);
	}
	int temp;

	while (N != 1) {
		que.pop();
		N--;
		temp = que.front();
		que.pop();
		que.push(temp);
	}
	cout << que.front();
	return 0; 
}