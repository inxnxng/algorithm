#include <iostream>
#include <vector>
using namespace std;

const int coverType[4][3][2] = {
    {{0,0 },{1,0},{0,1}},
    {{0,0 },{0,1},{1,1}},
    {{0,0 },{1,0},{1,1}},
    {{0,0 },{1,0},{1,-1}}
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; ++i) {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        //사이즈에서 벗어났다면
        if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
            ok = false;
        //만약 이미 덮여있는 곳이라면
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int cover(vector<vector<int>>& board) {
    int y = -1, x = -1;
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            
            //덮이지 않은 칸이라면 찾아서 break
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }
    //base case : 모든 칸을 채웠다면 1을 반환한다
    if (y == -1) return 1;
    int ret = 0;
    for (int type = 0; type < 4; ++type) {
        if (set(board, y, x, type, 1))
            ret += cover(board);
        set(board, y, x, type, -1);
    }
    return ret;
}

int main() {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
    int C, H, W;
    char chr;
    cin >> C;
    for (int test = 0; test < C; test++) {
        cin >> H >> W;
        int cnt = 0;

        //HxH 개의 벡터 배열을 선언한다.
        vector<vector<int>> a(H, vector<int>(W,0));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> chr;
                if (chr == '#')
                    a[i][j] = 1;
                else {
                    a[i][j] = 0;
                    cnt++;
                }
            }
        }
        if (cnt % 3 != 0)
            cout << 0 << "\n";
        else
            cout << cover(a) << "\n";
    }
    return 0;
}