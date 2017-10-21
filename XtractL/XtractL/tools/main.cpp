
//#define CHECK_MEMORY_LEAK
#ifdef CHECK_MEMORY_LEAK
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "XtractL.h"

enum class ExitCode {	Ok = 0,  
						XtractCParamException = 1,
						XtractCException = 2,
						StdException = 3,
						NotHandled = 4
					};


int main(int argc, char **argv)
{

	try
	{
		XtractL xTrackL;

		xTrackL.setup(argc, argv);
		xTrackL.process(true);
	}
	catch (XtractL::ParamException const & exception)
	{
		std::cout << "XtractL exception caught : " << std::endl << exception.what() << std::endl;
		std::cout << XtractL::CommandLineArgumentUsage << std::endl;
		system("pause");
		return static_cast<int>(ExitCode::XtractCParamException);
	}
	catch (XtractL::Exception const & exception) {
		std::cout << "XtractC exception caught : " << std::endl << exception.what() << std::endl;
		system("pause");
		return static_cast<int>(ExitCode::XtractCException);
	}
	catch (exception const & e) {
		std::cout << "std exception caught : " << std::endl << e.what() << std::endl;
		system("pause");
		return static_cast<int>(ExitCode::StdException);
	}
	catch (...) {
		std::cout << "Unhandled exception!!!" << std::endl;
		system("pause");
		return static_cast<int>(ExitCode::NotHandled);
	}

	system("pause");

#ifdef CHECK_MEMORY_LEAK
	_CrtDumpMemoryLeaks();
#endif
	return static_cast<int>(ExitCode::Ok);
}




