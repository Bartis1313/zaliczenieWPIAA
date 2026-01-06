#pragma once

#include <typeindex>
#include "logger/logger.hpp"

#define ADD_TYPEINFO std::type_index getType() const { return typeid(*this); }