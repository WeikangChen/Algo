#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>

template<class ForwardIt, class UnaryPredicate>
ForwardIt my_partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = std::find_if_not(first, last, p);
    if (first == last) return first;
 
    for (ForwardIt i = std::next(first); i != last; ++i) {
        if (p(*i)) {
            std::iter_swap(i, first);
            ++first;
        }
    }
    return first;
}

template<class ForwardIt, class UnaryPredicate>
ForwardIt my_remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = std::find_if_not(first, last, p);
    if (first == last) return first;
 
    for (ForwardIt i = std::next(first); i != last; ++i) {
        if (!p(*i)) {
            *first = std::move(*i);
            ++first;
        }
    }
    return first;
}


int main()
{
	std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    std::cout << "Original vector:\n    ";
    for(int elem : v) 
    	std::cout << elem << ' ';
 	std::cout << std::endl;

    auto it = my_remove_if(v.begin(), v.end(), [](int i){return i % 2 == 0;});
 
    std::cout << "Partitioned vector:\n    ";
    std::copy(std::begin(v), it, std::ostream_iterator<int>(std::cout, " "));
    std::cout << " * ";
    std::copy(it, std::end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

}
