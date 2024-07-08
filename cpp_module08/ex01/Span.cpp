#include "Span.hpp"

// Constructors and Destructor
Span::Span(unsigned int n) : _n(n) {
  return;
}

Span::Span(const Span &source) {
  this->_n = source.getN();
  const std::vector<int> &sourceVec = source.getVec();
  for (size_t i = 0; i < sourceVec.size(); i++)
    this->_vec.push_back(sourceVec[i]);
  return;
}

Span::~Span() {
  return;
}

// Operators overload
Span &Span::operator=(const Span &source) {
  this->_n = source.getN();
  const std::vector<int> &sourceVec = source.getVec();
  for (size_t i = 0; i < sourceVec.size(); i++)
    this->_vec.push_back(sourceVec[i]);
  return (*this);
}

// Member functions
void Span::addNumber(int n) {
	if (this->_vec.size() >= this->_n) {
		throw FullContainerException();
	}
	this->_vec.push_back(n);
	return;
}

int Span::shortestSpan(void) {
	if (this->_vec.size() < 2) {
		throw NotEnoughElementsException();
	}
	std::vector<int> vec = this->_vec;
	std::sort(vec.begin(), vec.end());
	int min = vec[1] - vec[0];
	for (size_t i = 1; i < vec.size() - 1; i++) {
		if (vec[i + 1] - vec[i] < min) {
			min = vec[i + 1] - vec[i];
		}
	}
	return (min);
}

int Span::longestSpan(void) {
	if (this->_vec.size() < 2) {
		throw NotEnoughElementsException();
	}
	std::vector<int> vec = this->_vec;
	std::sort(vec.begin(), vec.end());
	return (vec[vec.size() - 1] - vec[0]);
}

// Getters and Setters
unsigned int Span::getN(void) const {
	return (this->_n);
}

std::vector<int> Span::getVec(void) const {
	return (this->_vec);
}
