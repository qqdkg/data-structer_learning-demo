#pragma once

typedef struct DkgList {
	int val = -1;
	struct DkgList *next = nullptr;
	struct DkgList *per = nullptr;
} DkgList;

class DkgListClass {
public:
	DkgList * Creat(int n);
	void dkgShow(int n ,DkgList* const & list);
	void dkgDeleteNode(DkgList *list);
	void dkgCountMod_n(int n, DkgList *list);
};

// µ¥Á´±í
typedef struct sl_node {
	int data;
	struct sl_node* next;
}sl_node ,*sl_List;

class sl_ListTest {
public:
	void Test();

};


