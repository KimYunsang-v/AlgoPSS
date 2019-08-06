#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
int dp[1000001] = {0};

int makeOne(int num){
	
	if(num == 1 ) return 0;
	
	if(dp[num] != 0) return dp[num];
	
	//int& ret = dp[num];
	//int ret = 1;
	if(num % 3 == 0){
		dp[num] = makeOne(num/3) + 1;
	}
	
	if(num % 2 == 0){
		if(dp[num] == 0) dp[num] = makeOne(num/2) + 1;
		else dp[num] = min(dp[num], makeOne(num/2) + 1);
	}
	
	if(dp[num] == 0) dp[num] = makeOne(num-1) + 1;
	else dp[num] = min(dp[num], makeOne(num-1) + 1);
	
	return dp[num];
}


int main() {
	
	scanf("%d", &n);
	
	
	dp[2] = dp[3] = 1;
	
	printf("%d", makeOne(n));
	
	return 0;
} 
