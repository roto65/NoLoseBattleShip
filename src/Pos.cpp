#include <math.h>
#include <string>

#include "Pos.h"

Pos::Pos() {
    
}

Pos::Pos (int X, int Y) {
    x = X;
    y = Y;
}

Pos::Pos(std::string s) {
    int letter = (int) s[0];

    if (letter >= 97) letter -= 32; // ASCII di a = 97

    if (letter > 73) letter -= 2;   // ASCII di J = 74
    letter -= 65;                   // ASCII di A = 65

    int number = std::stoi(s.substr(1));
    number--;

    x = number;
    y = letter;
}

std::string Pos::toString() {
    y += 65;                        // ASCII di A = 65

    if (y > 73) y += 2;             // ASCII di J = 74

    std::string letter = std::to_string(y);
    std::string number = std::to_string(x);

    return letter + number;

}

Pos operator+ (Pos p1, Pos p2) {
    return Pos (p1.x + p2.x, p1.y + p2.y);
}

Pos operator- (Pos p1, Pos p2) {
    return Pos (p1.x - p2.x, p1.y - p2.y);
}

bool operator== (Pos p1, Pos p2) {
    return (p1.x == p2.x) && (p1.y == p2.y);
}

double distance(Pos p1, Pos p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}


