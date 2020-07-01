#ifndef HANGMAN_H
#define HANGMAN_H

#include <vector>

class Hangman {
    public:
        Hangman() {
            _ascii = {"_ ", "_\n", " |\n"," O\n","/","|","\\\n","/"," \\\n"};
        }
        void Draw() { _idx++; }
        bool Finished() { return _idx == _ascii.size(); }
        void Print() const;

    private:
        int _idx = 0;
        std::vector<std::string> _ascii;
};

#endif