#include "define.h"
#include "MK_Core.h"

int main() 
{

	if (!GET_SINGLE(MK_Core)->Init())
	{
		cout << "Game Init Error" << endl;
		MK_Core::DestroyInst();
		return 0;
	}

	GET_SINGLE(MK_Core)->Run();
}