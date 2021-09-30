#include "stdafx.h"
#include "LinkedListTest.h"
#include <iostream>

DkgList * DkgListClass::Creat(int n)
{
	if (n <= 0)
		return nullptr;


	DkgList * head = new DkgList;
	DkgList * end = new DkgList;
	end = head;

	for (int i = 1; i <= n; i++)
	{
		end->val = i;
		DkgList *tmp = new DkgList();
		if (i < 5)
		{
			tmp->per = end;
			end->next = tmp;
			end = tmp;
		}
	}
	end->next = head;
	head->per = end;

	return head;
}

void DkgListClass::dkgShow(int n, DkgList* const & list)
{
	DkgList * tmp = list;
	for (int i = 0; i < n; i++)
	{
		std::cout << tmp->val << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void DkgListClass::dkgDeleteNode(DkgList * list)
{
	list->per->next = list->next;
	list->next->per = list->per;
	delete list;
	list = nullptr;
}

void DkgListClass::dkgCountMod_n(int n, DkgList * list)
{
	int count = 0;
	while (list->val != list->next->val)
	{
		count++;
		if (count %n == 0)
		{
			DkgList * tmp = list;
			list = tmp->next;
			std::cout << "É¾³ý£º" << tmp->val << std::endl;
			dkgDeleteNode(tmp);
		}
		else
			list = list->next;
	}
	std::cout << "n = " << n << " Ê£ÏÂ: " << list->val << std::endl;
}
