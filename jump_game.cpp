#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>


using namespace std;

int n, board[10][10], count;

bool jump(int y, int x) {
	 // 기저 사례 : 게임판 밖을 벗어난 경우
	if(y >= n || x >= n) return false;
	// 기저 사례 : 마지막 칸에 도착한 경우
	if( y == n-1 && x == n-1) return true;
	
//	printf(" jump 실행 \n");
	count ++;
	int jumpSize = board[y][x];
	
	return jump( y + jumpSize, x) || jump(y, x + jumpSize);
}

//int n, board[100][100];
int cache[10][10];
//
int jump2(int y, int x) {
	// 기저 사례 : 게임판 밖을 벗어난 경우
	if(y >= n || x >= n) return 0;
	if( y == n-1 && x == n-1) return 1;
	
	count ++;
	
	// 메모이제이션 
	int& ret = cache[y][x];
	if(ret != -1) return ret;
	
	int jumpSize = board[y][x];
	return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
}


int main() {
	for(int i = 0; i <= 9; i++) {
		for(int j = 0; j <= 9; j++){
			board[i][j] = 1;
		}
	}
	
	memset(cache, -1, sizeof(cache));
	
	board[9][8] = 2;
	board[8][9] = 2;
	
	n = 10;
	
	printf("%d \n ", jump2(0,0));
	
	printf("%d" , count);
	
//	for(int i = 0; i <= 19; i++) {
//		for(int j = 0; j <= 19; j++){
//			printf("%d", board[i][j]);
//		}
//		printf("\n");
//	}

	
	
	return 0;
	
}
