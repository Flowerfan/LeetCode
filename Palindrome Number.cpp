//my solution
class Solution {
public:
	bool isPalindrome(int x) {
		double rev_x = 0;
		int o_x = x;
		while (x > 0) {
			rev_x = 10 * rev_x + x % 10;
			x /= 10;
		}
		return o_x == rev_x;
	}
};

//quick solution
//public class Solution {
//	public boolean isPalindrome(int x) {
//		if (x < 0)
//			return false;
//		int y = 0, x1 = 1;
//		while (x / x1 != 0) {
//			y = y * 10 + x % 10;
//			x /= 10;
//			x1 *= 10;
//		}
//		return y < 10 * x ? y == x : y / 10 == x;
//	}
//}