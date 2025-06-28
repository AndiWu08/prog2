#include <iostream>
#include <vector>
#include <string>

#define D

bool less1(const std::vector<std::pair<int, char>>& lhs, const std::vector<std::pair<int, char>>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	bool less = false;
	for (std::size_t i = 0; i < lhs.size(); ++i)
	{
		if (lhs[i].first > rhs[i].first)
			return false;
		if (lhs[i].first < rhs[i].first)
			less = true;
	}
	return less;
}

bool less2(const std::vector<std::pair<int, char>>& lhs, const std::vector<std::pair<int, char>>& rhs)
{
	auto size = std::min(lhs.size(), rhs.size());
	for (std::size_t i = 0; i < size; ++i)
	{
		if (lhs[i].first > rhs[i].first)
			return false;
		if (lhs[i].first < rhs[i].first)
			return true;
	}
	if (lhs.size() == rhs.size())
		return false;
	return lhs.size() < rhs.size();
}

bool aeq(const std::vector<std::pair<int, char>>& lhs, const std::vector<std::pair<int, char>>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	for (std::size_t i = 0; i < lhs.size(); ++i)
		if (lhs[i].first != rhs[i].first)
			return false;
	return true;
}

std::string toText(const std::vector<std::pair<int, char>>& v)
{
	std::string text = "(";
	for (auto& [value, name] : v)
	{
		text += " ";
		text += std::to_string(value);
		text += name;
		text += ",";
	}
	text.erase(--text.end());
	text += " )";
	return text;
}

int main()
{
	std::vector<std::vector<std::pair<int, char>>> vectors{
		// v1 
		{
			{3, 'd'}, {2, 'e'}, {1, 'f'}
		},
		// v2
		{
			{3, 'a'}, {3, 'b'}, {1, 'c'}
		},
		// v3
		{
			{4, 'g'}, {2, 'h'}, {3, 'i'}
		},
		// v4
		{
			{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}
		},
		// v5
		{
			{3, 'a'}, {3, 'b'}, {1, 'c'}
		},
		// v6
		{
			{3, 'j'}, {3, 'k'}, {1, 'l'}
		},
	};

	auto vEnd = vectors.cend();

	// Compare every vector with each other
	for (std::size_t firstIdx = 0; firstIdx < 3; ++firstIdx)
	{
		for (std::size_t secondIdx = firstIdx + 1; secondIdx < 6; ++secondIdx)
		{
			const auto& first = vectors[firstIdx];
			const auto& second = vectors[secondIdx];
			// Print the vectors
			std::cout << "Compare vector " << firstIdx + 1
				<< ": " << toText(first)
				<< " and vector " << secondIdx + 1
				<< ": " << toText(second) << '\n';
#if defined(A)
			std::cout << std::boolalpha
				<< 'v' << firstIdx + 1 << " < v" << secondIdx + 1 << "\t\t" << (first < second) << '\n'
				<< 'v' << secondIdx + 1 << " < v" << firstIdx + 1 << "\t\t" << (second < first) << '\n'
				<< 'v' << firstIdx + 1 << " == v" << secondIdx + 1 << "\t" << (first == second) << '\n'
				<< '\n';
#elif defined(B)
			std::cout << std::boolalpha
				<< 'v' << firstIdx + 1 << " < v" << secondIdx + 1 << "\t\t" << less1(first, second) << '\n'
				<< 'v' << secondIdx + 1 << " < v" << firstIdx + 1 << "\t\t" << less1(second, first) << '\n'
				<< 'v' << firstIdx + 1 << " == v" << secondIdx + 1 << "\t" << (first == second) << '\n'
				<< '\n';
#elif defined(C)
			std::cout << std::boolalpha
				<< 'v' << firstIdx + 1 << " < v" << secondIdx + 1 << "\t\t" << less2(first, second) << '\n'
				<< 'v' << secondIdx + 1 << " < v" << firstIdx + 1 << "\t\t" << less2(second, first) << '\n'
				<< 'v' << firstIdx + 1 << " == v" << secondIdx + 1 << "\t" << (first == second) << '\n'
				<< '\n';
#elif defined(D)
			std::cout << std::boolalpha
				<< 'v' << firstIdx + 1 << " < v" << secondIdx + 1 << "\t\t" << less2(first, second) << '\n'
				<< 'v' << secondIdx + 1 << " < v" << firstIdx + 1 << "\t\t" << less2(second, first) << '\n'
				<< 'v' << firstIdx + 1 << " == v" << secondIdx + 1 << "\t" << aeq(first, second) << '\n'
				<< '\n';
#endif
		}
	}
}