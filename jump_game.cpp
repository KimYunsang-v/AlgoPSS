#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>


using namespace std;

int n, board[10][10], count;

bool jump(int y, int x) {
	 // ���� ��� : ������ ���� ��� ���
	if(y >= n || x >= n) return false;
	// ���� ��� : ������ ĭ�� ������ ���
	if( y == n-1 && x == n-1) return true;
	
//	printf(" jump ���� \n");
	count ++;
	int jumpSize = board[y][x];
	
	return jump( y + jumpSize, x) || jump(y, x + jumpSize);
}

//int n, board[100][100];
int cache[10][10];
//
int jump2(int y, int x) {
	// ���� ��� : ������ ���� ��� ���
	if(y >= n || x >= n) return 0;
	if( y == n-1 && x == n-1) return 1;
	
	count ++;
	
	// �޸������̼� 
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
