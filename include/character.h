#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
    public:
        // Disable default constructor
        Character() = delete;
        // Initialize Constructor
        Character(char character);

        char Value() const { return _value; }
        bool Visible() const { return _is_visible; }
        void SetVisible() { _is_visible = true; }

    private:
        char _value;
        bool _is_visible = false;
};

#endif
