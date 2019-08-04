#include <iostream>
#include<cassert>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int n, m;
bool areFriends[10][10];

//int countPairings(bool taken[10]) {
//	// 기저 사례 : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾앗으니 종료한다.
//	// 한 사람이라도 짝이 안지어져 있으면 finished = false 가 됨 ! => 종료 안 됨 
//	bool finished = true;
//	for (int i = 0; i < n ; ++i) if (!taken[i]) finished = false;	
//	if(finished) return 1;
//	int ret = 0;
//	// 서로 친구인 두 학생을 찾아 짝을 지어 준다.
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
	// 남은 학생들 중 가장 번호가 빠른 학생을 찾는다. 
	int firstFree = -1;
	for(int i = 0; i < n; ++i) {
		if(!taken[i]){
			firstFree = i;
			break;
		}
	}
	// 기저 사례 : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다. 
	if(firstFree == -1) return 1;
	
	int ret = 0;
	// 이 학생과 짝지을 학생을 결정한다.
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
	cin >> cases; // 테스트 케이스 입력 
	while(cases--) { // 테스트 케이스 0보다 클 때 실행 
		cin >> n >> m;  // 친구 수 , 짝 수 입력 
		assert(n <= 10); // 친구 수 가 10보다 작은 지 확인 
		memset(areFriends, 0, sizeof(areFriends)); // 친구 짝 0으로 초기화 
		for(int i = 0; i < (m); i++) { // 짝 수 만큼 실행 
			int a, b; 
			cin >> a >> b; // 친구 1 , 2 입력 
			assert(0 <= a && a < n && 0 <= b && b < n); // 입력 받은 친구가 친구 수 내에 있는 지 확인 
			assert(!areFriends[a][b]); // 이미 입력받은 친구 쌍이 아닌지 확인 
			areFriends[a][b] = areFriends[b][a] = true; // 친구 쌍 등록 
		}
		bool taken[10]; 
		memset(taken, 0, sizeof(taken)); // 함수 내에서 n까지만 확인하기 때문에 10으로 선언하고 함수 호출 가능 
		cout << countPairings(taken) << endl;
	}	
}
