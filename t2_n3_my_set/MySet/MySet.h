#pragma once

template <typename T, typename Less = std::less<T>>
class CMySet
{
public:
	CMySet(Less const& less = Less())
		:m_less(less)
	{}

	bool IsEmpty() const
	{
		return !m_start;
	}

private:
	struct Node
	{
		template <typename TT>
		Node(TT &&data, std::unique_ptr<Node> &&next)
			:data(std::forward<T>(data))
			,next(std::move(next))
		{}

		T data;
		std::unique_ptr<Node> next;
	};

	std::unique_ptr<Node> m_start;
	Less m_less;
};
