#include <stdio.h>
#include <cstring>

using namespace std;

int cache[1001];
int n;
const int MOD = 10007;

int tiling(int width) {
	// 기저 사례:  width가 1 이하일 때
	if(width <= 1) return 1;
	
	int& ret = cache[width] ; 
	if(ret != -1) return ret;
	return ret = ((tiling(width-2) *2) + tiling(width-1)) % MOD;
}


int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	
	cache[1] = 1;
	cache[2] = 3;
	
	printf("%d", tiling(n));
	
	return 0;
}
