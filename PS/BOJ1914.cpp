#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int n;

void hanoi(int size, int start, int middle, int end){
	// ���� ��� : ������ �����̸� ������ �ű� 
	if( size == 1 ){
		printf("%d %d\n", start, end);
		return;
	}
	
	hanoi(size-1, start, end, middle ); // n-1 ���� 1�� -> 2�� (3�� ����) ���� �ű� 
	printf("%d %d\n", start, end); // ����ū ���� 1�� -> 3�� �ű�
	hanoi(size-1, middle, start, end); // �߰����� �Ű�� �ǵ��� 3������ �ű� ( 1�� ���� ) 	
 
}

int main() {
	
	
	scanf("%d", &n); 
	
	
	cout << pow(2, n);
	if(n <= 20){
		hanoi(n, 1, 2, 3);
	} else {
		// bigInteger ���� �ؾ� ��
		// 2 ^ n-1 �� ��� 
	}
	
	return 0;
}
