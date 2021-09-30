#pragma once



// Code 20 :避免将data mamber放置于公开接口

class AccessLevel {
public:
	AccessLevel():noAccess(1),readOnly(2),readWrite(3),writeOnly(4) {};

	int getReadOnly() const { return readOnly; }
	void  setReadWrite(int val) { readWrite = val; }
	int getReadWrite() const { return readWrite; }
	int setWriteOnly(int val) { writeOnly = val; }
private:
	int noAccess;					// 此整数		不作任何处理
	int readOnly;					// 此整数		只读
	int readWrite;					//	此整数		可读可写
	int writeOnly;					// 此整数		只读
};