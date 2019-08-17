#include <stdio.h>
#include <cstring>

using namespace std;

int T, N;
long long d[101];
int test[1000001];

long long triangle(int n) {
	//if(n == 1 || n == 2 || n == 3) return 1;
	
	long long& ret = d[n];
	
	if(ret != -1) return ret;
	
	ret = triangle(n-1) + triangle(n-5);
	
	return ret;	
}

int main() {
	scanf("%d", &T);
	
	for(int i=0; i <T; ++i){
		scanf("%d", &test[i]);
	}
	
	memset(d, -1, sizeof(d));
	d[1] = d[2] = d[3] = 1;
	d[4] = d[5] = 2;

	for(int i=0; i <T; ++i){		
		printf("%lld\n", triangle(test[i]));
	}
	
	return 0;
}
