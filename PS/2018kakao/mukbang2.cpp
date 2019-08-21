#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
	return p1.second < p2.second;
}

int solution(vector<int> food_times, long long k) {

    int size = food_times.size();
    
    vector<pair<int, int> > tmp(size);
    
    for(int i =0; i < size; ++i)
    	tmp[i] = { food_times[i] , i + 1};
    	
    sort(tmp.begin(), tmp.end()); // 먹는 시간이 적은 순서대로 
    
    long long before = 0;
    long long sum = 0; // 누적 시간 
    for(int i = 0; i < size; ++i) {
    	before = sum;
    	if((i == 0) && ((size - i) * tmp[0].first <= k)) {
    		sum = (size - i)*tmp[i].first;
    		continue;
		} else if (i != 0) {
			sum += ((tmp[i].first - tmp[i - 1].first)* (size - i));
			if (sum <= k) continue;
		}
		// k 에서 k 보다 커지기 전 누락시간 뺌 
		// ==> 이번 회차에 돌 횟수 
		k -= before; 
		sort(tmp.begin() + i, tmp.end(), cmp); // 인덱스 순서대로 소팅 
		int cnt = size - i; // 남아 있는 음식 갯수
		return tmp[i + (k%cnt)].second; // 돌 횟수 % 남은 사이즈 => 칸수 이동
	}
	return -1;
}
