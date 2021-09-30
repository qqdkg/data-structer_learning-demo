#include "stdafx.h"
#include "TraceProblem.h"
#include <iostream>
#include <unordered_map>
using std::cout;
using std::cin;
using std::endl;
using std::unordered_map;

list<list<int>> res;

list<list<int>> permute(int nums[])
{
	vector<int> numArr = {1,2,3,4,5,6,7,8};
	list<int> track;
	backtrack(numArr, track);

	for (auto listblock : res)
	{
		for (auto listelem : listblock)
		{
			cout << listelem << " ";
		}
		cout << endl;
	}
	return res;
}

// 路径：记录在track中
// 选择列表 ：nums中不存在与track中的元素
// 结束条件：nums中的元素全部在track中出现
void backtrack(vector<int> numArr, list<int> track)
{
	// 触发结束条件
	if (numArr.size() == track.size())
	{
		res.emplace_back(track);
		return;
	}

	for (int i = 0; i < numArr.size(); ++i)
	{
		// 排除不合法的选择
		for (auto elem : track)
		{
			if (elem == numArr.at(i))
				continue;
		}

		// 做选择
		track.emplace_back(numArr.at(i));

		// 进入下一层决策树
		backtrack(numArr, track);

		// 取消选择
		track.pop_back();
	}

}

void fullpremut::dfs_nums(int a[], int k, int n)
{
	if (k == n)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		count++;
		return;
	}

	for (int i = k; i < n; i++)
	{
		// 回溯之前进行操作
		swap(a[i], a[k]);

		// 回溯
		dfs_nums(a, k + 1, n);

		// 回溯后撤销操作
		swap(a[i], a[k]);
	}
}

void fullpremut::dfs_nums(vector<int> a, int k, int n)
{
	if (k == n)
	{
		for (const auto &elem : a)
		{
			cout << elem << " ";
		}
		cout << endl;
		count++;
		return;
	}

	for (int i = k;i < n; ++i)
	{
		swap(a[i], a[k]);
		dfs_nums(a, k + 1, n);
		swap(a[i], a[k]);
	}
}

void fullpremut::dfs_str(vector<string> strVec_in, string str)
{
	// 终止条件
	if (str.size() == strVec_in.size())
	{
		strVec_out.emplace_back(str);
		count++;
		return;
	}

	int k = str.length();
	int n = strVec_in.size();

	string str_tmp = strVec_in.at(k);
	for (auto elem : str_tmp)
	{
		str += elem;
		dfs_str(strVec_in, str);
		str.pop_back();
	}
}

void fullpremut::dfs_str2(string str_in, string str)
{
	if (str.length() == strVec_in.size())
	{
		strVec_out.emplace_back(str);
		count++;
		return;
	}

	int k = str.length();

	for (auto elem : str_in)
	{
		str += elem;
		string temp = strVec_in.at(k);
		dfs_str2(temp, str);
		str.pop_back();
	}
}

void fullpremut::dfs_8Queen(int k, int n)
{
	if (k == n)
	{
		count++;
		if (b_Show8QueenResult)
		{
			cout << "第" << count << "种解" << endl;
			showChessBoard();
			cout << endl;
		}
		
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		// 做决策
		int row = k;
		int col = i;

		// 确定这个点是不是可以放皇后
		if (canPlaceAQueen(row, col))
		{
			SetQueenOnBoard(row, col);
			// 回溯
			dfs_8Queen(k + 1, n);
			// 取消决策
			SetBlankOnBoard(row, col);
		}
	}

}

bool fullpremut::canPlaceAQueen(int row, int col)
{
	bool flag = true;
	int col_max = chessboard.at(row).length();
	int row_max = chessboard.size();

	if (row == 1 && col == 1)
	{
		int dkg = 0;
	}

	// 判断同行有没有皇后
	for (int icol = 0; icol < col_max; ++icol)
	{
		if ( getChOnBoard(row,icol) == Queen && icol != col)
		{
			return false;
		}
	}

	// 判断同列有没有皇后
	for (int irow = 0; irow < row_max; ++irow)
	{
		if (getChOnBoard(irow,col) == Queen && irow != row)
		{
			return false;
		}
	}

	// 判断同斜线有没有皇后
	for (int i = 1; i < row_max; ++i)
	{
		int row_up = row + i;
		int row_down = row - i;
		int col_up = col + i;
		int col_down = col - i;

		if (row_up < row_max && col_up < col_max && getChOnBoard(row_up, col_up) == Queen)
		{
			return false;
		}
		if (row_up < row_max && col_down >= 0 && getChOnBoard(row_up, col_down) == Queen)
		{
			return false;
		}
		if (row_down >= 0 && col_up < col_max && getChOnBoard(row_down, col_up) == Queen)
		{
			return false;
		}
		if (row_down >= 0 && col_down >= 0 && getChOnBoard(row_down, col_down) == Queen)
		{
			return false;
		}
	}
	return flag;
}

