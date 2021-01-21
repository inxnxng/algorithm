#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int testcase, possible, already, num;
	cin >> testcase;

	vector<double> result;

	for (int i = 0; i < testcase; i++) {
		cin >> possible >> already;
		vector<int> vec;
		//비용값 벡터에 넣기

		for (int j = 0; j < possible; j++) {
			cin >> num;
			vec.push_back(num);
		}

		//최소 비용 찾아내기
		double sum = 0;
		double minsum = 100;
		//몇 날을 탐색할 것인지
		for (int day = already; day < possible; day++) {
			//총 몇번 탐색이 되는지
			for (int iter = 0; iter < possible-day+1; iter++) {
				//cost값 더하기
				for (int idx = iter; idx < iter + day; idx++) {
					sum += vec[idx];
				}
				minsum = min(minsum, (double)(sum/day));
				sum = 0;
			}
		}
		result.push_back(minsum);
	}
	cout << fixed;
	cout.precision(10);
	for (int i = 0; i < testcase; i++)
		cout << result.at(i) << endl;

}