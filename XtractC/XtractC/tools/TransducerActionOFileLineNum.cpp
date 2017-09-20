#include "TransducerActionOFileLineNum.h"


#include <iomanip>


TransducerActionOFileLineNum::TransducerActionOFileLineNum(AutomatonFileStatExtraction const & fileStatExtraction, string const & prefix, string const & postfix, ostream * oStream)
	:	TransducerActionOFileStat(fileStatExtraction, prefix, postfix, oStream)
{
}

bool TransducerActionOFileLineNum::process(symbol_t prevSymbol, symbol_t curSymbol)
{
	*mOStream << mPrefix << setfill('0') << setw(5) << mFileStatExtraction.lineCount() << " - - - - - - - - - - " << mPostfix;

	return true;
}

TransducerAction* TransducerActionOFileLineNum::clone() const
{
	return new TransducerActionOFileLineNum(mFileStatExtraction, mPrefix, mPostfix, mOStream);
}
