#include "Player.h"

Player::Player()
{
    t_player.loadFromFile("images/ctr.png");
    scaler = 3.0f;
    setSprite(t_player, s_player, scaler, Vector2f(250, 100), Vector2i(ofs / 2, ofs - 2));
    GD::gm["playerspeed"] = 2;
    GD::gm["playerFallingSpeed"] = 5.0;
    GD::gm["playerJumpingPower"] = -7;
    ani_player.setAnimator(s_player, 5, ofs);
}
void Player::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(s_player, states);
}
void Player::update()
{
    keyboardUpdate();
    gravityUpdate();
    speed = GD::gm["playerspeed"];

    hitTiles();
    animateUpdate();
}
void Player::keyboardUpdate()
{
    if(Keyboard::isKeyPressed(Keyboard::Space) && onGround)
    {
        vel = GD::gm["playerJumpingPower"];
        onGround = false;
    }
    if(Keyboard::isKeyPressed(Keyboard::Up) && isHitLadder())
    {
        GD::gm["playerOnLadder"] = 1;
        s_player.move(0, -2);
    }
    if(Keyboard::isKeyPressed(Keyboard::Down) && isHitLadder())
    {
        GD::gm["playerOnLadder"] = 1;
        s_player.move(0, 2);
    }
    if(!isHitLadder())
    {
        GD::gm["playerOnLadder"] = 0;
    }

    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        velX = 2;
        GD::gm["playerOnLadder"] = 0;
        s_player.setScale(scaler, scaler);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        velX = -2;
        GD::gm["playerOnLadder"] = 0;
        if(s_player.getScale() == Vector2f(scaler, scaler)) s_player.setScale(-scaler, scaler);
    }
    else
    {
        velX = 0;
        ani_player.reset();
    }

}
void Player::hitTiles()
{
    Vector2f pos = s_player.getPosition();
    vector<Vector2f>::iterator it;
    for(it = GD::tm["ground"].begin(); it != GD::tm["ground"].end(); it ++)
    {
        Vector2f tilePos = *it;

        if(isHitTile(tilePos))
        {
            float coreX = tilePos.x + ofs / 2;
            float coreY = tilePos.y + ofs / 2;
            if(pos.y < coreY && GD::gm["playerOnLadder"] == 0
               && GD::gm["playerFalling"])
            {
                s_player.setPosition(pos.x, tilePos.y);
                onGround = true;
                GD::gm["playerOnLadder"] = 0;
            }
            /*else if(pos.x < coreX) // horizontal collision
            {
                s_player.setPosition(tilePos.x, pos.y);
            }
            else if(pos.x >= coreX)
            {
                s_player.setPosition(tilePos.x + ofs, pos.y);
            }*/
        }
    }
}
bool Player::isHitTile(Vector2f tilePos)
{
    Vector2f pos = s_player.getPosition();
    return pos.x + feetOfs >= tilePos.x && pos.x - feetOfs < tilePos.x + ofs
            && pos.y >= tilePos.y && pos.y <= tilePos.y + ofs;
}
bool Player::isHitLadder()
{
    vector<Vector2f>::iterator it;
    for(it = GD::tm["ladder"].begin(); it != GD::tm["ladder"].end(); it ++)
    {
        Vector2f tilePos = *it;
        if(isHitTile(tilePos))
            return true;
    }
    return false;
}
void Player::gravityUpdate()
{
    if(vel < GD::gm["playerFallingSpeed"])
    {
        vel += 0.2;
    }
    else vel = GD::gm["playerFallingSpeed"];
    if(vel > 0)
    {
        GD::gm["playerFalling"] = 1;
        onGround = false;
    }
    else GD::gm["playerFalling"] = 0;
    if(GD::gm["playerOnLadder"] == 0)
    {
        s_player.move(velX, vel);
    }
}
void Player::animateUpdate()
{
    if(GD::gm["playerOnLadder"])
    {
        if(Keyboard::isKeyPressed(Keyboard::Up) ||
           Keyboard::isKeyPressed(Keyboard::Down))
        ani_player.animate(4, 1, 15);
        else ani_player.pause(4);
    }
    else if(!onGround)
    {
        ani_player.animate(3);
    }
    else if(velX != 0)
    {
        ani_player.animate(1);
    }
    else ani_player.reset();
}
