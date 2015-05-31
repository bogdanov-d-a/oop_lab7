#include "stdafx.h"
#include "../MySet/MySet.h"

using namespace std;

BOOST_AUTO_TEST_CASE(SetIsEmptyByDefault)
{
	CMySet<int> s;
	BOOST_CHECK(s.IsEmpty());
}

BOOST_AUTO_TEST_CASE(TestNonemptySet)
{
	CMySet<int> s(vector<int>({ 1, 5, 2, -4, 8, 2, -4, 13 }));
	BOOST_CHECK(!s.IsEmpty());
	BOOST_CHECK(s.ToVector() == vector<int>({ -4, 1, 2, 5, 8, 13 }));
}
