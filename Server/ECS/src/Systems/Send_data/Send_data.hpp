/*
** EPITECH PROJECT, 2023
** Send_data.hpp
** File description:
** Send_data
*/

#ifndef SEND_DATA_HPP_
#define SEND_DATA_HPP_

#include "../../../include/Libs/ECS/Registry.hpp"
#include "../../../include/Libs/Definitions/Entity_Type.hpp"
#include "../../../include/Components/TypeComponent.hpp"
#include "../../../include/Components/PositionComp.hpp"
#include "../../../include/Components/UsernameComp.hpp"
#include "../../../include/Components/ParallaxComp.hpp"
#include "../../../include/Components/HealthComp.hpp"
#include "../../../include/Components/PowerUpTypeComponent.hpp"
#include "../../../include/Components/PowersComp.hpp"
#include <iostream>
#include <string>

class Registry;

class Send_data {
    public:
        Send_data() = default;
        ~Send_data() = default;

        std::string SendPosition(component::position_t pos);
        std::string SendType(component::type_t type);
        void operator()(Registry &reg, sparse_array<component::type_t> &type, sparse_array<component::position_t> &pos, sparse_array<component::username_t> &uname, sparse_array<component::parallax_t> &par, sparse_array<component::health_t> &health, sparse_array<component::PowerUpType_t> &powupType, sparse_array<component::Powers_t> &pow);

    protected:
    private:
};

#endif /* !SEND_DATA_HPP_ */
