#pragma once



// Code 20 :���⽫data mamber�����ڹ����ӿ�

class AccessLevel {
public:
	AccessLevel():noAccess(1),readOnly(2),readWrite(3),writeOnly(4) {};

	int getReadOnly() const { return readOnly; }
	void  setReadWrite(int val) { readWrite = val; }
	int getReadWrite() const { return readWrite; }
	int setWriteOnly(int val) { writeOnly = val; }
private:
	int noAccess;					// ������		�����κδ���
	int readOnly;					// ������		ֻ��
	int readWrite;					//	������		�ɶ���д
	int writeOnly;					// ������		ֻ��
};