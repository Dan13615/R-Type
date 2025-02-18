/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** ComponentManager.hpp
*/

#pragma once

#include <cstdarg>
#include <memory>
#include <unordered_map>
#include <cassert>
#include <iostream>
#include "ECS/ECS.hpp"
#include "AComponent.hpp"

namespace ECS
{
    class ComponentsManager {
        public:
            ComponentsManager();
            ~ComponentsManager() = default;

            template<class C, typename ...Args>
            void AddComponent(Entity &entity, Args... args)
            {
                assert(ECS::GetInstance().HasEntity(entity));
                #ifdef _WIN32
                    va_list argsList = nullptr;
                #else
                    va_list argsList;
                #endif

                p_registeredComponents[typeid(C).name()]->AddToEntity(entity, argsList, args...);
            }

            template<class C>
            void RemoveComponent(Entity &entity) const
            {
                assert(ECS::GetInstance().HasEntity(entity));

                for (auto &component : p_registeredComponents) {
                    if (typeid(C).name() == component.first)
                        component.second->RemoveFromEntity(entity);
                }
            }

            void RemoveAllComponents(Entity& entity);

            template<class C>
            [[nodiscard]] bool HasComponent(const Entity &entity) const
            {
                return entity.componentsName.contains(typeid(C).name());
            }

            template<class C>
            [[nodiscard]] std::unique_ptr<AComponent> &GetComponent(Entity &entity)
            {
                assert(ECS::GetInstance().HasEntity(entity));

                for (auto &component : p_registeredComponents) {
                    if (typeid(C).name() == component.first)
                        return p_registeredComponents[typeid(C).name()];
                }
                throw std::runtime_error("Component not found");
            }

            template<class C>
            [[nodiscard]] C &GetComponent() const
            {
                for (auto &component : p_registeredComponents) {
                    if (typeid(C).name() == component.first)
                        return dynamic_cast<C &>(*component.second);
                }
                throw std::runtime_error("Component not found");
            }

            template<class C>
            void RegisterComponent()
            {
                assert(!p_registeredComponents.contains(typeid(C).name()));

                p_registeredComponents[typeid(C).name()] = std::make_unique<C>();
            }

        private:
            std::unordered_map<std::string, std::unique_ptr<AComponent>> p_registeredComponents;
    };
}
