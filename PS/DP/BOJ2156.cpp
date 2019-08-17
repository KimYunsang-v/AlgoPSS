#include    <stdio.h>
#include    <algorithm>
 
using namespace std;
 
int n;
int dp[10001];
int a[10001];

int main() {
	
	scanf("%d", &n);
	
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	
	dp[1] = a[1];
	
	for(int i = 2; i <= n; ++i){
		 // 현 단계 안먹음 or 전 단계 안먹음
		 // 현 단계 안먹음 == dp[i - 1]   ===>  전 단계 안먹음 == dp[i - 2]  ===> 전전 단계 안먹음 == dp[i - 3] 
		dp[i] = max(dp[i-1], dp[i-2] + a[i]);
		
		// 위에 두 값과 전단계 먹고 현 단계 먹는 경우
		dp[i] = max(dp[i], dp[i-3] + a[i-1] + a[i]);
	}
	
	printf("%d", dp[n]);
	
	return 0;
}
