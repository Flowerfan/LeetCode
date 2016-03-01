#include<string>
#include<vector>
using namespace std;



class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		string prefix = "";
		for (int i = 0; i < strs[0].size(); i++) {
			int count = 1;
			for (int j = 1; j < strs.size(); j++) {
				if (strs[0][i] != strs[j][i])
					break;
				else count++;
			}
			if (count != strs.size())
				return prefix;
			prefix += strs[0][i];
		}
		return prefix;
	}
};