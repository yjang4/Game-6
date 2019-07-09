#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <Basic.h>

class Animator
{
    public:
        Animator();
        Animator(Sprite &sprite);
        void animate(int y, int frames = 2, int slowness = 5);
        void setAnimator(Sprite &sprite, int slowness, int offset);
        void reset(int y = 0);
        void pause(int y);

    private:
        int tick = 0;
        int tickCondition = 0;
        Sprite *spr;
        int ofs, slow;

};

#endif // ANIMATOR_H
