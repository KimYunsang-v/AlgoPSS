#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int trial[501]; // �ش� �������� ��� ���� ��� 
int reached[501]; // �ش� ���������� ����� ��� 
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
	
	// �������� ���� ��, �� ���� ���������� ������ ��
	// ������ ���� vector<pair<k, v>>�� ������
	// sort �Լ��� ���ٸ� �̿��Ͽ� �ذ�
	vector<pair<int, double>> v(ratio.begin(), ratio.end());
	sort(v.begin(), v.end(), [](const pair<int, double> &a, const pair<int, double> &b) {
		return a.second != b.second ? a.second > b.second : b.first > a.first;
	});
	
	
    for(auto &p: v){
		answer.push_back(p.first);
	}
    
    return answer;
}


