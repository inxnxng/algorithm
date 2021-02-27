#include<iostream>
using namespace std;

long long dp[101];

long long solve(int N) {
	for (int j = 6; j <= N; j++) {
		dp[j] = dp[j - 1] + dp[j - 5];
	}
	return  dp[N]; 
}

int main() {
	int N, T;
	cin >> T;

	dp[0] = dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << solve(N) << endl;
	}
	return 0;
}