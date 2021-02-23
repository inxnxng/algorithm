#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	int arr[300]{ 0, };
	int dp[300]{ 0, };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0]; // base case
	dp[1] = max(arr[0] + arr[1], arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i - 2] + arr[i],
        		    arr[i - 1] + arr[i] + dp[i - 3]);
	}

	cout << dp[N - 1];
	return 0;
}