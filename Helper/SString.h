#ifndef SSTRING_H
#define SSTRING_H

typedef struct SString{
	char *ch;								//ָ���ַ�����ָ��
	int length;								//�ַ�������
	char & operator[](const int n);
}SString;

int Index_BF(SString S,SString T,int pos);

void get_next(SString T,int next[]);

int Index_KPM(SString S, SString T, int pos);

bool Virus_detection(SString S, SString T);


#endif // !SSTRING_H