inline char fullpremut::getChOnBoard(int row, int col)
{
	return chessboard.at(row)[col];
}

void fullpremut::SetChOnBoard(int row, int col, char ch)
{
	if (chessboard.at(row)[col] != Queen)
	{
		chessboard.at(row)[col] = ch;
	}
}

void fullpremut::SetQueenOnBoard(int row, int col)
{
	SetChOnBoard(row, col, Queen);
}

void fullpremut::SetBlankOnBoard(int row, int col)
{
	chessboard.at(row)[col] = blank;
}

void fullpremut::SetBadPointOnBoard(char ch)
{
	int n = chessboard.size();
	for (int irow = 0; irow < n; irow++)
	{
		for (int icol = 0; icol < n; icol++)
		{
			if (canPlaceAQueen(irow, icol))
			{
				//cout << irow << " " << icol << " 可以放置皇后" << endl;
				SetChOnBoard(irow, icol, blank);
			}
			else
			{
				//cout << irow << " "<< icol << " 不可以放置皇后" << endl;
				SetChOnBoard(irow, icol, ch);
			}
		}
	}
}

void fullpremut::showChessBoard()
{
	for (auto strRow : chessboard)
	{
		for (auto ch : strRow)
			cout << ch;
		cout << endl;
	}
}

void fullpremut::numArr2strSet()
{
	// 存储键盘数字对应字符串的映射关系
	unordered_map<int, string> map;
	vector<string> strVec = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	for (int i = 0; i <= 9; i++)
	{
		map[i] = strVec[i];
	}

	// 输入电话号序列
	vector<int> nums = { 2,3 ,8,6};

	// 将输入的电话号码转换成对应的字符串
	vector<string> Vecin;
	for (auto elem : nums)
	{
		Vecin.emplace_back(map[elem]);
	}
	string str = "";
	dfs_str(Vecin, str);
	ShowAll(strVec_out);
	cout << "总组合数 : " << count << endl;
}

void fullpremut::Test_dfs_nums()
{
	count = 0;			// 计数初始化
	vector<int> arr = { 1,2,3,4,5 };
	int n = arr.size();
	dfs_nums(arr, 0, 5);
	cout << "排列共有" << count << "种" << endl;
}

void fullpremut::Test_dfs_str()
{
	count = 0;
	strVec_in = { "abc","def" ,"ghi","jkl"};
	string str = "";
	//dfs_str2(strVec_in.at(0), str);
	dfs_str(strVec_in, str);
	ShowAll(strVec_out);
	cout << "总组合数 : " << count << endl;
}

// 八皇后问题
// 皇后可以走横竖和斜线的最多七步
// 也就是说Queen在八*八的棋盘里，攻击范围可以到达边界
//八皇后问题是问在八乘八的棋盘内可以稳定存在的八个皇后有几种可能的分布
// 这个问题是DFS（深度优先）搜索的典型问题
void fullpremut::Test_dfs_8Queen()
{

	int n = 8;

	// 初始化棋盘
	string tmp = "";
	for (int i = 0; i < n; ++i)
	{
		tmp += blank;
	}
	for (int i = 0; i < n; ++i)
	{
		chessboard.emplace_back(tmp);
	}

	//b_Show8QueenResult = true;

	dfs_8Queen(0, n);

	cout << n << "皇后问题" << endl;
	cout << "共有 " << count << "种解" << endl;

} // void fullpremut::Test_dfs_8Queen()

