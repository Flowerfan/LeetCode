#include <vector>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
	string countAndSay(int n) {
		string ss1 = "1", ss2 = "";
		int num = n;
		int count = 1;
		string sum = "";
		for (int i = 1; i < n; i++) {
			char c = ss1[0];
			count = 1;
			ss2 = "";
			for (int j = 1; j < ss1.size(); j++) {
				if (c == ss1[j])
					count++;
				else {
					ss2 = (ss2 + char(count + 48)) + c;
					count = 1;
					c = ss1[j];
				}
			}
			ss2 = (ss2 + char(count + 48)) + c;
			ss1 = ss2;
		}
		return ss1;
	}
};

//other solution : recursive method

//string countAndSay(int n) {
//	if (n == 1) return "1";
//	string tmp = countAndSay(n - 1) + ' ';
//	string res = "";
//	int count = 1;
//	for (int i = 1; i < tmp.size(); ++i) {
//		if (tmp[i] == tmp[i - 1]) count++;
//		else {
//			stringstream ss;
//			ss << count;
//			res += ss.str() + tmp[i - 1];
//			count = 1;
//		}
//	}
//	return res;
//}