#include "stdafx.h"
#include "LSB.h"
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

void LsbOrMsb()
{
	union test {
		char a;
		int b;
	} num;
	num.b = 0x12345678;
	if (num.a == 0x78)
	{
		cout << "本机为小端存储" << endl;
	}
	else
	{
		cout << "本机为大端存储" << endl;
	}

}

typedef struct {
	unsigned char value;
	unsigned int temp;
	unsigned short len;
	unsigned char data[0];
}DATA_FRAME_5;

void lsbExample()
{
	unsigned short len = 2;
	unsigned char *buf = (unsigned char *)malloc(sizeof(DATA_FRAME_5) + len);
	if (NULL == buf) return;

	unsigned char idx = 0;
	for (idx = 0; idx < sizeof(DATA_FRAME_5) + len; idx++)
	{
		buf[idx] = idx;
	}

	DATA_FRAME_5 *p_frame = (DATA_FRAME_5 *)buf;
	printf("A:%02x\r\n", p_frame->value);
	printf("B:%08x\r\n", p_frame->temp);
	printf("C:%04x\r\n", p_frame->len);
	printf("D:%02x\r\n", p_frame->data[0]);
	printf("E:%02x\r\n", p_frame->data[1]);
	free(buf);
}
