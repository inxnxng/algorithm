#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001], sum[1001], result[1001];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr,arr+N);
	result[0] = sum[0] = arr[0];
	for (int i = 1; i < N; i++) {
		sum[i] = arr[i] + sum[i - 1];
		result[i] = result[i - 1] + sum[i];
	}
	cout <<result[N-1];
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001], sum[1001];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr,arr+N);

	sum[0] = arr[0];
	int tmp = sum[0];
	for (int i = 1; i < N; i++) {
		tmp = sum[i] = arr[i] + tmp;
		sum[i] = sum[i - 1] + sum[i];
	}
	cout <<sum[N-1];
	return 0;
}