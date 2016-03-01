#include <iostream>
#include <string>
#include "vector"
using namespace std;


class Solution {
public:
	int reverse(int x) {
		if (x == 0)
			return x;
		int flag = 1;
		if (x < 0) {
			flag = -1;
			x = -x;
		}
		double inverse_x = 0;
		while (x/10 != 0 || x%10 != 0) {
			inverse_x = 10 * inverse_x + (x % 10);
			x /= 10;
			if (inverse_x * flag > INT_MAX || inverse_x * flag < INT_MIN)
				return 0;
		}
		return flag*inverse_x;
	}
};

