#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int n;

void hanoi(int size, int start, int middle, int end){
	// 기저 사례 : 마지막 원판이면 끝으로 옮김 
	if( size == 1 ){
		printf("%d %d\n", start, end);
		return;
	}
	
	hanoi(size-1, start, end, middle ); // n-1 개를 1번 -> 2번 (3번 경유) 으로 옮김 
	printf("%d %d\n", start, end); // 제일큰 원판 1번 -> 3번 옮김
	hanoi(size-1, middle, start, end); // 중간으로 옮겼던 판들을 3번으로 옮김 ( 1번 경유 ) 	
 
}

int main() {
	
	
	scanf("%d", &n); 
	
	
	cout << pow(2, n);
	if(n <= 20){
		hanoi(n, 1, 2, 3);
	} else {
		// bigInteger 구현 해야 함
		// 2 ^ n-1 개 출력 
	}
	
	return 0;
}
