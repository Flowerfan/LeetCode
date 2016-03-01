#include <vector>
using namespace std;


class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int arr[9];
		for (int i = 0; i < board.size(); i++) {
			for (int k = 0; k < 9; k++)
				arr[k] = 0;
			for (int j = 0; j < board.size(); j++) {
				if (board[i][j] == '.')
					continue;
				if (arr[int(board[i][j]) - 49]++ != 0)
					return false;
			}
		}
		for (int i = 0; i < board.size(); i++) {
			for (int k = 0; k < 9; k++)
				arr[k] = 0;
			for (int j = 0; j < board.size(); j++) {
				if (board[j][i] == '.')
					continue;
				if (arr[int(board[j][i]) - 49]++ != 0 )
					return false;
			}
		}
		for (int i = 0; i < board.size(); i = i + 3) {
			for (int j = 0; j < board.size(); j = j + 3) {
				for (int k = 0; k < 9; k++)
					arr[k] = 0;
				for (int m = i; m < i + 3; m++) {
					for (int n = j; n < j + 3; n++) {
						if (board[m][n] == '.')
							continue;
						if (arr[int(board[m][n]) - 49]++ != 0)
							return false;
					}
				}
			}
		}
		return true;
	}
};

// other simple solution
//class Solution
//{
//public:
//	bool isValidSudoku(vector<vector<char> > &board)
//	{
//		int used1[9][9] = { 0 }, used2[9][9] = { 0 }, used3[9][9] = { 0 };
//
//		for (int i = 0; i < board.size(); ++i)
//			for (int j = 0; j < board[i].size(); ++j)
//				if (board[i][j] != '.')
//				{
//					int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
//					if (used1[i][num] || used2[j][num] || used3[k][num])
//						return false;
//					used1[i][num] = used2[j][num] = used3[k][num] = 1;
//				}
//
//		return true;
//	}
//};