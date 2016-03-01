#include<string>
#include<stack>
using namespace std;


//stack 
class Solution {
public:
	bool isValid(string s) {
		stack<char> ss;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[' || s[i] == '(' || s[i] == '{')
				ss.push(s[i]);
			else if (ss.empty()|| (s[i] - ss.top()) > 2) return false;
			else ss.pop();
		}
		return ss.empty();
	}
};

//quick solution
//class Solution {
//public:
//	bool isValid(string s) {
//		stack<char> st;
//		for (auto&& x : s) {
//			if (x == '(' || x == '[' || x == '{') st.push(x);
//			else
//				if (st.empty() || (abs(x - st.top())>2)) return false;
//				else st.pop();
//		}
//		return st.empty();
//	}
//};