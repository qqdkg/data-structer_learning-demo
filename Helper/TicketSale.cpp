#include "stdafx.h"
#include "TicketSale.h"

HANDLE g_hMutex;


// ��Ʊ�����̺߳�����
DWORD WINAPI SaleTicket(LPVOID lpParam)
{
	THD_DATA * pThreadData = (THD_DATA*)lpParam;
	TICKET * pSaleData = pThreadData->pTicket;

	while (pSaleData->nCount > 0)
	{
		// ����һ����������
		WaitForSingleObject(g_hMutex, INFINITE);
		if (pSaleData->nCount > 0)
		{
			cout << pThreadData->strThreadName << "�۳���" << pSaleData->nCount-- << "��Ʊ��";
			if (pSaleData->nCount >= 0)
				cout << "��Ʊ�ɹ���ʣ��" << pSaleData->nCount << "��Ʊ��" << endl;
			else
				cout << "��Ʊʧ�ܣ���Ʊ�����ꡣ" << endl;
		} //if( pSaleData )
		
		Sleep(100);
		
		// �ͷŻ�������
		ReleaseMutex(g_hMutex);

	} //while(pSaleData)

	return 0;
}

void TestProg()
{
	// ����һ��������
	g_hMutex = CreateMutex(NULL, FALSE, NULL);

	// ��ʼ����Ʊ
	TICKET ticket;
	ticket.nCount = 100;
	strcpy_s(ticket.strTicketName, " ��ͷ-->���� ");


	const int THREAD_NUM = 8;

	THD_DATA threadSale[THREAD_NUM];
	HANDLE hThread[THREAD_NUM];
	for (int i = 0; i < THREAD_NUM; i++)
	{
		threadSale[i]. pTicket = &ticket;										// ��Ʊ�̻߳�ȡ��Ʊ��Ϣ
		string strThreadName = convertToString(i);


		strThreadName = "����" + strThreadName;
		strcpy_s(threadSale[i].strThreadName, strThreadName.c_str());

		// �����߳�		��ȡ�߳̾��
		hThread[i] = CreateThread(NULL, NULL, SaleTicket, &threadSale[i], 0, NULL);


		// ����һ����������
		WaitForSingleObject(g_hMutex, INFINITE);
		cout << threadSale[i].strThreadName << "��ʼ����" << threadSale[i].pTicket->strTicketName << "��Ʊ..." << endl;

		// �ͷŻ�����
		ReleaseMutex(g_hMutex);

		// �ر��߳̾��
		CloseHandle(hThread[i]);
	} // 
	system("pause");

}

