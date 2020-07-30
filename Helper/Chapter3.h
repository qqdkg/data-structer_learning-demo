#ifndef __CHAPTER3_H
#define __CHAPTER3_H


//3.2 ¶þ·ÖËÑË÷
class BinarySearchTank
{
private:
	static const int M = 10000;
	int s[M];
public:
	int BinarySearch(int n, int s[], int x);
	int RecursionBS(int s[], int x, int low, int high);
	void BinarySearchTest();
	void BinarySearchTestRec();
};






#endif // !__CHAPTER3_H
