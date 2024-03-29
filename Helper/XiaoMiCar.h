#pragma once

// 2021-09-29
// 这个题目是小米汽车部门面试时的手撕代码题目

// 1.给两个int序列，要求求这两个int序列的合集

// 现场的思路
//		两个数列分别排序，然后同时做合并和去重这一步，用这个思路其实很不好写，在如何同时合并和去重这一点上卡了很久，耗尽了时间

// 下来思考一下其实可以采取这样的思路
//		先合并，然后排序，然后去重（标记重复元素，然后复制没有标记的元素到输出数组）

// 经验教训，不要想着一次性同时完成两件事，会导致事情变得非常复杂，最好一次只完成一件事件
// 比如这次：不要想着在合并有序数列的同时去重，太可怕了，操作很复杂，面试现场几乎不能能做出来。
//					如果现场写感觉自己的思路越写越复杂，就花几分钟反思一下是不是有想要一部完成多件事的情况。

int * getCorss(const int * arr1, int n1, const int * arr2, int n2, int &n_out);

void getCorssTest();


