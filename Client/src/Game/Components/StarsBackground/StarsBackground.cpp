/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "StarsBackground.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            StarsBackground::Star::Star(gd::Window &window, int x, int y, int size, int speed)
                : _size(size), _speed(speed)
            {
                _position = {static_cast<float>(x), static_cast<float>(y)};
                _shape.create({
                    {(float)(size / 2), (float)(0)},
                    {(float)(size / 3 * 2), (float)(size / 3)},
                    {(float)(size), (float)(size / 2)},
                    {(float)(size / 3 * 2), (float)(size / 3 * 2)},
                    {(float)(size / 2), (float)(size)},
                    {(float)(size / 3), (float)(size / 3 * 2)},
                    {(float)(0), (float)(size / 2)},
                    {(float)(size / 3), (float)(size / 3)},
                });
                _shape.setOrigin({(float)(size / 2), (float)(size / 2)});
                _shape.setFillColor(gd::Color::fromHex("#505050"));
                _shape.setPosition(_position);
            }

            void StarsBackground::Star::update(gd::Window &window)
            {
                (void)window;
                _shape.move({(float)(-_speed), 0});
            }

            void StarsBackground::Star::setSpeed(int speed)
            {
                _speed = speed;
            }

            void StarsBackground::Star::draw(gd::Window &window)
            {
                window.draw(_shape);
            }

            StarsBackground::StarsBackground(gd::Window &window)
            {
                for (int i = 0; i < rand() % 90 + 10; i++)
                    _stars.push_back(Star(window, rand() % window.getWidth(), rand() % (window.getHeight() + 10) - 5, rand() % 9 + 1));
                _spawnclock.reset();
                _updateClock.reset();
            }

            void StarsBackground::update(gd::Window &window)
            {
                if (_updateClock.getElapsedTime() > 1000 / 24) {
                    for (auto &star : _stars) {
                        star.update(window);
                        if (star.getPosition().x < 0)
                            _stars.erase(_stars.begin());
                    }
                    _updateClock.reset();
                }

                if (_spawnclock.getElapsedTime() >= rand() % 600 + 100) {
                    _stars.push_back(Star(window, window.getWidth(), rand() % window.getHeight(), rand() % 10 + 5));
                    _spawnclock.reset();
                }
            }

            void StarsBackground::draw(gd::Window &window)
            {
                for (auto &star : _stars)
                    star.draw(window);
            }
        } // namespace Components
    } // namespace Game
} // namespace RType