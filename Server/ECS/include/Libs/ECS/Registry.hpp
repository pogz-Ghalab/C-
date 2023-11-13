/*
** EPITECH PROJECT, 2023
** Registry.hpp
** File description:
** Registry
*/


#ifndef REGISTRY_HPP_
#define REGISTRY_HPP_
#include "Entity.hpp"
#include "SparseArrays.hpp"
#include "../../../../Server/include/server.hpp"
#include "../../Components/PositionComp.hpp"

#include <any>
#include <map>
#include <typeindex>
#include <functional>
#include <iostream>
#include <nlohmann/json.hpp>

#define LEVEL_FILEPATH "../Config/LevelGen.json"
#define ENEMY_FILEPATH "../Config/EnemiesConfig.json"

using json = nlohmann::json;

class Server;

class Registry {
    public:
        Server *srv = NULL;
        Registry() = default;
        Registry(std::size_t _Entitynbr) : _Entitynbr(_Entitynbr) {};
        ~Registry() = default;
        void Ute() {this->fire = true;};
        void NoUte() {this->fire = false;};
        bool getFire() {return(this->fire);};

        int getEntityNbr() {return (_Entitynbr);};

        template<class Component>
        sparse_array<Component> &register_component() {
            if ((_components_arrays.count(std::type_index(typeid(Component))) == 0)) {
                _components_arrays.emplace(std::type_index(typeid(Component)), std::make_any<sparse_array<Component>>(_Entitynbr));
                _terminator.emplace_back([](Registry &reg, Entity const &entity) {reg.remove_component<Component>(entity);});
            } else
                throw std::invalid_argument("Component is already registered");
            return (this->get_components<Component>());
        };

        template<class Component>
        sparse_array<Component> &get_components() {
            return (std::any_cast<sparse_array<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))));
        };

        template<class Component>
        sparse_array<Component> const &get_components() const {
            return (std::any_cast<sparse_array<Component> &>(_components_arrays.at(std::type_index(typeid(Component)))));
        };

        Entity spawn_entity() {
            _Entitynbr += 1;
            return (Entity(_Entitynbr - 1));
        };

        template<class ...Component>
        Entity spawn_entity_with_components(Component && ...components) {
            Entity entity = spawn_entity();

            (add_component(entity, std::forward<Component>(components)), ...);
            return (entity);
        };

        Entity entity_from_index(std::size_t idx) {
            if (idx >= _Entitynbr)
                throw std::out_of_range("Entity at this index doesn't exist");
            return (Entity(idx));
        };

        void kill_entity(Entity const &entity) {
            for (auto &&it : _terminator)
                it(*this, entity);
            _KilledEntities.push_back((size_t) entity);
        };
    
        bool isDead(Entity const &entity) {
            return (std::find(this->_KilledEntities.begin(), this->_KilledEntities.end(), (size_t) entity) != _KilledEntities.end());
        };

        template <typename Component>
        typename sparse_array<Component>::reference_type add_component(Entity const &entity ,Component &&comp) {
            if (_components_arrays.find(std::type_index(typeid(Component))) == _components_arrays.end())
                throw std::invalid_argument("Component not registered");
            sparse_array<Component> &sparseArray = std::any_cast<sparse_array<Component> &>(_components_arrays.at(std::type_index(typeid(Component))));
            if (entity > sparseArray.size())
                sparseArray.extend((size_t) entity - sparseArray.size());
            return (sparseArray.insert_at(entity, comp));
        };

        template <typename Component, typename... Params>
        typename sparse_array<Component>::reference_type emplace_component(Entity const &entity, Params &&...param) {
            sparse_array<Component> sparseArray = std::any_cast<sparse_array<Component> &>(_components_arrays.at(std::type_index(typeid(Component))));
            return (sparseArray.emplaceAt(entity, param...));
        };

        template <typename Component>
        void remove_component(Entity const &entity) {
            sparse_array<Component> &sparseArray = std::any_cast<sparse_array<Component> &>(_components_arrays.at(std::type_index(typeid(Component))));
            if (sparseArray.size() > entity)
                sparseArray.erase(entity);
        };

        template<class ...Component, typename Function>
        void add_system(Function && func) {
            _SystemList.push_back([&func](Registry &registry) -> void {
                func(registry, registry.get_components<Component>()...);
            });
        };

        template<class ...Component, typename Function>
        void add_system (Function const &func) {
            _SystemList.push_back([&func](Registry &registry) -> void {
                func(registry, registry.get_components<Component>()...);
            });
        };

        void run_systems() {
            for (auto &function : _SystemList)
                function(*this);
        };

        std::vector<json> _enemyConfig;
        std::vector<json> _levelConfig;

        bool BossAlive = false;
        bool Readlvl = false;
        bool setValues = false;
        int Enemy1 = 0;
        int Enemy2 = 0;
        int Enemy3 = 0;
        int Boss = 0;
        int Level = 1;
        int EnemiesLevelNbr = 0;


        //ARENTI TEMPORARY
        //Snake variable
        int boss2 = 1;
        bool gate = false;
        bool ascend = false;
        int movement_dir_switch = -1;
        bool snake_switch = false;
        int snake_temp_x = 0;
        int snake_temp_y = 0;
        Direction snake_direction = Direction::West;

        bool Kill_Snake = false;
        bool snak_killed = false;
        int snake_nodes = 0;
        int snake_hp = 20;

////////////////// CLOCKS /////////////////////////////////

        std::clock_t boss2_movement_time = std::clock();
        std::clock_t snake_move_time = clock();
        std::clock_t drone_shooting_time = std::clock();
        std::clock_t rock_time = std::clock();
        std::clock_t enemy_wave_time = std::clock();
        std::clock_t enemy_bullets_time = std::clock();
//        int nbRocks = 1;

        /// POWER UP VARIABLES
        int ShieldActive = 0;
        int StopActive = 0;

       // bool display_drone = false;  
       int Drone_active = 0;
       
        //std::clock_t rock_time = std::clock();
        std::clock_t PowerUp_time = std::clock();
        std::clock_t PowerUpShield_time = std::clock();
        std::clock_t PowerUpStop_time = std::clock();
        std::clock_t ShieldActive_Timer = std::clock();
        std::clock_t StopActive_Timer = std::clock();

        std::clock_t PowerUpDrone_time = std::clock();
        std::clock_t droneactive_timer = std::clock();

    private:
        std::map<std::type_index, std::any> _components_arrays;
        // basically vector of vectors for each type of component classes

        std::size_t _Entitynbr = 0;

        std::vector<std::size_t> _KilledEntities;
        
        std::vector<std::function<void(Registry &)>> _SystemList;

        std::vector<std::function<void (Registry &, Entity const &)>> _terminator;


        bool fire = false;
};



#endif /* !REGISTRY_HPP_ */
