#include <iostream>

#include "hangman.h"
#include "result.h"

void Hangman::Print() const {
    for (int i = 0; i < _idx; i++) {
        std::cout << _ascii[i];
    }

    std::cout << std::endl;
}

void Input(char &user_character) {
    std::cout << "Please enter a letter:\n";
    std::cin >> user_character;
}

void Update(Result &result, const char &user_character, Hangman &hangman) {
    bool character_found;

    character_found = result.Check(user_character);

    if (!character_found) {
        hangman.Draw();
    }
}

void Render(const Result &result, const Hangman &hangman) {
    #ifdef _WIN32
    system("CLS");
    #elif _WIN64
    system("CLS");
    #elif __LINUX__ || __gnu_linux__ || __linux__
    system("clear");
    #elif __APPLE__
    system("clear");
    #endif

    std::cout << std::endl;
    std::cout << "Guess the word!" << std::endl;
    std::cout << "--------------------";
    std::cout << std::endl;

    result.Print();

    std::cout << std::endl;
    std::cout << "Stage:" << std::endl;
    std::cout << "--------------------";
    std::cout << std::endl;

    hangman.Print();

    std::cout << std::endl;
    std::cout << std::endl;
}

int main() {
    Result result("hangman");
    Hangman hangman;
    char user_character;

    Render(result, hangman);

    while (!result.Revealed() && !hangman.Finished()) {
        Input(user_character);
        Update(result, user_character, hangman);
        Render(result, hangman);
    }

    std::cout << "Finished.\n";

    if (!hangman.Finished()) {
        std::cout << "Congrats! You guessed the word\n";
    } else {
        std::cout << "Try again!\n";
    }

    return 0;
}
