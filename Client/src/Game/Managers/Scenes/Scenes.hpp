/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_MANAGERS_SCENES_HPP_
#define RTYPE_GAME_MANAGERS_SCENES_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include <unordered_map>
#include "GradeDe/Color.hpp"
#include "GradeDe/Shape.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Vector.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Managers/Music/Music.hpp"
#include "Game/Scenes/Base/IScene.hpp"
#include "Game/Scenes/Game/GameScene.hpp"
#include "Game/Scenes/JoinRoom/JoinRoom.hpp"
#include "Game/Scenes/Menu/MenuScene.hpp"
#include "Game/Scenes/RoomsList/RoomsListScene.hpp"
#include "Game/Scenes/Settings/SettingsScene.hpp"
#include "Game/Scenes/WaitingRoom/WaitingRoom.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            class Scenes
            {
                public:
                    static Scenes &get();
                    ~Scenes() = default;

                    void load(gd::Window &window);
                    void reload(gd::Window &window);
                    void changeScene(const std::string &name);
                    std::shared_ptr<RType::Game::Scenes::IScene> getScene();
                    void update(gd::Window &window);
                    void draw(gd::Window &window);
                    bool isTransitioning() const;
                    std::string getCurrentSceneName() const;
                    void needToReload();

                private:
                    Scenes() = default;

                    typedef enum {
                        FADE_IN,
                        FADE_OUT,
                        NOTHING,
                    } TransitionState;

                    int _transitionDuration = 400;
                    int _transitionFrame = 40;
                    int _transitionSpeed = 255 / _transitionFrame;
                    int _backupVolume = 100;
                    int _volumeTransition = 100 / _transitionFrame;
                    gd::Time _timer;
                    std::shared_ptr<RType::Game::Scenes::IScene> _currentScene = nullptr;
                    std::string _nextScene = "";
                    std::string _currentSceneName = "";
                    TransitionState _transitionState = NOTHING;
                    int _transitionOpacity = 0;
                    std::unordered_map<std::string, std::shared_ptr<RType::Game::Scenes::IScene>> _scenes = {};
                    gd::Shape _transitionShape;
                    gd::Color _transitionColor = gd::Color::Transparent;
                    bool _needReload = false;

                    void _addScene(const std::string &name, std::shared_ptr<RType::Game::Scenes::IScene> scene, gd::Window &window);
            };
        } // namespace Managers
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_MANAGERS_SCENES_HPP_ */
