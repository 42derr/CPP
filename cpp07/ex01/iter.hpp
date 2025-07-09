#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template <typename T, typename Func>
void iter(T* a, std::size_t N, Func f)
{
    for (std::size_t i = 0; i < N; ++i)
        f(a[i]);
}

#endif
