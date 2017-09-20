#include "TransducerActionOStatic.h"


TransducerActionOStatic::TransducerActionOStatic(string const & staticText, ostream * oStream)
	:	TransducerActionOStream{ oStream },
		mStaticText{ staticText }
{
}

bool TransducerActionOStatic::process(symbol_t prevSymbol, symbol_t curSymbol)
{
	*mOStream << mStaticText;

	return true;
}

TransducerAction* TransducerActionOStatic::clone() const
{
	return new TransducerActionOStatic(mStaticText, mOStream);
}
