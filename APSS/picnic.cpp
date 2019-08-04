#include <iostream>
#include<cassert>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int n, m;
bool areFriends[10][10];

//int countPairings(bool taken[10]) {
//	// ���� ��� : ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
//	// �� ����̶� ¦�� �������� ������ finished = false �� �� ! => ���� �� �� 
//	bool finished = true;
//	for (int i = 0; i < n ; ++i) if (!taken[i]) finished = false;	
//	if(finished) return 1;
//	int ret = 0;
//	// ���� ģ���� �� �л��� ã�� ¦�� ���� �ش�.
//	for(int i = 0; i < n; ++i)
//		for(int j = 0; j < n; j++)
//			if(!taken[i] && !taken[j] && areFriends[i][j]) {
//				taken[i] = taken[j] = true;
//				ret += countPairings(taken);
//				taken[i] = taken[j] = false;
//			}	 
//	return ret;
//}

int countPairings(bool taken[10]) {
	// ���� �л��� �� ���� ��ȣ�� ���� �л��� ã�´�. 
	int firstFree = -1;
	for(int i = 0; i < n; ++i) {
		if(!taken[i]){
			firstFree = i;
			break;
		}
	}
	// ���� ��� : ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�. 
	if(firstFree == -1) return 1;
	
	int ret = 0;
	// �� �л��� ¦���� �л��� �����Ѵ�.
	for(int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if(!taken[pairWith] && areFriends[firstFree][pairWith]){
			taken[pairWith] = taken[firstFree] = true;
			ret += countPairings(taken);
			taken[pairWith] = taken[firstFree] = false;
		}
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases; // �׽�Ʈ ���̽� �Է� 
	while(cases--) { // �׽�Ʈ ���̽� 0���� Ŭ �� ���� 
		cin >> n >> m;  // ģ�� �� , ¦ �� �Է� 
		assert(n <= 10); // ģ�� �� �� 10���� ���� �� Ȯ�� 
		memset(areFriends, 0, sizeof(areFriends)); // ģ�� ¦ 0���� �ʱ�ȭ 
		for(int i = 0; i < (m); i++) { // ¦ �� ��ŭ ���� 
			int a, b; 
			cin >> a >> b; // ģ�� 1 , 2 �Է� 
			assert(0 <= a && a < n && 0 <= b && b < n); // �Է� ���� ģ���� ģ�� �� ���� �ִ� �� Ȯ�� 
			assert(!areFriends[a][b]); // �̹� �Է¹��� ģ�� ���� �ƴ��� Ȯ�� 
			areFriends[a][b] = areFriends[b][a] = true; // ģ�� �� ��� 
		}
		bool taken[10]; 
		memset(taken, 0, sizeof(taken)); // �Լ� ������ n������ Ȯ���ϱ� ������ 10���� �����ϰ� �Լ� ȣ�� ���� 
		cout << countPairings(taken) << endl;
	}	
}
