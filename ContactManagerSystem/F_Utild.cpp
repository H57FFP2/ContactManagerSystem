#include <string>
#include <algorithm>
#include "F_Utils.h"


void tolowerc(std::string& text) {
	std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) { return std::tolower(c); });
}