#ifndef PLAYER_H
#define PLAYER_H

#include <Basic.h>
#include <Animator.h>

class Player : public Drawable
{
    public:
        Player();
        virtual void draw(RenderTarget& target, RenderStates states) const;
        void update();


    private:
        Texture t_player;
        Sprite s_player;
        Animator ani_player;
        float scaler, speed;
        int ofs = 32;
        int feetOfs = 2;

        void keyboardUpdate();
        void hitTiles();
        void gravityUpdate();
        void animateUpdate();
        bool isHitTile(Vector2f tilePos);
        bool isHitLadder();
        float vel = 0;
        float VEL = 3.0f;
        float velX = 0;
        bool onGround = false;


};

#endif // PLAYER_H
