#ifndef SRC_GAMESCENE_HPP_
#define SRC_GAMESCENE_HPP_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <sugarlab/Game.hpp>
#include <sugarlab/Scene.hpp>
#include <sugarlab/AssetLoader.hpp>
#include <sugarlab/Rect.hpp>
#include <sugarlab/Vec2.hpp>
#include <sugarlab/Text.hpp>

class GameScene : public Scene {
    public:
        explicit GameScene(std::string name, Game* game);
        void init();
        void update(double delta_time);
        void draw(SDL_Renderer* renderer);

    private:
        Game* game_;
        Text* score_text_[2];
        int score_[2];
        void resize_ui();
};

#endif  // SRC_GAMESCENE_HPP_