void fullpremut::swap(int & a, int & b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


// 找零钱问题，我们有几种面值的硬币，每种面值的硬币都有无线供应。要求计算可以完成找零的最少硬币数，如果无法完成找零则返回-1；

CoinProblem::CoinProblem() : min_count(INT_MAX), count(0), cur_V(0), goal_V(0)
{
}

#include<algorithm>
void CoinProblem::minCoinsTest()
{
	int V = 30;
	vector<int> coins = { 25,5,6 };
	int M = coins.size();
	sort(coins.begin(),coins.end());
	int minc = minCoins(V, coins, M);
	cout << "所需最少硬币数量为:" << minc << endl;
}

void CoinProblem::DFS_greed(int iter, vector<int>& coins, vector<int>& coinCount, int M)
{
	// 终止条件
	if (iter == M || cur_V >= goal_V)		// 遍历了所有面额的硬币 或者 当前金额超过或等于目标金额
	{
		if (cur_V == goal_V)
		{
			if (min_count > count)				// 求最小的的那个输出变量一开始要初始化一个很大的值
			{
				min_count = count;
			}
		}
		return ;
	}

	// 做决策

	for (int i = 0; (cur_V + i*coins.at(iter) <= goal_V); i++)
	{
		// 做决策
		cur_V += i*coins.at(iter);
		coinCount.at(iter)+=i;
		count += i;														// 之前忘记给待优化函数的优化目标赋值了

		// 回溯
		DFS_greed(iter + 1, coins, coinCount, M);

		// 取消决策
		cur_V -= i*coins.at(iter);
		coinCount.at(iter)-=i;
		count -= i;
	}

}

int CoinProblem::minCoins(int V, vector<int>& coins, int M)
{
	goal_V = V;

	// 创建每种面额硬币的使用计数
	vector<int> coinCount;
	for (int i = 0; i < coins.size(); i++)
	{
		coinCount.emplace_back(0);
	}

	DFS_greed(0, coins, coinCount, M);

	return (min_count == INT_MAX)?-1:min_count;
}

SiteProblem::SiteProblem() :n(0), k(0), min_noise(INT_MAX)
{
}

int SiteProblem::disturb(vector<int> siteArr)
{
	sort(siteArr.begin(), siteArr.end());
	int max_val = 0;
	for (int i = 0; i < siteArr.size() - 1; i++)
	{
		int tmp = siteArr.at(i + 1) - siteArr.at(i);
		if (tmp > max_val)
		{
			max_val = tmp;
		}
	}
	return max_val;
}

int SiteProblem::disturb(vector<int> cur_site, vector<int> goal_site)
{
	// 请保证其中的数字没有重复，这里不再进行检测
	// 排个序
	vector<int> siteArr;
	for (auto elem : cur_site)
	{
		siteArr.emplace_back(elem);
	}
	for (auto elem : goal_site)
	{
		siteArr.emplace_back(elem);
	}

	return disturb(siteArr);
}

void SiteProblem::DFS(int iter)
{
	// 终止条件
	if (disturb(cursite) < min_noise)
	{
		min_noise = disturb(cursite);
		for (int i = 0; i < cursite.size(); i++)
		{
			goalsite.at(i) = cursite.at(i);
		}
		return;
	}
	else if (iter == k)
	{
		return;
	}

	// 决策
	// 每层会有 iter+1 新建立基站
	for (int idx = 1; idx <= *(oldsite.end()-1); idx++)				// 这里是想说j小于最大的基站位置，要求基站位置矩阵提前排好序
	{
		if (cursite.at(idx) != 0)  // 不等于0则说明该位置部署了基站，所以跳过
		{
			continue;
		}

		// 做决策
		cursite.at(idx) = idx;													// 这个特意设置了idx等于在该处插入基站时的距离

		// 回溯
		DFS(iter + 1);

		// 取消决策
		cursite.at(idx) = 0;
	}

}

void SiteProblem::SiteTest()
{
	cout << "请输入已部署基站总数:" << endl;
	cin >> n;
	cout << "请输入已部署基站位置:" << endl;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		oldsite.emplace_back(tmp);
	}
	cout << "请输入可增加部署基站数" << endl;
	cin >> k;

	// // 如果不想输入，则注释上面的内容，将这些内容解开注释
	//oldsite = { 1,6,7 };
	//n = oldsite.size();
	//k = 2;

	sort(oldsite.begin(), oldsite.end());

	for (int i = 0; i <= *(oldsite.end()-1); i++)
	{
		cursite.emplace_back(0);
		goalsite.emplace_back(0);
	}
	for (auto elem : oldsite)
	{
		cursite.at(elem) = elem;
	}
	min_noise = disturb(cursite);

	DFS(0);

	cout << "最小系统噪声为: " << min_noise << endl;
	cout << "最小噪声下基站部署位置: " << endl;
	for (auto elem : goalsite)
	{
		if (elem != 0)
			cout << elem << " ";
	}
	cout << endl;
}

void MergeSortClass::MergeSortTest()
{
	int A[] = { 42,15,20,6,8,38,50,12 };
	int low = 0;
	int high = sizeof(A) / sizeof(int) - 1;
	MergeSort2(A, low, high);
	for (int i = low; i < high; i++)
		cout << A[i] << ' ';
	cout << endl;
}

void MergeSortClass::Merge(int A[], int low, int mid, int high)
{
	int* B = new int[high - low + 1];
	int i = low;
	int j = mid + 1;
	int k = 0;
	// 先完成一段
	while (i <= mid && j <= high) // 按照从小到大排序
	{
		if (A[i] <= A[j])
		{
			B[k++] = A[i++];
		}
		else
		{
			B[k++] = A[j++];
		}
	}
	// 那段没完成，把那段加载后面，默认每一段本身都是排好序的
	while (i <= mid)
	{
		B[k++] = A[i++];
	}
	while (j <= high)
	{
		B[k++] = A[j++];
	}

	// 将B中的数据转移到A中的正确位置
	for (i = low, k = 0; i <= high; i++)
	{
		A[i] = B[k++];
	}
	delete[] B;
}

void MergeSortClass::MergeSort(int A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;

		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low, mid, high);
	}
}

void MergeSortClass::MergeSort2(int A[], int low, int high)
{
	// 终止条件
	if (low >= high)
		return;

	// 做决策
	int mid = (low + high) / 2;
	MergeSort2(A, low, mid);
	MergeSort2(A, mid + 1, high);
	Merge(A, low, mid, high);

	// 没有取消决策的过程
}
