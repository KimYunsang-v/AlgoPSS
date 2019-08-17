#include <stdio.h>

using namespace std;


int N, result;
int a[1001];
int main() {
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; ++i) {
		scanf("%d", &a[i]);
	}
	
	int min = a[0];
	
	for(int i=0; i < N-1; ++i){
		for(int j = i+1; j < N; ++j){
			if(a[i] > a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j <= i; ++j){
			result += a[j];
		}
	}
	
	printf("%d", result);
	
	return 0;
}
