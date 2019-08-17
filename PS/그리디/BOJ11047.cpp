#include <stdio.h>

using namespace std;

int N, K;
int M[11];
int ret;

int main() {		
	scanf("%d %d", &N, &K);
	
	for(int i = 0; i < N; ++i){
		scanf("%d", &M[i]);
	}	
	
	while(N-- && K){		
		if(K < M[N]) continue;
		ret += K / M[N];
		K %= M[N];
	}
	
	printf("%d", ret);
	return 0;
}
