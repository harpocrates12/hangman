#include <iostream>

#include "result.h"
#include "character.h"

// Initialize Constructor
Result::Result(std::string result) {
    for (int i = 0; i < result.size(); i++) {
        _characters.emplace_back(result[i]);
    }
}

bool Result::Revealed() const {
    for (Character character : _characters) {
        if (character.Visible() == false) {
            return false;
        }
    }

    return true;
}

bool Result::Check(const char &user_character) {
    bool character_found = false;

    for (Character &character : _characters) {
        if (character.Value() == user_character) {
            character_found = true;
            character.SetVisible();
        }
    }

    return character_found;
}

void Result::Print() const {
    for (Character character : _characters) {
        if (character.Visible()) {
            std::cout << character.Value();
        } else {
            std::cout << '_';
        }
        std::cout << ' ';
    }

    std::cout << std::endl;
}
