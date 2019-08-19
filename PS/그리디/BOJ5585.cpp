#include <stdio.h>

using namespace std;

int n; 
int g[6];

int main() {
	
	scanf("%d", &n);
	
	n = 1000 - n;

	int i,count = 0;
	int money = 500;
	
	
	while(n) {
		//printf("before count = %d , n = %d , money = %d \n" , count, n, money);
		if(n >= money){
			count += n / money;
			n %= money;
		}
		if(i % 2 == 0)	{
			money /= 5;		
		}else{
			money /= 2;
		}
		++i;
		//printf("after count = %d , n = %d , money = %d \n" , count, n, money);
	}
	
	printf("%d", count);
	
	return 0;
	
}
