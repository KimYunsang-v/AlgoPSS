

// ���ڿ����� ���̰� �־��� �� �ϳ��� ��ġ�� �ּ� ����� ��ȯ�Ѵ�.
int concat(const vector<int>& lengths)  {
	//�ּ� ť�� �����Ѵ�.
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i = 0; i < lengths.size(); ++i) 
		pq.push(lengths[i]);
	int ret = 0;
	
	//���Ұ� �ϳ� �̻� ���� ���� �ݺ��Ѵ�.
	while(pq.size() > 1) {
		//���� ª�� ���ڿ� �� ���� ã�Ƽ� ��ġ�� ť�� �ִ´�.
		int min1 = pq.top(); pq.pop();
		int min2 = pq.top(); pq.pop();
		pq.push(min1 + min2) ;
		ret += min1 + min2;
	}
	
	return ret;
}
