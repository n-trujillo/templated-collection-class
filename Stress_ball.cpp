#include "Stress_ball.h"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

Stress_ball::Stress_ball() : color(Stress_ball_colors(rand() % 4)), size(Stress_ball_sizes(rand() % 3)) {}

// Paramaterized constructor
Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) : color(c), size(s) {}

Stress_ball_colors Stress_ball::get_color() const {
	return color;
}

Stress_ball_sizes Stress_ball::get_size() const {
	return size;
}

bool Stress_ball::operator==(const Stress_ball& sb) {
	if (sb.get_color() == color && sb.get_size() == size) {
		return true;
	} else {
		return false;
	}
}

ostream& operator<<(std::ostream& o, const Stress_ball& sb) {

	string c = "";
	string s = "";

	switch(sb.get_color()) {
		case Stress_ball_colors::red:
			c = "red";
			break;
		case Stress_ball_colors::blue:
			c = "blue";
			break;
		case Stress_ball_colors::yellow:
			c = "yellow";
			break;
		case Stress_ball_colors::green:
			c = "green";
			break;
		default:
			c = "error";
			break;
	}

	switch(sb.get_size()) {
		case Stress_ball_sizes::small:
			s = "small";
			break;
		case Stress_ball_sizes::medium:
			s = "medium";
			break;
		case Stress_ball_sizes::large:
			s = "large";
			break;
		default:
			s = "error";
			break;
	}

	o << "(" << c << ", " << s << ")";
	return o;
}