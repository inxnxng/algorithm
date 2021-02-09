#include<iostream>
#include<string>
using namespace std;

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)

int hugs(const string& mem, const string& fan) {
	int N = mem.size(), M = fan.size(), hugs = 0;
	//같은 수의 사람이 있을 경우 
	if (N == M) {
		for (int i = 0; i < N; i++) {
			if (mem[i] == 'M' && fan[i] == 'M')
				return 0;
		}
		return 1;
	}
	//수가 안맞을 경우
	int cnt;
	for (int i = 0; i < (M - N + 1); i++) {
		cnt = 0;
		for (int j = 0; j < N; j++)
			if (mem[j] == 'M' && fan[i+j] == 'M')
				cnt++;
		if (cnt == 0)
			hugs++;
		
	}	
	return hugs;
}


int main() {
	int C;
	string mem, fan;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> mem >> fan;
		cout << hugs(mem, fan) << endl;
	}
	return 0;
}