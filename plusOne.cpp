
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int flag = 0;
		if (digits[digits.size() - 1] == 9) {
			digits[digits.size() - 1] = 0;
			flag = 1;
		}
		else digits[digits.size() - 1] += 1;
		for (int i = digits.size() -2; i >= 0; i--) {
			if (flag == 1) {
				if (digits[i] == 9) {
					digits[i] = 0;
					flag = 1;
				}
				else {
					digits[i]++;
					flag = 0;
				}
			}
			else
				break;
		}
		if (flag == 1)
			digits.insert(digits.begin(),1);
		return digits;
	}
};


//other quick solution
//class Solution {
//public:
//	vector<int> plusOne(vector<int>& digits) {
//		bool carry = true;
//		for (int i = digits.size() - 1; i >= 0 && carry; i--) {
//			carry = (digits[i] + 1) / 10;
//			digits[i] = (digits[i] + 1) % 10;
//		}
//		if (carry)  digits.insert(digits.begin(), 1);
//		return digits;
//	}
//};