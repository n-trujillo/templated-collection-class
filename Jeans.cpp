#include "Jeans.h"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

Jeans::Jeans() : color(Jeans_colors(rand() % 4)), size(Jeans_sizes(rand() % 4)) {}

// Paramaterized constructor
Jeans::Jeans(Jeans_colors c, Jeans_sizes s) : color(c), size(s) {}

Jeans_colors Jeans::get_color() const {
	return color;
}

Jeans_sizes Jeans::get_size() const {
	return size;
}

bool Jeans::operator==(const Jeans& sb) {
	if (sb.get_color() == color && sb.get_size() == size) {
		return true;
	} else {
		return false;
	}
}

ostream& operator<<(std::ostream& o, const Jeans& sb) {

	string c = "";
	string s = "";

	switch(sb.get_color()) {
		case Jeans_colors::white:
			c = "white";
			break;
		case Jeans_colors::black:
			c = "black";
			break;
		case Jeans_colors::blue:
			c = "blue";
			break;
		case Jeans_colors::grey:
			c = "grey";
			break;
	}

	switch(sb.get_size()) {
		case Jeans_sizes::small:
			s = "small";
			break;
		case Jeans_sizes::medium:
			s = "medium";
			break;
		case Jeans_sizes::large:
			s = "large";
			break;
		case Jeans_sizes::xlarge:
			s = "xlarge";
	}

	o << "(" << c << ", " << s << ")";
	return o;
}