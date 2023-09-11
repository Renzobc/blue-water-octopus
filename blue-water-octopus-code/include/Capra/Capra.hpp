// 1. (Mandatory) Write a function that takes an unsigned 32 bits integer as input and
// returns true if all the digits in the base 10 representation of that number are unique.
// bool all_digits_unique(uint32_t value)
// Example:
// all_digits_unique (48778584) returns false
// all_digits_unique (17308459) returns true

#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <memory>
#include <set>
#include <iostream>

namespace capra
{

    bool all_digits_unique(uint32_t value);

    void sort_letters(std::string &input, std::string sort_order);

    enum class DOOR_ORIENTATION : char
    {
        NORTH = 'n',
        SOUTH = 's',
        WEST = 'w',
        EAST = 'e'
    };

    struct Room
    {
        // weak ptr referencing the copy count block of the shared ptr
        // the reference to a room should NOT keep the room alive if needed to be deleted.
        std::weak_ptr<Room> north;
        std::weak_ptr<Room> south;
        std::weak_ptr<Room> east;
        std::weak_ptr<Room> west;

        std::string name;

        // Room() = delete;
        Room(std::string r_name) : name(r_name){};

        // Connects to a already created shared ptr of type room
        void connect(std::shared_ptr<Room> &r, DOOR_ORIENTATION door);

        // find if path exists
        bool path_exists_to(const std::string ending_room_name);

        bool operator<(const Room other) const
        {
            return std::basic_string(this->name) < std::basic_string(other.name);
        }

        bool operator==(const Room other) const
        {
            return other.name == this->name;
        }
    };

};
