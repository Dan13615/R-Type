/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Application.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace App {

    class Application {
        public:
            struct AppSettings {
                sf::Vector2u windowSize = sf::Vector2u(800, 600);
                std::string windowTitle = "My window";
                unsigned int frameRateLimit = 60;
                unsigned int bytePerPixel = 32;
            };

            explicit Application(const AppSettings &settings);
            ~Application();
            void run();
            sf::RenderWindow &getWindow();
        private:
            sf::RenderWindow p_window;
            bool _hitterAlreadySpawn = false;
            std::size_t _hitId;
        private:
            void initHandledEvents();
            void initBackground();
            void initDuck();
            void spawnHit(int x, int y);
            void launchSnook(sf::Event &event);
    };
} // namespace App
