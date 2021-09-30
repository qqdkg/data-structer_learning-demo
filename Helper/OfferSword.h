#pragma once

// 2021-09-06_剑指offer的面试题

// 面试题3：数组中的重复数字
// 有一个长度为n的数组，其中每一个数字都在范围（0到n-1）之间，要求找到其中任意一个重复的数字
class Prob_3_UniNum {
public:
	// 使用数组实现简单的哈希表版本
	// 时间复杂度O(1)
	// 空间复杂度O(n)
	bool findUniNum_hash(int numbers[], int n, int& duplication);

	// 测试用例
	void testUniNum( );

};





