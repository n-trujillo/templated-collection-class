#ifndef JEANS_H
#define JEANS_H
#include <iostream>
#include <stdlib.h>

using namespace std;

enum class Jeans_colors {white, black, blue, grey};
enum class Jeans_sizes {small, medium, large, xlarge};

class Jeans{
    Jeans_colors color;
    Jeans_sizes size;

public:
    Jeans();
    Jeans(Jeans_colors c, Jeans_sizes s);
    Jeans_colors get_color() const; 
    Jeans_sizes get_size() const;
    bool operator==(const Jeans& sb);
};

ostream& operator<<(ostream& o, const Jeans& sb);
#endif