

// 문자열들의 길이가 주어질 때 하나로 합치는 최소 비용을 반환한다.
int concat(const vector<int>& lengths)  {
	//최소 큐를 선언한다.
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i = 0; i < lengths.size(); ++i) 
		pq.push(lengths[i]);
	int ret = 0;
	
	//원소가 하나 이상 남은 동안 반복한다.
	while(pq.size() > 1) {
		//가장 짧은 문자열 두 개를 찾아서 합치고 큐에 넣는다.
		int min1 = pq.top(); pq.pop();
		int min2 = pq.top(); pq.pop();
		pq.push(min1 + min2) ;
		ret += min1 + min2;
	}
	
	return ret;
}
