#ifndef SRC_MENUSCENE_HPP_
#define SRC_MENUSCENE_HPP_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <sugarlab/Game.hpp>
#include <sugarlab/Scene.hpp>
#include <sugarlab/AssetLoader.hpp>
#include <sugarlab/Rect.hpp>
#include <sugarlab/Vec2.hpp>
#include <sugarlab/Text.hpp>
#include <sugarlab/Button.hpp>

class MenuScene : public Scene {
    public:
        explicit MenuScene(std::string name, Game* game);
        void init();
        void update(double delta_time);

    private:
        Game* game_;
        void resize_ui();
};

#endif  // SRC_MENUSCENE_HPP_
