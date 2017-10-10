#include "TransducerActionOFileStat.h"


TransducerActionOFileStat::TransducerActionOFileStat(AutomatonFileStatExtraction const & fileStatExtraction, string const & prefix, string const & postfix, ostream * oStream)
	:	TransducerActionOStream(oStream),
		mFileStatExtraction{ fileStatExtraction },
		mPrefix{ prefix },
		mPostfix{ postfix }
{
}
