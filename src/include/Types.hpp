#pragma once

#include <string>
#include <memory>
#include <utility>

using uint = unsigned int;
using String = std::string;

template< typename T, typename U>
using Pair = std::pair<T, U>;

// template< typename T>
// using UPointer = std::unique_ptr<T>;

template< typename T, typename U>
using UPointer = std::unique_ptr<T, U>;