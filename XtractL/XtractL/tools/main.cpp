
//#define CHECK_MEMORY_LEAK
#ifdef CHECK_MEMORY_LEAK
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

enum class ExitCode {	Ok = 0,  
						XtractCParamException = 1,
						XtractCException = 2,
						StdException = 3,
						NotHandled = 4
					};


int main(int argc, char **argv)
{
	
#ifdef CHECK_MEMORY_LEAK
	_CrtDumpMemoryLeaks();
#endif
	return static_cast<int>(ExitCode::Ok);
}




