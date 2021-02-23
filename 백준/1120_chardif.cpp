#include<iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string A, B;
	cin >> A >> B;
	int Asz = A.size();
	int Bsz = B.size();
	int wrong = Bsz; 
	//A와 B의 길이는 같은 상태
	for (int i = 0; i <= (Bsz-Asz); i++) {
		int tmp = 0;
		for (int j = 0; j < Asz; j++) {
			if (A[j] != B[i + j])
				tmp++;
		}
		wrong = (tmp > wrong) ? wrong : tmp;
	}
	cout << (wrong);
	return 0;
}