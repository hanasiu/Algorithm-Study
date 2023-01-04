#include <iostream>
#include <vector>


using namespace std;

//char cake[8] = { 'a', 'b', 'c', 'a', 'd', 'b', 'a' };
//                  a  c     a     d     a    b    a
int ReplaceAndRemove(int size, char s[]) {
	int write_idx = 0, a_count = 0; // 
	for (int i = 0; i < size; ++i) {
		if (s[i] != 'b') { // 
			s[write_idx++] = s[i]; // 옮겨 씀
		} 
		if (s[i] == 'a') { // a를 셈
			++a_count;
		}
	} 
	cout << write_idx << endl;

	int cur_idx = write_idx - 1; //  ++시킨 걸 감소 시켜줌
	write_idx = write_idx + a_count - 1; // cur_idx에서 a_count를 더해줌
	cout << write_idx << endl;
	const int final_size = write_idx + 1; // 사이즈는 인덱스보다 하나 큼
	while (cur_idx >= 0) {
		if (s[cur_idx] == 'a') {
			s[write_idx--] == 'd';
			s[write_idx--] == 'd';
		}
		else {
			s[write_idx--] = s[cur_idx];
		}
		--cur_idx;
	}
	return final_size;
}



int main()
{
	char cake[8] = { 'a', 'b', 'c', 'a', 'd', 'b', 'a' };
	int i = ReplaceAndRemove(7, cake);
	for (int i = 0; i < 8; ++i) {
		cout << cake[i] << " ";
	}

	return 0;
}
