#ifndef RESULT_H
#define RESULT_H

#include <string>
#include <vector>

#include "character.h"

class Result {
    public:
        // Initialize Constructor
        Result(std::string result);
        // Returns true when all characters are revealed, otherwise false
        bool Revealed() const;
        bool Check(const char &character);
        void Print() const;
    private:
        std::vector<Character> _characters;
};

#endif
