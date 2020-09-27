/*------------------------------------------------------------------|
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"
示例 2:

输入: n = 4, k = 9
输出: "2314"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	旋转
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：5.8 MB, 在所有 C++ 提交中击败了83.73%的用户			
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;


string getPermutation(int n, int k)
{
	if (n == 1)
	{
		return "1";
	}

	int factorial[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
	vector<char> temp;

	for (int i = 1; i <= n; i++)
	{
		temp.push_back(i + '0');
	}

	string res;
	k--;													/*	计数是从0开始的，因此k要减一	*/

	for (int i = 0; i < n; i++)
	{
		int ans = k / factorial[n - i - 1];					/*	从(n-1)!除到1!,如果值为0就说明没有比(n-1)!更大的排列，所以按顺序填数	*/
		res.push_back(temp[ans]);
		k %= factorial[n - i - 1];							/*	去除前面的排列总数	*/
		temp.erase(temp.begin() + ans);						/*	删去待填数组的元素，不存在的元素说明已经填过了	*/
	}

	return res;
}

int main()
{
	int n = 3;
	int k = 2;

	//
	
	//
	cout << getPermutation(n, k) << endl;
}
