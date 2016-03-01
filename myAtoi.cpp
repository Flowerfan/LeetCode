#include <iostream>
using namespace std;


//my solution
class Solution {
public:
	int myAtoi(string str) {
		if (str == "")
			return 0;
		double rev_s = 0;
		int flag = 1;
		int sign_count = 0;
		for (int i = 0; i < str.size(); i++) {
			if (sign_count == 0 && rev_s == 0) {
				if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
					continue;
				if (str[i] == '-') {
					sign_count++;
					flag = -1;
				}
				else if (str[i] == '+') {
					sign_count++;
				}
				else if (int(str[i]) < 48 || int(str[i]) > 57)
					return 0;
				else
					rev_s = int(str[i]) - 48;

			}
			else if (int(str[i]) < 48 || int(str[i]) > 57)
				break;
			else
				rev_s = 10 * rev_s + int(str[i]) - 48;
				
		}
		if (rev_s * flag > INT_MAX)
			return INT_MAX;
		else if (rev_s * flag < INT_MIN)
			return INT_MIN;
		return flag * rev_s;

	}
};


//10 line solution

int myAtoi(string str) {
	if (str.empty()) return 0;
	int i = 0, sign = 1;
	while (i + 1 < str.size() && isspace(str[i])) ++i;
	long res = 0;
	if (str[i] == '-' || str[i] == '+') sign = 44 - str[i++];
	while (i < str.size()) {
		if (isdigit(str[i])) res = 10 * res + str[i++] - '0';
		else return res * sign;
		if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
	}
	return res * sign;
}