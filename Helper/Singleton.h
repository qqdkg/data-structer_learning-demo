#pragma once

class singleton
{
private:
	singleton() {};
	singleton * instance;
public:
	singleton* Get();

};


