#pragma once

#include <exception>
#include <string>

class IdException {
public:

	std::string what() {
		return "Error:Invalid ID!";
	}
};

class OutOfBoundExcepion {
public:
	std::string what() {
		return "Error: Out of bounds! ";
	}
};
