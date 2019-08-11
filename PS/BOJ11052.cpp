#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int p[1001];
int cache[1001];

int card(int value) {
	if(value == 1) return p[1];
	
	int& ret = cache[value];

	if(ret != -1) return ret;

	ret = p[value];
	
	for(int i = 1; i <= value; ++i) {
		ret = max(ret, card(value-i)+ p[i]);
	}
	
	return ret;
}


int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	
	for(int i=1; i <= n; ++i){
		scanf("%d", &p[i]);
	}	
	
	printf("%d", card(n));
}
