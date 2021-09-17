#ifndef STRESS_BALL_H
#define STRESS_BALL_H
#include <iostream>
#include <stdlib.h>

using namespace std;

enum class Stress_ball_colors {red, blue, green, yellow};
enum class Stress_ball_sizes {small, medium, large};

class Stress_ball{
    Stress_ball_colors color;
    Stress_ball_sizes size;

public:
    Stress_ball();
    Stress_ball(Stress_ball_colors c, Stress_ball_sizes s);
    Stress_ball_colors get_color() const; 
    Stress_ball_sizes get_size() const;
    bool operator==(const Stress_ball& sb);
};

ostream& operator<<(ostream& o, const Stress_ball& sb);
#endif