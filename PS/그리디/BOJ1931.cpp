#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N; 
int BEGIN[100001], END[100001];

int schedule() {
	//일찍 끝나는 순서대로 정렬
	vector<pair<int,int> > order;
	for(int i=0; i < N; ++i){
		order.push_back(make_pair(END[i], BEGIN[i]));
	} 	
	sort(order.begin(), order.end());
	
	// earliest: 다음 회의가 시작할 수 있는 가장 빠른 시간
	// selected: 지금까지 선택한 회의의 수
	int earliest = 0, selected = 0;
	for(int i=0; i < order.size(); ++i) {
		int meetingBegin = order[i].second, meetingEnd = order[i].first;
		
		if(earliest <= meetingBegin){
			// earliest를 마지막 회의가 끝난 시간 이후로 갱신한다.
			earliest = meetingEnd;
			++selected; 
		}
	}
	
	return selected;
}

int main() {
	scanf("%d", &N);
	
	for(int i = 0; i < N; ++i){
		scanf("%d %d", &BEGIN[i], &END[i]);
	}
	
	printf("%d", schedule());
}
