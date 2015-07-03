#include <stdio.h>
#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include "menuscene.hpp"

MenuScene::MenuScene(std::string name, Game* game) : game_(game), Scene(name) {

}

void MenuScene::init() {
    double button_x = this->game_->window_width() / 2 - 75;
    double button_y = this->game_->window_height() / 2 - 25;

    Mix_Chunk* button_hover = this->game_->assets()->sfx("button-hover.wav");
    Button* play_button = new Button("Play", "play", "button-play.png", new Rect(button_x, button_y, 150, 50), this->game_);
    play_button->set_button_hover(button_hover);

    this->add_actor(play_button);
}

void MenuScene::update(double delta_time) {
    for (int i = 0; i < this->event_queue_.size(); i++) {
        if (this->event_queue_[i]->type() == "play") {
            this->game_->set_scene("game");
        } else if (this->event_queue_[i]->type() == "resize") {
            this->resize_ui();
        }
    }

    Scene::update(delta_time);
}

void MenuScene::resize_ui() {
    std::vector<Actor*> menu_buttons = this->get_actors_by_tag("button");
    Rect* button_collider;
    double button_x = this->game_->window_width() / 2 - (75 * this->game_->x_scalar());
    double button_width = 150 * this->game_->x_scalar();
    double button_y = this->game_->window_height() / 2 - (75 * this->game_->y_scalar());
    double button_height = 50 * this->game_->y_scalar();
    double button_space = 20 * this->game_->y_scalar();

    for (int i = 0; i < menu_buttons.size(); i++) {
        button_collider = dynamic_cast<Button*>(menu_buttons[i])->collider();
        button_collider->set_x(button_x);
        button_collider->set_width(button_width);
        button_collider->set_y(button_y);
        button_collider->set_height(button_height);

        button_y += button_y + button_space;
    }
}
