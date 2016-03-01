#include<vector>
using namespace std;

//my solution
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()) return 0;
		int length = 0;
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] == val) {
				nums[i] = nums[nums.size() - 1];
				nums.pop_back();
				i--;
			}
			else length++;
		}
		return (nums[length] == val) ? length : (length + 1);
	}
};

//other solution

//int removeElement(vector<int>& nums, int val) {
//	int slow = 0;
//	for (int i = 0; i<nums.size(); i++) {
//		if (nums[i] != val)
//			nums[slow++] = nums[i];
//	}
//	return slow;
//}