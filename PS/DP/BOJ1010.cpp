#include <stdio.h>
#include <cstring>

using namespace std;

int t, result;
int test[1000][2];
int d[31][31];

long bridge(int n, int r) {
	
	if(n == r || r == 0){
		return 1;	
	}
	
	int& ret = d[n][r];
	
	if(ret != -1) return ret;
	
	ret = bridge(n-1, r-1) + bridge(n-1, r);
	
	return ret;
}

int main() {
	
	
	scanf("%d", &t);
	
	for(int i = 0; i < t; ++i){
		scanf("%d %d", &test[i][0], &test[i][1]);
	}
	
	for(int i = 0; i < t; ++i){
		memset(d, -1, sizeof(d));
		printf("%d\n", bridge(test[i][1], test[i][0]));
	}
}
