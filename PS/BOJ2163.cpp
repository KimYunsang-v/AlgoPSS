#include <stdio.h>
#include <cstring>

using namespace std;

int N, M;
int d[301][301];

int chocolate(int n, int m) {
	
	if(n == 1) return m-1;
	
	int& ret = d[n][m];
	
	if(ret) return ret;
		
	int half = n / 2 ;
	
	ret = chocolate(half, m) + chocolate(n - half, m) + 1;
	
	return ret;	
}

int main() {
	
	memset(d, 0, sizeof(d));
	
	scanf("%d %d", &N, &M);
	
	printf("%d", chocolate(N,M));
	
	return 0;
}
