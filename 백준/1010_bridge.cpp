#include<iostream>
using namespace std;

int combination(int n, int r) {
    if (n == r ) 
        return 1;
    if (r == 1)
        return n;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}


int main() {
    int casee;
    cin >> casee;
    int n_key = -1, m_key = -1;
    for (int i = 0; i < casee; i++) {
        cin >> n_key;
        cin >> m_key;
        int answer = combination(m_key, n_key);
        cout << answer << endl;
    }
    return 0;
}