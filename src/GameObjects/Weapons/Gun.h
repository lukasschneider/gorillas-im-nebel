#ifndef GORILLAGAME_GUN_H
#define GORILLAGAME_GUN_H

#include "../../lib/global.h"
#include "../../lib/BulletRingBuffer.h"
#include "../../lib/SoundManager.h"

class Gun {
public:
    int ammo;
    int magazin;
    float reloadTime;
    float timeSinceLastReload;
    bool isReloading{};

    std::string path = BasePath "asset/graphic/guns/ak.png";
    SDL_Texture* texture;
    SDL_Rect srcRect{};
    SDL_FRect dstRect{};

    BulletRingBuffer bullets;

    float timeSinceLastShot = 0.0f;
    const float shotDelay = 0.2f;
    float angle = 0.0f;

    explicit Gun(SDL_Renderer * render);

    [[nodiscard]] SDL_FPoint getBulletExitPosition() const;

    void render(SDL_Renderer *renderer);

    void update(int mouseX, int mouseY, const SDL_FRect &playerRect, const SDL_FRect &viewport, float dt);

    // Bullet Logic
    void fire(Renderer* renderer, SDL_FRect *vp, SoundManager * sm);

    void updateBullets(float dt);

    void renderBullets(SDL_Renderer *renderer, SDL_FRect *vp) const;

    [[nodiscard]] bool isEmpty() const;

    void reload();

    ~Gun();

};



#endif //GORILLAGAME_GUN_H
