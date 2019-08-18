#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N; 
int BEGIN[100001], END[100001];

int schedule() {
	//���� ������ ������� ����
	vector<pair<int,int> > order;
	for(int i=0; i < N; ++i){
		order.push_back(make_pair(END[i], BEGIN[i]));
	} 	
	sort(order.begin(), order.end());
	
	// earliest: ���� ȸ�ǰ� ������ �� �ִ� ���� ���� �ð�
	// selected: ���ݱ��� ������ ȸ���� ��
	int earliest = 0, selected = 0;
	for(int i=0; i < order.size(); ++i) {
		int meetingBegin = order[i].second, meetingEnd = order[i].first;
		
		if(earliest <= meetingBegin){
			// earliest�� ������ ȸ�ǰ� ���� �ð� ���ķ� �����Ѵ�.
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
