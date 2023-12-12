#pragma once

#include <type_traits>
#include <string>

#include "datatypes.h"


std::string separateSection(std::string title);

std::string separateSubsection(std::string title);

std::string separateBlock(std::string title);

std::string separateBlock(std::string title, int chapter);


template<typename T,
    typename = std::enable_if_t<
    std::is_same_v<T, Group> ||
    std::is_same_v<T, Lecturel> ||
    std::is_same_v<T, Subject> ||
    std::is_same_v<T, Info>
    >
>
std::ostream& operator<<(std::ostream& stream, T obj) {
	return stream << obj.toString();
}
