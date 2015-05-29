#include "stdafx.h"
#include "../MySet/MySet.h"

BOOST_AUTO_TEST_CASE(SetIsEmptyAfterConstruction)
{
	CMySet<int> s;
	BOOST_CHECK(s.IsEmpty());
}
