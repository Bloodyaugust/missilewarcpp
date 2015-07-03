#include <stdio.h>
#include <iostream>
#include "gamescene.hpp"

GameScene::GameScene(std::string name, Game* game) : game_(game), Scene(name) {
    TTF_Font* font = TTF_OpenFont("res/font/orbitron-black.ttf", 24);
}

void GameScene::init() {

}

void GameScene::update(double delta_time) {
    for (int i = 0; i < this->event_queue_.size(); i++) {
        if (this->event_queue_[i]->type() == "resize") {
            this->resize_ui();
        }
    }

    Scene::update(delta_time);
}

void GameScene::draw(SDL_Renderer* renderer) {
    Scene::draw(renderer);
}

void GameScene::resize_ui() {
  
}
