#include<iostream>
using namespace std;

int N, M;
bool visited[9]{ false, };
int arr[9]{ 0, };

void solve(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			solve(cnt + 1);
			visited[i] = false;
		}
	}
	return;
}

int main() {
	cin >> N >> M;
	int cnt = 0;
	solve(cnt);

	return 0;
}