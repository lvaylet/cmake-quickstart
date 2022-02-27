#include <vector>
#include <limits>
#include <iostream>

float maxValue(std::vector<float> numbers) {
  float maxNumber = -std::numeric_limits<float>::infinity();
  for (float number : numbers) {
    if (number > maxNumber) {
      maxNumber = number;
    }
  }
  return maxNumber;
}
