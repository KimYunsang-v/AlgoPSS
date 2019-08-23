#include <stdio.h>
#include <algorithm>


using namespace std;

int N;
int g[10001];
int ret = 0;

int main() {
	scanf("%d", &N);
	
	for(int i = 0; i < N; ++i){
		scanf("%d", &g[i]);
	}
	
	sort(g, g+N);
	
    long long result = 0;
    for (int i = 0; i < N; i++) {
        long long sum = g[i] * (i + 1);
        if(sum > result)
            result = sum;
    }

	printf("%d", result);
	
	return 0;
}

