/*
** EPITECH PROJECT, 2023
** PositionComp.hpp
** File description:
** PositionComp
*/

#ifndef POSITIONCOMP_HPP_
#define POSITIONCOMP_HPP_

#include <ctime>

enum Direction
{
    North,
    NorthEast,
    East,
    SouthEast,
    South,
    SouthWest,
    West,
    NorthWest
};

namespace component {
    struct position_t {
        int x;
        int y;

        std::string getDirection(void)
        {
            switch (direction){
                case 0:
                    return "N";
                case 2:
                    return "E";
                case 4:
                    return "S";
                case 6:
                    return "W";
            }
        }

        // give random coords to enemy initially
        Direction direction = Direction::West;
        clock_t movement_clock = clock();

    };   
}

#endif /* !POSITIONCOMP_HPP_ */
