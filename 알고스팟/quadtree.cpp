#include<iostream>
#include<string>
using namespace std;

#define MAX_SIZE 20

char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(string::iterator& it, int y, int x, int size) {
	//글자 하나를 탐색하면 iterator을 옮겨준다.
	char head = *(it++);
	if (head == 'b' || head == 'w') {
		for (int dy = 0; dy < size; ++dy) {
			for (int dx = 0; dx < size; ++dx) {
				decompressed[y + dy][x + dx] = head;
			}
		}
	}
	else {
		int half = size / 2;
		decompress(it, y, x, half);
		decompress(it, y, x+half, half);
		decompress(it, y+half, x, half);
		decompress(it, y+half, x+half, half);
	}
}

string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'w' || head == 'b')
		return string(1, head);
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}


int main() {
	int C; string strIn;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> strIn;
		if (strIn.size() > 1000) exit(-1);
		string::iterator iter = strIn.begin();
		//decompress(iter, 0, 0, strIn.length());
		//iter = strIn.begin();
		cout << reverse(iter) << endl;
	}
	return 0;
}