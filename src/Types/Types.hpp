#pragma once

#include <string>
#include <memory>
#include <utility>

using uint = unsigned int;
using String = std::string;

template<typename T, typename U>
using Pair = std::pair<T, U>;

template<typename T>
using Vector = std::vector<T>;

template<typename T, size_t N>
using Array = std::array<T, N>;

using Positionf = Array<float, 3>;
using Positiond = Array<double, 3>;

template<typename T>
using UPointerT = std::unique_ptr<T>;

template<typename T, typename D>
using UPointerTD = std::unique_ptr<T, D>;

template<typename T>
using SPointer = std::shared_ptr<T>;
