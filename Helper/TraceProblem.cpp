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

// ·������¼��track��
// ѡ���б� ��nums�в�������track�е�Ԫ��
// ����������nums�е�Ԫ��ȫ����track�г���
void backtrack(vector<int> numArr, list<int> track)
{
	// ������������
	if (numArr.size() == track.size())
	{
		res.emplace_back(track);
		return;
	}

	for (int i = 0; i < numArr.size(); ++i)
	{
		// �ų����Ϸ���ѡ��
		for (auto elem : track)
		{
			if (elem == numArr.at(i))
				continue;
		}

		// ��ѡ��
		track.emplace_back(numArr.at(i));

		// ������һ�������
		backtrack(numArr, track);

		// ȡ��ѡ��
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
		// ����֮ǰ���в���
		swap(a[i], a[k]);

		// ����
		dfs_nums(a, k + 1, n);

		// ���ݺ�������
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
	// ��ֹ����
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
			cout << "��" << count << "�ֽ�" << endl;
			showChessBoard();
			cout << endl;
		}
		
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		// ������
		int row = k;
		int col = i;

		// ȷ��������ǲ��ǿ��ԷŻʺ�
		if (canPlaceAQueen(row, col))
		{
			SetQueenOnBoard(row, col);
			// ����
			dfs_8Queen(k + 1, n);
			// ȡ������
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

	// �ж�ͬ����û�лʺ�
	for (int icol = 0; icol < col_max; ++icol)
	{
		if ( getChOnBoard(row,icol) == Queen && icol != col)
		{
			return false;
		}
	}

	// �ж�ͬ����û�лʺ�
	for (int irow = 0; irow < row_max; ++irow)
	{
		if (getChOnBoard(irow,col) == Queen && irow != row)
		{
			return false;
		}
	}

	// �ж�ͬб����û�лʺ�
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
				//cout << irow << " " << icol << " ���Է��ûʺ�" << endl;
				SetChOnBoard(irow, icol, blank);
			}
			else
			{
				//cout << irow << " "<< icol << " �����Է��ûʺ�" << endl;
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
	// �洢�������ֶ�Ӧ�ַ�����ӳ���ϵ
	unordered_map<int, string> map;
	vector<string> strVec = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	for (int i = 0; i <= 9; i++)
	{
		map[i] = strVec[i];
	}

	// ����绰������
	vector<int> nums = { 2,3 ,8,6};

	// ������ĵ绰����ת���ɶ�Ӧ���ַ���
	vector<string> Vecin;
	for (auto elem : nums)
	{
		Vecin.emplace_back(map[elem]);
	}
	string str = "";
	dfs_str(Vecin, str);
	ShowAll(strVec_out);
	cout << "������� : " << count << endl;
}

void fullpremut::Test_dfs_nums()
{
	count = 0;			// ������ʼ��
	vector<int> arr = { 1,2,3,4,5 };
	int n = arr.size();
	dfs_nums(arr, 0, 5);
	cout << "���й���" << count << "��" << endl;
}

void fullpremut::Test_dfs_str()
{
	count = 0;
	strVec_in = { "abc","def" ,"ghi","jkl"};
	string str = "";
	//dfs_str2(strVec_in.at(0), str);
	dfs_str(strVec_in, str);
	ShowAll(strVec_out);
	cout << "������� : " << count << endl;
}

// �˻ʺ�����
// �ʺ�����ߺ�����б�ߵ�����߲�
// Ҳ����˵Queen�ڰ�*�˵������������Χ���Ե���߽�
//�˻ʺ����������ڰ˳˰˵������ڿ����ȶ����ڵİ˸��ʺ��м��ֿ��ܵķֲ�
// ���������DFS��������ȣ������ĵ�������
void fullpremut::Test_dfs_8Queen()
{

	int n = 8;

	// ��ʼ������
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

	cout << n << "�ʺ�����" << endl;
	cout << "���� " << count << "�ֽ�" << endl;

} // void fullpremut::Test_dfs_8Queen()

void fullpremut::swap(int & a, int & b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


// ����Ǯ���⣬�����м�����ֵ��Ӳ�ң�ÿ����ֵ��Ӳ�Ҷ������߹�Ӧ��Ҫ��������������������Ӳ����������޷���������򷵻�-1��

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
	cout << "��������Ӳ������Ϊ:" << minc << endl;
}

void CoinProblem::DFS_greed(int iter, vector<int>& coins, vector<int>& coinCount, int M)
{
	// ��ֹ����
	if (iter == M || cur_V >= goal_V)		// ��������������Ӳ�� ���� ��ǰ���������Ŀ����
	{
		if (cur_V == goal_V)
		{
			if (min_count > count)				// ����С�ĵ��Ǹ��������һ��ʼҪ��ʼ��һ���ܴ��ֵ
			{
				min_count = count;
			}
		}
		return ;
	}

	// ������

	for (int i = 0; (cur_V + i*coins.at(iter) <= goal_V); i++)
	{
		// ������
		cur_V += i*coins.at(iter);
		coinCount.at(iter)+=i;
		count += i;														// ֮ǰ���Ǹ����Ż��������Ż�Ŀ�긳ֵ��

		// ����
		DFS_greed(iter + 1, coins, coinCount, M);

		// ȡ������
		cur_V -= i*coins.at(iter);
		coinCount.at(iter)-=i;
		count -= i;
	}

}

int CoinProblem::minCoins(int V, vector<int>& coins, int M)
{
	goal_V = V;

	// ����ÿ�����Ӳ�ҵ�ʹ�ü���
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
	// �뱣֤���е�����û���ظ������ﲻ�ٽ��м��
	// �Ÿ���
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
	// ��ֹ����
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

	// ����
	// ÿ����� iter+1 �½�����վ
	for (int idx = 1; idx <= *(oldsite.end()-1); idx++)				// ��������˵jС�����Ļ�վλ�ã�Ҫ���վλ�þ�����ǰ�ź���
	{
		if (cursite.at(idx) != 0)  // ������0��˵����λ�ò����˻�վ����������
		{
			continue;
		}

		// ������
		cursite.at(idx) = idx;													// �������������idx�����ڸô������վʱ�ľ���

		// ����
		DFS(iter + 1);

		// ȡ������
		cursite.at(idx) = 0;
	}

}

void SiteProblem::SiteTest()
{
	cout << "�������Ѳ����վ����:" << endl;
	cin >> n;
	cout << "�������Ѳ����վλ��:" << endl;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		oldsite.emplace_back(tmp);
	}
	cout << "����������Ӳ����վ��" << endl;
	cin >> k;

	// // ����������룬��ע����������ݣ�����Щ���ݽ⿪ע��
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

	cout << "��Сϵͳ����Ϊ: " << min_noise << endl;
	cout << "��С�����»�վ����λ��: " << endl;
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
	// �����һ��
	while (i <= mid && j <= high) // ���մ�С��������
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
	// �Ƕ�û��ɣ����Ƕμ��غ��棬Ĭ��ÿһ�α������ź����
	while (i <= mid)
	{
		B[k++] = A[i++];
	}
	while (j <= high)
	{
		B[k++] = A[j++];
	}

	// ��B�е�����ת�Ƶ�A�е���ȷλ��
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
	// ��ֹ����
	if (low >= high)
		return;

	// ������
	int mid = (low + high) / 2;
	MergeSort2(A, low, mid);
	MergeSort2(A, mid + 1, high);
	Merge(A, low, mid, high);

	// û��ȡ�����ߵĹ���
}
