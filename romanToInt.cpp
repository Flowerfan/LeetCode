//I:1 V:5 X:10 L:50 C:100 D:500 M:1000
#include<string>
using namespace std;
//my solution
class Solution {
public:
	int romanToInt(string s) {
		int result = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == 'M')
				result += 1000;
			else if (s[i] == 'D')
				result += 500;
			else if (s[i] == 'C')
				result += (s[i + 1] == 'D' || s[i + 1] == 'M') ? -100 : 100;
			else if (s[i] == 'L')
				result += 50;
			else if (s[i] == 'X')
				result += (s[i + 1] == 'C' || s[i + 1] == 'L') ? -10 : 10;
			else if (s[i] == 'V')
				result += 5;
			else if (s[i] == 'I')
				result += (s[i + 1] == 'V' || s[i + 1] == 'X') ? -1 : 1;
		}
		switch (s[s.size() - 1]) {
		case 'M': result += 1000; break;
		case 'D': result += 500; break;
		case 'C': result += 100; break;
		case 'L': result += 50; break;
		case 'X': result += 10; break;
		case 'V': result += 5; break;
		case 'I': result += 1; break;
		}
		return result;
	}
};

//simple fast solution
//class Solution {
//public:
//	int romanToInt(string s) {
//		int result = 0;
//		int map[256];
//		map['I'] = 1; map['V'] = 5; map['X'] = 10; map['L'] = 50; map['C'] = 100; map['D'] = 500; map['M'] = 1000;
//		for (int i = 0; i<s.size(); i++) {
//			if (i + 1<s.size() && map[s[i]]<map[s[i + 1]]) result -= map[s[i]];
//			else result += map[s[i]];
//		}
//		return result;
//	}
//};