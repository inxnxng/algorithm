#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	//기본 값 받기
	int N, M, elem, right = 0, left = 0, answer = 0, sum = 0;
	cin >> N >> M;
	
	//배열에 넣기
	int arr[10000];
	for (int i = 0; i < N; i++) {
		cin >> elem;
		arr[i] = elem;
	}

	//연산하기
	while(right < N && left <= N) {
		cout << left << ", " << right << endl;
		if (sum < M) {
			if (right >= N)
				break;
			sum += arr[left++];
		}
		else if (sum == M) {
			answer++;
			cout << "sum : " << sum << endl;
			sum -= arr[right++];
		}
		else {
			sum -= arr[right++];
		}
	}

	cout << answer << endl;
	return 0;

}