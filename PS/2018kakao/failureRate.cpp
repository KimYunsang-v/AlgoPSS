#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int trial[501]; // 해당 스테이지 통과 못한 사람 
int reached[501]; // 해당 스테이지를 통과한 사람 
map<int, double> ratio;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int totalChallenger = stages.size();
    
    for(int i=0; i < stages.size(); ++i) {
    	trial[stages[i]]++;
	}
    
    reached[0] = totalChallenger;
    for(int i=1; i <= N; ++i) {
    	reached[i] = reached[i-1] - trial[i-1];
    	if(trial[i] == 0) {
    		ratio[i] = 0;
		}else{
			ratio[i] = trial[i] / (double) reached[i];
		}
	}
	
	// 실패율이 같을 때, 더 낮은 스테이지가 오도록 함
	// 정렬을 위해 vector<pair<k, v>>로 저장함
	// sort 함수와 람다를 이용하여 해결
	vector<pair<int, double>> v(ratio.begin(), ratio.end());
	sort(v.begin(), v.end(), [](const pair<int, double> &a, const pair<int, double> &b) {
		return a.second != b.second ? a.second > b.second : b.first > a.first;
	});
	
	
    for(auto &p: v){
		answer.push_back(p.first);
	}
    
    return answer;
}


