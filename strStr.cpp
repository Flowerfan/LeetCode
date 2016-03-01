#include<string>
using namespace std;

//my solution
class Solution {
public:
	int strStr(string haystack, string needle) {
		int len1 = haystack.size(), len2 = needle.size();
		if (len2 > len1)
			return -1;
		for (int i = 0; i <= len1 - len2 ; i++) {
			int flag = 0;
			for (int j = 0; j < len2; j++) {
				if (haystack[i + j] != needle[j]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				return i;
		}
		return -1;	
	}
};

//other solution
//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		int nH = haystack.length();
//		int nN = needle.length();
//		if (nN == 0)
//			return 0;
//		if (nN>nH)
//			return -1;
//		for (int i = 0; i <= nH - nN; i++)
//			if (haystack.substr(i, nN) == needle)
//				return i;x
//
//		return -1;
//	}
//};