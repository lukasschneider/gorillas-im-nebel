

// Bullet.cpp

#include "Bullet.h"

void Bullet::update(float dt) {
    rect.x += cos(angle) * speed * dt;
    rect.y += sin(angle) * speed * dt;
}

void Bullet::render(SDL_Renderer* renderer) const {
    SDL_FRect renderRect = {rect.x, rect.y, rect.w, rect.h};
    SDL_RenderCopyExF(renderer, texture, NULL, &renderRect, angle * 180 / M_PI, NULL, SDL_FLIP_NONE);
}

Bullet::Bullet(float x, float y, float speed, float angle, SDL_Renderer* renderer)
        : rect{x, y, 25, 25}, speed(speed), angle(angle)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}