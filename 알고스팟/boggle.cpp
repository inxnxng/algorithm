#include <iostream>
#include <string>
using namespace std;

char table[5][5];
const int dx[8]{ -1,-1,-1,1,1,1,0,0 };
const int dy[8]{ -1,0,1,-1,0,1,-1,1 };

bool isRange(int x, int y) {
	return (-1 < x && x < 5 && -1 < y && y < 5);
}

bool hasWord(int x, int y, const string& word) {
	//base case : 범위에서 벗어날 경우
	if (!isRange(x, y)) return false;
	//base case : 첫 글자가 시작 글자와 다른 경우
	if (table[x][y] != word[0]) return false;
	//base case : 첫 글자를 찾고 그 글자의 길이가 1일 경우
	if (word.size() == 1) return true;

	for (int i = 0; i < 8; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (hasWord(nextX, nextY, word.substr(1)))
			return true;
	}
	return false;
}

void search(const string& word) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (hasWord(i, j, word)) {
				cout << word << " YES" << endl;
				return;
			}
		}
	}

	cout << word << " NO" << endl;
	return;
}

int main() {
	int tcase;
	char apb;
	cin >> tcase;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> table[i][j];
		}
	}
	
	cin >> tcase;
	string word;
	
	for (int i = 0; i < tcase; i++) {
		cin >> word;
		search(word);
	}
	return 0;
}