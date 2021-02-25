#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];
int main() {
	cin.tie(NULL);
	int N, M, elem;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	bool check = false;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> elem;
		int start = 0, end = N - 1, mid;
		while (start <= end){
			mid = (start + end) / 2;
			if (arr[mid] < elem) {
				start = mid+1;
			}
			else if(arr[mid] > elem){
				end = mid-1;
			}
			else {
				check = true;
				break;
			}
		}
		if (check) {
			cout << "1\n";
			check = false;
		}
		else
			cout << "0\n";
	}

	return 0;
}