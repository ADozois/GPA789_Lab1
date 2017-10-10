#include "TransducerActionODynamic.h"


TransducerActionODynamic::TransducerActionODynamic(string const & prefix, bool displayPrevious, string const & infix, bool displayCurrent, string const & postfix, ostream * oStream)
	:	TransducerActionOStream{ oStream },
		mDisplayPrevious{ displayPrevious },
		mDisplayCurrent{ displayCurrent },
		mPrefix{ prefix },
		mInfix{ infix },
		mPostfix{ postfix }
{
}
TransducerActionODynamic::TransducerActionODynamic(string const & prefix, string const & postfix, ostream * oStream)
	:	TransducerActionODynamic(prefix, false, string(), true, postfix, oStream) 
{
}
TransducerActionODynamic::TransducerActionODynamic(string const & postfix, ostream * oStream) 
	: TransducerActionODynamic(string(), postfix, oStream) 
{
}
TransducerActionODynamic::TransducerActionODynamic(ostream * oStream)
	: TransducerActionODynamic(string(), oStream)
{ 
}

bool TransducerActionODynamic::process(symbol_t prevSymbol, symbol_t curSymbol)
{
	*mOStream << mPrefix;
	if (mDisplayPrevious) *mOStream << prevSymbol;
	*mOStream << mInfix;
	if (mDisplayCurrent) *mOStream << curSymbol;
	*mOStream << mPostfix;

	return true;
}

TransducerAction* TransducerActionODynamic::clone() const
{
	return new TransducerActionODynamic(mPrefix, mDisplayPrevious, mInfix, mDisplayCurrent, mPostfix, mOStream);
}
