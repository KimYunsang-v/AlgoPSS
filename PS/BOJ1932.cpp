#include    <stdio.h>
#include    <algorithm>
 
using namespace std;
 
static int triangle[555][555];
 
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
        scanf("%d", &triangle[i][j]);
 
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j <= i; ++j)
        {
        	// 이거는 맨 아래서 부터 최대값 찾기
			// 마지막엔 젤 위에서의 최대값이 나옴 
            triangle[i - 1][j] += max(triangle[i][j], triangle[i][j + 1]);
        }
    }
 
    printf("%d", triangle[1][1]);
 
    return 0;
}
