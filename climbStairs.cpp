class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0) return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		int ways = 0;
		int ones = 1, twos = 2;
		for (int i = 2; i < n; i++) {
			ways = ones + twos;
			ones = twos;
			twos = ways;
		}
		return ways;
	}
};