#include "stdafx.h"
#include "Singleton.h"


singleton* singleton::Get()
{
	if (instance == nullptr)
	{
		instance = new singleton();
	}
	return instance;
}
