#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, ans = 0;
	int ti[17]{ 0, }, pi[17]{ 0, };
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ti[i] >> pi[i];
	}
	for (int i = N; i >= 1; i--) {
		if ((i + ti[i]) > N+1)
			pi[i] = pi[i + 1];
		else {
		   pi[i] = max(pi[i+1], pi[i] + pi[i + ti[i]]);
		   ans = max(ans, pi[i]); 
		}
	}
	cout << ans << endl;
	return 0;
}