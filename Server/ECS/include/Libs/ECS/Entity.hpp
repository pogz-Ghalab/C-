/*
** EPITECH PROJECT, 2023
** Entity.hpp
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "Registry.hpp"
#include <iostream>

class Entity {
    public:
        explicit Entity(std::size_t id) : _id(id) {};
        
        operator std::size_t() const {
            return (_id);
        };

    protected:
        //friend class Registry;

        std::size_t _id;
        std::int32_t MAXSIZE = 100;
    private:
};

#endif /* !ENTITY_HPP_ */
