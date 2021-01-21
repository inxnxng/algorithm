#include<iostream>
using namespace std;

int main() {
    int m,n;	//m 가로 n 세로
    cin >> n >> m;

    int arr[50][50]={ 0 };	//배열 초기화하기
    char num;

    for (int i = 0; i < n; i++) {	//입력된 배열을 arr 배열에 넣어주기
        for (int j = 0; j < m; j++) {
            cin >> num;
            arr[i][j] = num;
        }
    }

    int min = 50;	//최종 결과값인 min값 초기화

    for (int i = 0; i < n - 7; i++) {	
        for (int j = 0; j < m - 7; j++) {

            int wtob = 0;
            int btow = 0;

            for (int a = i; a < i + 8; a++) {
                for (int b = j; b < j + 8; b++) {

                    if ((a + b) % 2 == 0) {
                        if (arr[a][b] == 66) 
                            btow++;
                        else
                            wtob++;
                    }
                    else {
                        if (arr[a][b] == 66)
                            wtob++;
                        else
                            btow++;
                    }
                }
            }            
            min = (min < wtob) ? min : wtob;	//한번 싹 다 돌고 나서 최솟값 검색
            min = (min < btow) ? min : btow;

        }
    }

    cout << min;	//결과 출력
    return 0;
}