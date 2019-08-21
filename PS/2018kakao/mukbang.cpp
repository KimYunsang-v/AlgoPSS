#include <string>
#include <vector>

using namespace std;

// 효율성에서 통과 x
// 다른 알고리즘 필요 

int solution(vector<int> food_times, long long k) {
    int answer = 0;    
    int i=0, zeroCount=0;
    
    while(k+1) {
    	if(i >= food_times.size()){
    		i = 0; continue;
		}
    	if(food_times[i] == 0) {
    		i++;
    		zeroCount++;
    		if(zeroCount == food_times.size()){
    			return -1;
			}
			continue;
		}else{
			zeroCount = 0;
			if(k == 0) break;
			
			food_times[i]--;
			k--;
			i++;
		}
	}
    answer = i+1;
    return answer;
}

int main() {
	
	vector<int> food_times;
	food_times.push_back(3);
	food_times.push_back(1);
	food_times.push_back(2);
	printf("%d", solution(food_times, 5));
	
	return 0; 
	
}
