#include <stdio.h>
#include <cstring>

using namespace std;

int T, N;
int d[101];
int test[1000001];

int triangle(int n) {
	//if(n == 1 || n == 2 || n == 3) return 1;
	
	int& ret = d[n];
	
	if(ret) return ret;
	
	ret = triangle(n-2) + triangle(n-3);
	
	return ret;	
}

int main() {
	scanf("%d", &T);
	
	for(int i=0; i <T; ++i){
		scanf("%d", &test[i]);
	}
	
	
	
	for(int i=0; i <T; ++i){
		memset(d, 0, sizeof(d));
		d[1] = d[2] = d[3] = 1;
		printf("%d\n", triangle(test[i]));
	}
	
	return 0;
}


