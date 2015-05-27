#pragma once

template <typename T, typename Less = std::less<T>>
bool FindMax(std::vector<T> const& arr, T &maxValue, Less const& less = Less())
{
	if (arr.empty())
	{
		return false;
	}

	auto maxIt = arr.begin();
	for (auto curIt = ++arr.begin(); curIt != arr.end(); ++curIt)
	{
		if (less(*maxIt, *curIt))
		{
			maxIt = curIt;
		}
	}

	maxValue = *maxIt;
	return true;
}
