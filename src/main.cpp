#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include <SDL2/SDL.h>
#include <sugarlab/Game.hpp>
#include "menuscene.hpp"
#include "gamescene.hpp"
using namespace std;

int main() {
    cout << "test" << endl << endl;

    Game* missilewar = new Game(1920, 1080);
    missilewar->set_window_clear_color(0, 0, 0);

    GameScene* game_scene = new GameScene("game", missilewar);
    MenuScene* menu_scene = new MenuScene("menu", missilewar);

    missilewar->set_asset_loader("res/img/", "res/sfx/");

    missilewar->add_scene(game_scene);
    missilewar->add_scene(menu_scene);

    missilewar->set_scene("menu");

    missilewar->run();

    cout << endl << endl << "end" << endl;

    return 0;
}
