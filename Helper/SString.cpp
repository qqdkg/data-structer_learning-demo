#include "stdafx.h"
#include "SString.h"
#include"iostream"

char & SString::operator[](const int n)
{
	// TODO: �ڴ˴����� return ���
	return *(ch + n);
}


int Index_BF(SString S, SString T, int pos)
{
	//���Ӵ�T��������S�е�pos���ַ�֮�����һ���ֵ�λ��
	//���У�T�ǿգ�1<=pos<=S[0](��0��λ�ô洢�ַ�������)
	int i = pos, j = 1, sum = 0;
	while (i <= S[0] && j <= T[0])
	{
		sum++;
		if (S[i] == T[i])							//�����ȣ�������ȽϺ�����ַ���
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;							//i���ص���һ�ֿ�ʼ�Ƚ�λ�õ���һ���ַ�s
			j = 1;										//�Ӵ�������ʼ
		}
	}
	std::cout << "һ���Ƚ���" << sum << "��" << std::endl;
	if (j > T[0])									//ƥ��ɹ�
		return i - T[0];
	else
		return 0;
}

void get_next(SString T, int* next)
{
	int j = 1;
	int k = 0;
	next[1] = 0;
	while(j < T[0])									//T[0]�洢���ַ����ĳ���
	{
		if (k == 0 || T[j] == T[k])
			next[++j] = ++k;
		else
			k = next[k];
	}
}

int Index_KPM(SString S, SString T, int pos)
{
	//�����ַ���T��next������T������S�е�λ��
	//���У�T�ǿգ�1<=pos<=S[0]
	int i = pos;
	int j = 1;
	int *next=NULL;
	get_next(T,next);
	while (i < S[0] && j < T[0])
	{
		if (j == 0 || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];			//ģʽ�������ƶ�
	}
	if (j > T[0])	//ƥ��ɹ�
		return i - T[0];
	else
		return 0;
}

bool Virus_detection(SString S, SString T)
{
	int i, j;
	SString temp;//��¼��������
	for (i = T[0] + 1, j = 1; j <= T[0]; i++, j++)
		T[i] = T[j];
	for (i = 0; i < T[0]; i++)
	{
		temp[0] = T[0];				//�������ֳ���ΪT[0]
		for (j = 1; j < T[0]; j++)//ȡ��һ����������
			temp[j] = T[i + j];
		if (Index_KPM(S, T, 1))//��⵽����
			return true;
	}
	return false;
}
