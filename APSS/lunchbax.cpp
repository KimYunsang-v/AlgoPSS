
int n, e[MAX_N], m[MAX_N];
int heat() {
	//어느 순서로 데워야 할지를 정한다.
	vector<pair<int,int> > order;
	for(int i = 0; i < n; ++i) 
		order.push_back(make_pair(-e[i], i));  // -로 넣는 이유 : 정렬할때 오래걸리는 것이 첫번째로 옴 
		
	sort(order.begin(), order.end());
	
	//해당 순서대로 데워먹는 과정을 시뮬레이션한다.
	int ret = 0, beginEat = 0;
	for(int i =0; i < n; ++i) {
		int box = order[i].second;
		beginEat += m[box];
		/* max parameter 의 ret은 이전 박스를 데우고 먹는데 까지 걸리는 시간 ! 
		 * max parameter 의 beginEat + e[box] 는 현재 박스를 데우고 먹는데 까지 걸리는 시간 !
		 * max를 쓰는 이유는 이 전 박스를 데우고 먹는 시간 vs
		 * 전 박스 만드는 시간 ~ (현재 박스 만든느 시간 + 현재 박스 먹는 시간) 
		 * 전 박스 먹기 전까지 현재 박스 만들고 먹으면 시간 추가 x 
		 */
		ret = max(ret, beginEat + e[box]); 
	}
	
	return ret;
}
