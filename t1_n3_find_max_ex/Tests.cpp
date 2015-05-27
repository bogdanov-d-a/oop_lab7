#include "stdafx.h"
#include "FindMaxEx.h"

using namespace std;

class IntLess
{
public:
	explicit IntLess(bool inverse = false)
		:m_inverse(inverse)
	{}

	bool const operator()(int const& a, int const& b) const
	{
		return m_inverse ? (a > b) : (a < b);
	}

private:
	bool m_inverse;
};

BOOST_AUTO_TEST_CASE(TestEmptyVector)
{
	int maxValue;
	BOOST_CHECK(!FindMax(vector<int>(), maxValue));
}

BOOST_AUTO_TEST_CASE(TestIntVector)
{
	int maxValue;
	BOOST_CHECK(FindMax(vector<int>({ 1, 3, 5, -3, 7, 3 }), maxValue));
	BOOST_CHECK_EQUAL(maxValue, 7);
}

BOOST_AUTO_TEST_CASE(TestIntVectorForMin)
{
	int minValue;

	BOOST_CHECK(FindMax(vector<int>({ 1, 3, 5, -3, 7, 3 }), minValue,
		[](int const& a, int const& b){ return a > b; }));

	BOOST_CHECK_EQUAL(minValue, -3);
}

BOOST_AUTO_TEST_CASE(TestIntVectorWithIntLess)
{
	int maxValue;
	BOOST_CHECK(FindMax(vector<int>({ 1, 3, 5, -3, 7, 3 }), maxValue, IntLess()));
	BOOST_CHECK_EQUAL(maxValue, 7);
}

BOOST_AUTO_TEST_CASE(TestIntVectorForMinWithIntLess)
{
	int minValue;
	BOOST_CHECK(FindMax(vector<int>({ 1, 3, 5, -3, 7, 3 }), minValue, IntLess(true)));
	BOOST_CHECK_EQUAL(minValue, -3);
}

BOOST_AUTO_TEST_CASE(TestDoubleVector)
{
	double maxValue;
	BOOST_CHECK(FindMax(vector<double>({ 1.3, 3.2, 1.9, -3.8, 2.7, 3.6 }), maxValue));
	BOOST_CHECK_EQUAL(maxValue, 3.6);
}
