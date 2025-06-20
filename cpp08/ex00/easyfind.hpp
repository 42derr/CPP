#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
void easyfind(T& container, int target)
{
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (it != container.end())
        std::cout << "Found " << target << std::endl;
    else
        throw std::runtime_error("Value not found in container");
}

#endif
