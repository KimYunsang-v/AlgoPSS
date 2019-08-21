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
    	
    sort(tmp.begin(), tmp.end()); // �Դ� �ð��� ���� ������� 
    
    long long before = 0;
    long long sum = 0; // ���� �ð� 
    for(int i = 0; i < size; ++i) {
    	before = sum;
    	if((i == 0) && ((size - i) * tmp[0].first <= k)) {
    		sum = (size - i)*tmp[i].first;
    		continue;
		} else if (i != 0) {
			sum += ((tmp[i].first - tmp[i - 1].first)* (size - i));
			if (sum <= k) continue;
		}
		// k ���� k ���� Ŀ���� �� �����ð� �� 
		// ==> �̹� ȸ���� �� Ƚ�� 
		k -= before; 
		sort(tmp.begin() + i, tmp.end(), cmp); // �ε��� ������� ���� 
		int cnt = size - i; // ���� �ִ� ���� ����
		return tmp[i + (k%cnt)].second; // �� Ƚ�� % ���� ������ => ĭ�� �̵�
	}
	return -1;
}
