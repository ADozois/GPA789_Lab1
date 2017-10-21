#include "XtractL.h"
#include <sstream>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// XtractC
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
const string XtractL::OpenInputFileErrorString{ "Le nom du fichier d'entree est invalide ou il existe une restriction d'acces sur ce fichier." };
const string XtractL::OpenOutputFileErrorString{ "Le nom du fichier de sortie est invalide ou il existe une restriction d'acces sur ce fichier." };
const string XtractL::ReadCharacterFromInputFileString{ "Impossible de lire un caractere." };
const string XtractL::CommandLineArgumentUsage{ R"(
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Programme XtractL - Extraction de literaux d'un fichier source du langage C++
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Usage : xtractL infile [outfile]
  - infile : est le fichier source C/C++ (*.h, *.hpp, *.c, *.cpp)
  - outfile : est le fichier de sortie
              si non specifie, la sortie est redirigee vers la sortie standard
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
)" };

XtractL::XtractL()
	: mOStream{ &cout },
	mCppLiteralExtraction(mFileStatExtraction)
{
}

void XtractL::setup(const string & inputFileName)
{
	openInputFile(inputFileName);

	mOStream = &cout;
	mCppLiteralExtraction.setOStream(mOStream);
}

void XtractL::setup(const string & inputFileName, const string & outputFileName)
{
	openInputFile(inputFileName);
	openOutputFile(outputFileName);

	mOStream = &mOutputFile;
	mCppLiteralExtraction.setOStream(mOStream);
}

void XtractL::setup(const string & inputFileName, stringstream & outputstring)
{
	openInputFile(inputFileName);

	mOStream = &outputstring;
	mCppLiteralExtraction.setOStream(mOStream);
}

void XtractL::setup(int argc, char **argv)
{
	if (argc < 2 || argc > 3) {
		throw ParamException(__FUNCSIG__);
	}

	switch (argc) {
	case 2:
		setup(argv[1]);
		break;
	case 3:
		setup(argv[1], argv[2]);
		break;
	}
}

void XtractL::openInputFile(const string & inputFileName)
{
	mInputFile.open(inputFileName, ios::in);

	if (mInputFile.fail()) {
		throw Exception(__FUNCSIG__, OpenInputFileErrorString);
	}
}

void XtractL::openOutputFile(const string & outputFileName)
{
	mOutputFile.open(outputFileName, ios::out | ios::trunc);

	if (mOutputFile.fail()) {
		throw Exception(__FUNCSIG__, OpenOutputFileErrorString);
	}
}

void XtractL::process(bool includeStats)
{
	mFileStatExtraction.start();
	mCppLiteralExtraction.start();

	symbol_t symbol;
	while (!mInputFile.eof()) {
		mInputFile.get(symbol);
		if (!mInputFile.eof()) {
			if (mInputFile.fail()) {
				throw Exception(__FUNCSIG__, ReadCharacterFromInputFileString);
			}
			mFileStatExtraction.processSymbol(symbol);
			mCppLiteralExtraction.processSymbol(symbol);
		}
	}

	mFileStatExctractionAccepted = mFileStatExtraction.stop();
	mCppLiteralExtractionAccepted = mCppLiteralExtraction.stop();

	if (includeStats) {
		writeStats();
	}
}

void XtractL::writeStats()
{
	*mOStream << endl << endl;
	*mOStream << "File statistics :" << endl;
	*mOStream << "Number of lines : " << mFileStatExtraction.lineCount() << endl;
	*mOStream << "Number of spaces : " << mFileStatExtraction.spaceCount() << endl;
	*mOStream << "Number of other characters : " << mFileStatExtraction.characterCount() << endl;
	*mOStream << "Number of C style comments : " << mCppLiteralExtraction.cStyleCommentCount() << endl;
	*mOStream << "Number of C++ style comments : " << mCppLiteralExtraction.cppStyleCommentCount() << endl;
	*mOStream << "Number of strings : " << mCppLiteralExtraction.stringCount() << endl;
	*mOStream << "Number of characters : " << mCppLiteralExtraction.characterCount() << endl;
	*mOStream << "Number of integer: " << mCppLiteralExtraction.integerCount() << endl;
	*mOStream << "Number of float: " << mCppLiteralExtraction.floatCount() << endl;
	*mOStream << endl << "Accepting state :" << endl;
	*mOStream << "Statistics extraction returned with success : " << boolalpha << mFileStatExctractionAccepted << endl;
	*mOStream << "C++ comments extraction returned with success : " << boolalpha << mCppLiteralExtractionAccepted << endl;
	*mOStream << endl;
}



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// XtractL::Exception
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
XtractL::Exception::Exception(const string & context, const string & cause)
	: mContext{ context },
	mCause{ cause }
{
}

string XtractL::Exception::what() const
{
	stringstream strStream;

	strStream << "Exception levee : XtractL::Exception" << endl
		<< "  - Contexte : " << mContext << endl
		<< "  - Cause possible : " << mCause << endl;

	return strStream.str();
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// XtractL::ParamException
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
const string XtractL::ParamException::CauseString{ "Parametre(s) d'entree invalide(s)." };

XtractL::ParamException::ParamException()
	: Exception("", CauseString)
{
}

XtractL::ParamException::ParamException(const string & context)
	: Exception(context, CauseString)
{
}