#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#define dkg_debug

void Metro_init(int ** mat, int n)
{
	for (int i = 0; i < n; i++)
	{
		mat[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = 0;
		}
	}
}

void Metro_Dsip(int ** mat, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void Metro_Set(int ** mat, int s1, int s2, int cmd)
{
	// 与邻接表对应
	s1 = s1 - 1;
	s2 = s2 - 1;

	if (cmd == 0)
	{
		mat[s1][s2] = 0;
		mat[s2][s1] = 0;
	}
	else
	{
		mat[s1][s2] = 1;
		mat[s2][s1] = 1;
	}

}

void Metro_Swap(int ** mat, int s1, int s2)
{
	// 与邻接表对应
	s1 = s1 - 1;
	s2 = s2 - 1;


}

int MertoLink()
{
	int n = 0;
	int m = 0;
	int q = 0;
	// 依次输入：地铁站数量，连接数量，交换数量
#ifdef dkg_debug
	n = 5;
	m = 5;
	q = 3;
	cout << "Debug模式:" << endl;
	cout << n << " " << m << " " << q << endl;
#else
	cin >> n >> m >> q;
#endif

	int** mat = new int*[n];

	// 初始化邻接矩阵
	Metro_init(mat, n);

	//Metro_Dsip(mat, n);

	// 初始化连接
#ifdef dkg_debug
	int arr1[] = { 1,2,3,4,1 };
	int arr2[] = { 2,3,4,5,4 };
#endif

	for (int i = 0; i < m; i++)
	{
		int s1, s2;
#ifdef dkg_debug
		s1 = arr1[i];
		s2 = arr2[i];
		cout << s1 << " " << s2 << endl;
#else
		cin >> s1 >> s2;
#endif

		Metro_Set(mat, s1, s2, 1);
	}
	//Metro_Dsip(mat, n);


	int* table = new int[n];

	for (int i = 0; i < n; i++)
	{
		table[i] = i + 1;
	}

#ifdef dkg_debug
	int arr3[] = { 2,1,3 };
	int arr4[] = { 5,2,4 };
#endif

	for (int i = 0; i < q; i++)
	{
		int s1, s2;

#ifdef dkg_debug
		s1 = arr3[i];
		s2 = arr4[i];
#else
		cin >> s1 >> s2;
#endif
		int id1 = 0, id2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (s1 == table[i])
				id1 = i;
			if (s2 == table[i])
				id2 = i;
		}
		int tmp = table[id1];
		table[id1] = table[id2];
		table[id2] = tmp;
	}


	for (int id = 1; id <= n; id++)
	{
		for (int j = 0; j < n; j++)
		{
			int count = 0;
			if (id == table[j])
			{
				for (int i = 0; i < n; i++)
				{
					if (mat[j][i] == 1)
						count++;
				}
				cout << count << " ";
			}
		}
	}

	return 0;
}