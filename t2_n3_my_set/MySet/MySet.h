#pragma once

template <typename T, typename Less = std::less<T>>
class CMySet
{
public:
	CMySet()
	{}

	template <typename InputIterator>
	CMySet(InputIterator const& begin, InputIterator const& end)
	{
		std::vector<InputIterator> iterators;
		for (auto iterator = begin; iterator != end; ++iterator)
		{
			iterators.push_back(iterator);
		}

		Less less = Less();
		std::sort(iterators.begin(), iterators.end(),
			[&less](InputIterator const& a, InputIterator const& b){ return less(*b, *a); });

		for (InputIterator iterator : iterators)
		{
			if (!m_start || less(*iterator, m_start->data))
			{
				m_start = std::make_unique<Node>(static_cast<T>(*iterator), std::move(m_start));
			}
		}
	}

	template <typename Container>
	CMySet(Container const& container)
		:CMySet(container.begin(), container.end())
	{}

	bool IsEmpty() const
	{
		return !m_start;
	}

	std::vector<T> ToVector() const
	{
		std::vector<T> result;

		for (auto curNode = &m_start; *curNode; curNode = &((*curNode)->next))
		{
			result.push_back((*curNode)->data);
		}

		return result;
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
};
