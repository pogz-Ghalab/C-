/*
** EPITECH PROJECT, 2023
** SparseArrays.hpp
** File description:
** SparseArrays
*/

#ifndef SPARSEARRAYS_HPP_
#define SPARSEARRAYS_HPP_

#include <optional>
#include <iostream>
#include <vector>
#include <memory>

template <typename Component>
    class sparse_array {
        public:
            using reference_type = std::optional<Component> &;
            using const_reference_type = std::optional<Component> const &;
            using container_t = std::vector<std::optional<Component>>;
            using size_type = typename container_t::size_type;
            using iterator = typename container_t::iterator;
            using const_iterator = typename container_t::const_iterator;
            using value_type = std::optional<Component>;
        public:
            sparse_array() = default;

                        // copy constuctor //
            sparse_array(sparse_array const &spr_copy) {
                for (std::size_t t = 0; t < spr_copy.size(); t++)
                    _data.push_back(std::nullopt);
                for (std::size_t t = 0; t < spr_copy.size(); t++)
                    _data[t] = spr_copy._data[t];
            };
                        // move constructor //
            sparse_array(sparse_array &&spr_arr) noexcept {
                _data(std::move(spr_arr._data));
            };

            sparse_array(std::size_t size) {
                for (std::size_t i = 0; i < size; i++) {
                    _data.push_back(std::nullopt);
                }
            };

            ~sparse_array() = default;

                        // copy assignment operator 
            sparse_array &operator=(sparse_array const &spr_arr) {
                std::swap(_data, spr_arr._data);
                return (*this);
            };

                    // move assignment operator 
            sparse_array &operator=(sparse_array &&spr_arr) noexcept {
                _data = std::move(_data, spr_arr._data);
                return (*this);
            };

            reference_type operator[](size_t idx) {
                return (_data[idx]);
            };

            const_reference_type operator[](size_t idx) const {
                return (_data[idx]);
            };

            iterator begin() {
                return (_data.begin());
            };

            const_iterator begin() const {
                return (_data.begin());
            };

            const_iterator cbegin() const {
                return (_data.cbegin());
            };

            iterator end() {
                return (_data.end());
            };

            const_iterator end() const {
                return (_data.end());
            };

            const_iterator cend() const {
                return (_data.cend());
            };

            size_type size() const {
                return (_data.size());
            };

            void extend(size_t Extender) {
                for (size_t t = 0; t < Extender; t += 1)
                    _data.push_back(std::nullopt);
            }

            reference_type insert_at(size_type pos, Component const &component) {
                if (pos > _data.size())
                    throw std::invalid_argument("Position doesnt exist in array");
                if (pos < _data.size()) {
                    auto tmp = _data.get_allocator();
                    std::allocator_traits<decltype(tmp)>::destroy(tmp, std::addressof(_data[pos]));
                    _data[pos] = component;
                    return (_data[pos]);
                }
                _data.push_back(component);
                return (_data.back());
            };

            reference_type insert_at(size_type pos, Component &&component) {
                if (pos > _data.size())
                    throw std::invalid_argument("Position doesnt exist in array");
                if (pos < _data.size()) {
                    auto tmp = _data.get_allocator();
                    std::allocator_traits<decltype(tmp)>::destroy(tmp, std::addressof(_data[pos]));
                    _data[pos] = std::move(component);
                    return (_data[pos]);
                }
                _data.push_back(std::move(component));
                return (_data.back());
            };

            template <class... Params>
            reference_type emplace_at(size_type pos, Params &&...params) {
                if (pos > _data.size())
                    throw std::invalid_argument("Position doesnt exist in array");
                auto tmp = _data.get_allocator();
    
                std::allocator_traits<decltype(tmp)>::destroy(tmp, std::addressof(_data[pos]));
                std::allocator_traits<decltype(tmp)>::construct(tmp, std::addressof(_data[pos]), std::forward(params)...);
                return _data[pos];
            };

            void erase (size_type pos) {
                _data[pos] = std::nullopt;
            };

            size_type get_index(value_type const &val_type) const {
                auto tmp = std::addressof(val_type);

                for (std::size_t t = 0; t < _data.size(); t++)
                    if (tmp == std::addressof(_data[t]))
                        return (t);
                throw std::invalid_argument("Component doesnt exist");
            };

        private:
            container_t _data; // basically vector of component classes
};

#endif /* !SPARSEARRAYS_HPP_ */