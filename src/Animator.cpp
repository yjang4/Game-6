#include "Animator.h"

Animator::Animator()
{

}
Animator::Animator(Sprite &sprite)
{
    spr = &sprite;
}
void Animator::setAnimator(Sprite &sprite, int slowness, int offset)
{
    spr = &sprite;
    slow = slowness;
    ofs = offset;
}
void Animator::animate(int y, int frames, int slowness)
{
    if(slow < 1)
        slow = 1;
    spr -> setTextureRect(IntRect(ofs * tick, ofs * y, ofs, ofs));
    tickCondition ++;
    if(tickCondition > slowness)
    {
        tickCondition = 0;
        tick ++;
    }
    if(tick > frames) tick = 0;
}
void Animator::reset(int y)
{
    spr -> setTextureRect(IntRect(0, ofs * y, ofs, ofs));
}
void Animator::pause(int y)
{
    spr -> setTextureRect(IntRect(ofs * tick, ofs * y, ofs, ofs));
}
