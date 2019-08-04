#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>


using namespace std;

//// ���ϵ�ī�� ���� w�� ���ڿ� w�� �����Ǵ��� ���θ� ��ȯ�Ѵ�. 
//bool match(const string& w, const string& s) {
//	printf("%s  %s \n", w.c_str(), s.c_str());
//	
//	// w[pos]�� s[pos]�� ���糪����. 
//	int pos = 0;
//	while(pos < s.size() && pos < w.size() &&
//			(w[pos] == '?' || w[pos] == s[pos]))
//	{
//		++pos;
//	}		
//	
//	// ���̻� ������ �� ������ �� while���� �������� Ȯ���Ѵ�.
//	// 2. ���� ���� �����ؼ� ���� ���: ���ڿ��� ������� ������
//	if(pos == w.size()) {
//		return  pos == s.size();
//	}
//	
//	// 4. *�� ������ ���� ���: *�� �� ���ڸ� �����ؾ� ���� ��� ȣ���ϸ鼭 Ȯ���Ѵ�. 
//	if(w[pos] == '*'){
//		for(int skip = 0; pos + skip <= s.size(); ++skip ){
//			if(match(w.substr(pos+1), s.substr(pos+skip))){
//				return true;
//			}
//		}
//	} 
//	
//	//�� ���� ��쿡�� ��� �������� �ʴ´�.
//	return false;	
//}




// -1�� ���� ���� ������ �ʾ����� �ǹ��Ѵ�.
// 1�� �ش� �Էµ��� ���� �������� �ǹ��Ѵ�.
// 0�� �ش� �Էµ��� ���� �������� ������ �ǹ��Ѵ�.
int cache[101][101];
//���ϰ� ���ڿ� 
string W, S;
// ���ϵ�ī�� ���� W[w..]�� ���ڿ� S[s..]�� �����Ǵ��� ���θ� ��ȯ�Ѵ�.
bool matchMemoized(int w, int s) { 	
	// �޸������̼�
	int& ret = cache[w][s];
	if(ret != -1) return ret;
	
	// W[w] �� S[s]�� ���糪����.
	while(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])){
		++w;
		++s;
	} 
	
	//���̻� ������ �� ������ �� while���� �������� Ȯ���Ѵ�.
	//2. ���� ���� �����ؼ� ���� ���: ���ڿ��� ������� ��
	if(w == W.size()) return ret = (s == S.size());
	// 4. *�� ������ ���� ���: ���ڿ��� ������� ��
	if(W[w] == '*'){
		for(int skip = 0; skip+s <= S.size(); ++skip){
			if(matchMemoized(w+1, s+skip)){
				return ret = 1;
			}
		}
	}
	
	//3. �� ���� ��쿡�� ��� �������� �ʴ´�.
	return ret = 0 ;	
}

int main(){
	
//	printf("%d \n", match("*e*p", "heap"));
//	
//	printf("%d", match("*e*p", "hellc"));

	memset(cache, -1, sizeof(cache));
	
	W = "*e*p";
	S = "heapll";
	printf("%d \n" , matchMemoized(0,0));
	
}

