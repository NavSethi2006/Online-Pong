#include "game.h"

Texture tex;
Animation_set animations;

Frame RUN_ANIMATION[3] = {{0, 33, 20, 31},
                               {20, 33, 20, 31},
                               {40, 33, 20, 31}};

Frame IDLE_ANIMATION[1] = {0,0,17,32};

Frame JUMP_ANIMATION[5] = {{40, 80, 18, 31},
                               {70, 83, 16, 25},
                               {97, 86, 23, 20},
                               {129, 83, 18, 25},
                               {157, 84, 22, 23}};
                               
Frame WALL_CLIMB_ANIMATION[4] = {{0,199,17,32},
                                {40,201,17,32},
                                {80,200,16,31},
                            {118, 201, 23,31}};

Frame ATTACK_ANIMATION[3] = {{0,240,17,30},
                            {28,241,42,30},
                            {74,241,29,30},
                            {115,241,27,29}};

enum PlayerStates {
    IDLE,
    RUN,
    JUMP,
    WALL_CLIMB,
    ATTACK

} PlayerStates;


void game() {

    tex = get_texture_asset("../src/assets/player.png");

    set_texture(&tex, 20, 20, 30, 55);



    animations.animations[IDLE] = init_animation(IDLE_ANIMATION, 1, 0.5f);
    animations.animations[RUN] = init_animation(RUN_ANIMATION, 3, 0.2f);
    animations.animations[JUMP] = init_animation(JUMP_ANIMATION, 5, 0.1f);
    animations.animations[ATTACK] = init_animation(ATTACK_ANIMATION, 4, 0.1f);
    animations.animations[WALL_CLIMB] = init_animation(WALL_CLIMB_ANIMATION, 4, 0.1f);

    PlayerStates = IDLE;

}


void game_handle_event(SDL_Event *event) {

    if(event->type == SDL_EVENT_KEY_DOWN && event->key.key == SDLK_ESCAPE) {
        switch_scene(get_menu_scene());
    }

    if(event->type == SDL_EVENT_KEY_DOWN && event->key.key == SDLK_W) {
        PlayerStates = RUN;
    }
    if(event->type == SDL_EVENT_KEY_DOWN && event->key.key == SDLK_S) {
        PlayerStates = IDLE;
    }
    if (event->type == SDL_EVENT_KEY_DOWN && event->key.key == SDLK_SPACE) {
        PlayerStates = JUMP;
    }
    if (event->type == SDL_EVENT_KEY_DOWN && event->key.key == SDLK_A) {
        PlayerStates = ATTACK;
    }
    if (event->type == SDL_EVENT_KEY_DOWN && event->key.key == SDLK_D) {
        PlayerStates = WALL_CLIMB;
    }

}

void game_update(float delta_time) {

    //update_animation_set(&animations, PlayerStates,delta_time);



}

void game_render(Window *window) {

    //render_animation_set(&animations, PlayerStates,window);



}


Scene Game_Scene = {
    .init  = game,
    .handle_event = game_handle_event,
    .update = game_update,
    .render = game_render
};

Scene *get_game_scene() {
    return &Game_Scene;
}
