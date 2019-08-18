
int n, e[MAX_N], m[MAX_N];
int heat() {
	//��� ������ ������ ������ ���Ѵ�.
	vector<pair<int,int> > order;
	for(int i = 0; i < n; ++i) 
		order.push_back(make_pair(-e[i], i));  // -�� �ִ� ���� : �����Ҷ� �����ɸ��� ���� ù��°�� �� 
		
	sort(order.begin(), order.end());
	
	//�ش� ������� �����Դ� ������ �ùķ��̼��Ѵ�.
	int ret = 0, beginEat = 0;
	for(int i =0; i < n; ++i) {
		int box = order[i].second;
		beginEat += m[box];
		/* max parameter �� ret�� ���� �ڽ��� ����� �Դµ� ���� �ɸ��� �ð� ! 
		 * max parameter �� beginEat + e[box] �� ���� �ڽ��� ����� �Դµ� ���� �ɸ��� �ð� !
		 * max�� ���� ������ �� �� �ڽ��� ����� �Դ� �ð� vs
		 * �� �ڽ� ����� �ð� ~ (���� �ڽ� ����� �ð� + ���� �ڽ� �Դ� �ð�) 
		 * �� �ڽ� �Ա� ������ ���� �ڽ� ����� ������ �ð� �߰� x 
		 */
		ret = max(ret, beginEat + e[box]); 
	}
	
	return ret;
}
