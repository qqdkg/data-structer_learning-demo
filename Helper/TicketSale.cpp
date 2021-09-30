#include "stdafx.h"
#include "TicketSale.h"

HANDLE g_hMutex;


// 售票程序（线程函数）
DWORD WINAPI SaleTicket(LPVOID lpParam)
{
	THD_DATA * pThreadData = (THD_DATA*)lpParam;
	TICKET * pSaleData = pThreadData->pTicket;

	while (pSaleData->nCount > 0)
	{
		// 请求一个互斥量锁
		WaitForSingleObject(g_hMutex, INFINITE);
		if (pSaleData->nCount > 0)
		{
			cout << pThreadData->strThreadName << "售出第" << pSaleData->nCount-- << "张票，";
			if (pSaleData->nCount >= 0)
				cout << "出票成功！剩余" << pSaleData->nCount << "张票。" << endl;
			else
				cout << "出票失败！该票已售完。" << endl;
		} //if( pSaleData )
		
		Sleep(100);
		
		// 释放互斥量锁
		ReleaseMutex(g_hMutex);

	} //while(pSaleData)

	return 0;
}

void TestProg()
{
	// 创建一个互斥量
	g_hMutex = CreateMutex(NULL, FALSE, NULL);

	// 初始化火车票
	TICKET ticket;
	ticket.nCount = 100;
	strcpy_s(ticket.strTicketName, " 包头-->杭州 ");


	const int THREAD_NUM = 8;

	THD_DATA threadSale[THREAD_NUM];
	HANDLE hThread[THREAD_NUM];
	for (int i = 0; i < THREAD_NUM; i++)
	{
		threadSale[i]. pTicket = &ticket;										// 售票线程获取车票信息
		string strThreadName = convertToString(i);


		strThreadName = "窗口" + strThreadName;
		strcpy_s(threadSale[i].strThreadName, strThreadName.c_str());

		// 创建线程		获取线程句柄
		hThread[i] = CreateThread(NULL, NULL, SaleTicket, &threadSale[i], 0, NULL);


		// 请求一个互斥量锁
		WaitForSingleObject(g_hMutex, INFINITE);
		cout << threadSale[i].strThreadName << "开始销售" << threadSale[i].pTicket->strTicketName << "的票..." << endl;

		// 释放互斥量
		ReleaseMutex(g_hMutex);

		// 关闭线程句柄
		CloseHandle(hThread[i]);
	} // 
	system("pause");

}

