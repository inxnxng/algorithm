#include <iostream>
using namespace std;

int n;
bool areFriends[10][10]; 
bool taken[10]{ false };

int countPairings(bool taken[10]) {
	int ret = 0;
	int firstFree = -1; //남은 학생들 중 가장 번호가 빠른 학생을 찾는다
	for (int i = 0; i < n; i++) {
		if (!taken[i]) { //계산된 것이 아니라면
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) return 1; //모든 학생들이 짝을 찾았다면 과정을 종료
	for (int pairwith = firstFree + 1; pairwith < n; ++pairwith) {
		if (!taken[pairwith] && areFriends[firstFree][pairwith]) {
			taken[firstFree] = taken[pairwith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairwith] = false;
		}
	}
	return ret;
}

void check(int m) {
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		areFriends[a][b] = areFriends[b][a] = true;
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int testcase, m, ans;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> n >> m; //n은 친구 수, m은 쌍의 수
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				areFriends[i][j] = false;
			}
		}
		check(m);
		ans = countPairings(taken);
		cout << ans << endl;
	}
}