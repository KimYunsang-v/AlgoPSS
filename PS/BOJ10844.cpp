#include <algorithm>
#include <stdio.h>

using namespace std;

const int mod = 1000000000;
int n;
long long ret;
int dp[101][11];

int main() {
	
	scanf("%d", &n);
	
	// 0을 제외한 모든 숫자가 한번씩 나옴 
	for (int i = 1; i <= 9 ; ++i) dp[1][i] = 1;
	
	
	
	for(int i = 2; i <= n; ++i){
		for(int j = 0; j <= 9; ++j){
			// 현재 숫자가 나오려면 이 전 상황에서 (현재 -1 , 현재 + 1 ) 경우에 현재 숫자 (j) 가 나오기 때문에
			//  dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) 
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
		}
	}
	
	for(int i = 0; i <= 9; ++i){
		ret = ret + dp[n][i];
	}
	
	printf("%lld", ret % mod);
	
	return 0;
}
