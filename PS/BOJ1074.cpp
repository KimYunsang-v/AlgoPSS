#include<cassert>
#include<vector>
#include<iostream>
#include<cstring>
#include <algorithm>
#include <math.h>
using namespace std;

int N, r, c;
int result;
void Z(int x, int y, int len) {	
	if(y == r && x == c){
		printf("%d", result); // 해당 좌표일 경우 출력 
		exit(0); 
	}	
	
	if(len == 1){
		result++;
		return;
	}		
	
	if(!(r >= y && r < y + len && c >= x && c < x + len)){
		result += len * len;
		return;
	}
	
	Z(x, y, len/2);
	Z(x + len/2, y, len/2);	
	Z(x, y + len/2, len/2);	
	Z(x+len/2, y+len/2, len/2);
}

int main() {
	scanf("%d %d %d", &N, &r, &c);
	
	Z(0,0,pow(2,N));    
	
    return 0;
}
