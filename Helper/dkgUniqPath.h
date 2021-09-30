#pragma once



//int n = 0, m = 0;
//int count = 0;
//
//void BFS(int ** mat, int cur_n, int cur_m)
//{
//	if (cur_n == n - 1 && cur_m == m - 1)
//	{
//		count++;
//		return;
//	}
//	if (cur_n == n - 1 && cur_m != m - 1)
//	{
//		return;
//	}
//	if (cur_n != n - 1 && cur_m == m - 1)
//	{
//		return;
//	}
//
//	if (cur_n + 1 < n)
//	{
//		BFS(mat, cur_n + 1, cur_m);
//	}
//	if (cur_m + 1 < m)
//	{
//		BFS(mat, cur_n, cur_m + 1);
//	}
//
//}
//
//int uniquePath(int ** mat, int n, int m)
//{
//	if (mat[0][0] == 1 || mat[n - 1][m - 1] == 1)
//		return 0;
//
//	BFS(mat, 0, 0);
//
//	return count;
//}
//
//void uniqPathTest()
//{
//	cin >> n;
//	cin >> m;
//	int ** mat = new int*[n];
//	for (int i = 0; i < n; i++)
//	{
//		mat[i] = new int[m];
//		for (int j = 0; j < m; j++)
//		{
//			cin >> mat[i][j];
//		}
//	}
//
//
//
//	for (int i = 0; i < m; i++)
//	{
//		delete[] mat[i];
//	}
//	delete[] mat;
//}



