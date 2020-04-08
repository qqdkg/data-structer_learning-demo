#pragma once
class callBackFucn {

	typedef int(*Biger)(int, int);
	Biger big;
	void SetFunb(Biger func) { big = func; }

	typedef int(*Smaller)(int, int);
	Smaller small;
	void SetFcns(Smaller func) { small = func; }
};
