#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[1001];
int cache[1001];
int result;

int lis(int start) {
	
	//if(start == n-1) return 1;
	
	int& ret = cache[start];
	
	if(ret != -1) return ret;

	ret = 1;
	
	for(int next = start + 1; next < n; ++next) {
		if(a[start] < a[next])
			ret = max(ret, lis(next) + 1);
	}	
	
	return ret;
}

int main() {
	
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	
	for(int i = 0; i < n; ++i){
		result = max(result, lis(i));
	}
	
	printf("%d", result);
}
