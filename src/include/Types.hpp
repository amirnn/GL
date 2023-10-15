#pragma once

#include <string>
#include <memory>
#include <utility>

using uint = unsigned int;
using String = std::string;

template< typename T, typename U>
using Pair = std::pair<T, U>;

template< typename T>
using UPointerT = std::unique_ptr<T>;

template< typename T, typename D>
using UPointerTD = std::unique_ptr<T, D>;