
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	Parser(ac, av + 1);
}

PmergeMe::~PmergeMe()
{
	std::vector<int>	test(numsVec_);
	std::sort(test.begin(), test.end());
	ShowContent("TEST", test);
	ShowContent("MINE", numsVec_);
	if (test != numsVec_)
		std::cout << RED"KO! :(" << std::endl;
	else
		std::cout << GREEN"OK! :)" << std::endl;
}

void	PmergeMe::Init()
{
	ShowContent("Inicio", this->numsVec_);
	Sort(numsVec_, 1);
	//ShowContent("Fin", this->numsVec_);
}

void	PmergeMe::Parser(int ac, char **av)
{
	int i = 0;

	if (ac < 2)
		return (Error("USAGE: ./PmergeMe <nums>"));
	while (av[i])
	{
		char *end;
		int num = std::strtol(av[i], &end, 10);

		if (*end != '\0' || num < 0 || num < INT_MIN  || num > INT_MAX)
			return (Error("ERROR: Invalid arguments"));
		if (std::find(numsVec_.begin(), numsVec_.end(), num) != numsVec_.end())
			return (Error("ERROR: Repeated numbers in the sequence"));
		numsVec_.push_back(num);
		i++;
	}
}

void	PmergeMe::Error(const std::string& errorMsg)
{
	std::cerr << RED"\n\t" << errorMsg << "\n" << std::endl;
	exit(EXIT_FAILURE);
}

void	PmergeMe::ShowContent(std::string name, std::vector<int> v)
{
	std::cout << name << " = [";
	for (size_t i = 0; i < v.size(); i++)
	{
		if (i != 0)
			std::cout << ", ";
		std::cout << v[i];
	}
	std::cout << "] --> size = " << v.size() << "\n";
}

void	PmergeMe::Sort(std::vector<int> &seq, size_t level)
{
	size_t	pair_size = pow(2, level);
	size_t	element_size = pair_size / 2;
	size_t	n_pairs = seq.size() / pair_size;

	if (n_pairs < 1)
		return;	
	for (size_t i = 0; i < seq.size() - (seq.size() % pair_size); i += pair_size)
	{
		size_t lastIndex = element_size - 1;
		std::vector<int> left(seq.begin() + i, seq.begin() + i + element_size);
		std::vector<int> right(seq.begin() + i + element_size, seq.begin() + i + pair_size);

		if (left[lastIndex] > right[lastIndex])
			std::swap_ranges(left.begin(), left.end(), right.begin());

		std::copy(left.begin(), left.end(), seq.begin() + i);
		std::copy(right.begin(), right.end(), seq.begin() + i + element_size);
	}

	Sort(seq, level + 1);
	Merge(seq, pair_size);
}

size_t PmergeMe::BinarySearch(const std::vector<int>& keys, size_t end, int target)
{
	size_t	start = 0;

	while (start < end)
	{
		size_t mid = start + (end - start) / 2;

		if (keys[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}

	return (start);
}

// MAIN: b1, a1, a2, an...
// PEND: b2, b3, bn...
// No-p: %2 != 
void PmergeMe::Merge(std::vector<int> &seq, size_t pair_size)
{
	std::vector<int>	main(seq.begin(), seq.begin() + pair_size);
	std::vector<int>	pend;
	std::vector<int>	non;
	size_t				i;
	size_t				element_size = pair_size / 2;

	for (i = pair_size; i + element_size <= seq.size(); i += element_size)
	{
		std::vector<int> b(seq.begin() + i, seq.begin() + i + element_size);
		pend.insert(pend.end(), b.begin(), b.end());
		if (i + pair_size > seq.size())
			continue ;
		std::vector<int> a(seq.begin() + i + element_size, seq.begin() + i + pair_size);
		main.insert(main.end(), a.begin(), a.end());
		i += element_size;
	}

	if (i < seq.size())
		non.insert(non.end(), seq.begin() + i, seq.end());

	/* BORRAR */
	std::cout << YELLOW"\n\t-----------------------------------------------------\n" << NC""<< std::endl;
	std::cout << "PAIR_SIZE = " << pair_size << "\nELEMENT_SIZE = " << pair_size/2 << std::endl;
	ShowContent("MAIN", main);
	ShowContent("PEND", pend);
	ShowContent("NON", non);

	inserted = 0;
	aux_main.clear();
	for (size_t j = 0; j + element_size <= main.size(); j += element_size)
		aux_main.push_back(main[j + element_size - 1]);

	i = 1;
	size_t pend_blocks = pend.size() / element_size;
	size_t prev_jc = 0;
	size_t jacobsthal = JacobsthalNum(i);

	while (jacobsthal <= pend_blocks)
	{
		size_t diff = jacobsthal - prev_jc;
		size_t j = jacobsthal;

		/*BORRAR*/
		std::cout << YELLOW"JACOB = " << jacobsthal << " in i(" << i << ")\nPREV = " << prev_jc << "\nDIFF = " << diff << NC"\n";
		for (size_t j_in = 0; j_in < diff && j > 0; ++j_in, --j)
		{
			std::cout << GREEN" J(" << j << ")" << NC"" << std::endl;
			size_t index = (j - 1) * element_size;
			Insertion(main, pend, index, element_size);
			ShowContent("main", main);
		}
		++i;
		prev_jc = jacobsthal;
		jacobsthal = JacobsthalNum(i);
	}

	for (i = inserted * element_size; i + element_size <= pend.size(); i += element_size)
		Insertion(main, pend, i, element_size);

	main.insert(main.end(), non.begin(), non.end());
	seq = main;
}

void PmergeMe::Insertion(std::vector<int> &main, std::vector<int> &pend, size_t i, size_t element_size)
{
	std::vector<int> b(pend.begin() + i, pend.begin() + i + element_size);
	ShowContent("B", b);
	size_t	limit = (i / element_size) + 2 + inserted;
	size_t	end = aux_main.size();

	if (limit < end)
		end = limit;
	size_t pos = BinarySearch(aux_main, end, b[element_size - 1]);
	aux_main.insert(aux_main.begin() + pos, b[element_size - 1]);
	main.insert(main.begin() + (pos * element_size), b.begin(), b.end());
	inserted++;
}

size_t PmergeMe::JacobsthalNum(size_t n)
{
	if (n <= 1)
		return (1);
	return JacobsthalNum(n - 1) + 2 * JacobsthalNum(n - 2);
}
