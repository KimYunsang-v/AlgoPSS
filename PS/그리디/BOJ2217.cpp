#include <stdio.h>
#include <algorithm>


using namespace std;

int N;
int g[100001];

int main() {
	scanf("%d", &N);	
	
	for(int i = 0; i < N; ++i){
		scanf("%d", &g[i]);
	}
	
	sort(g, g+N);
	
    int sum = -1;
    
    for (int i = 0; i < N; i++) {
        sum = max(sum,  g[i] * (N-i));
    }

	printf("%d", sum);
	
	return 0;
}

