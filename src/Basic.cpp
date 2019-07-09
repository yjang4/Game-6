#include "Basic.h"

void setText(Text &text, string s, Vector2f pos, float ctrSize, Color color, bool center)
{
    text.setFont(GD::font);
    text.setCharacterSize(ctrSize);
    text.setString(s);
    FloatRect fl = text.getLocalBounds();
    if(center) text.setOrigin(fl.left + fl.width / 2.0f, fl.top + fl.height / 2.0f);
    text.setPosition(pos);
    text.setFillColor(color);
}
void setBox(RectangleShape &rect, Vector2f pos, Vector2f boxSize, Color fillColor, Color outlineColor, bool center)
{
    rect.setSize(boxSize);
    if(center) rect.setOrigin(Vector2f(boxSize.x / 2, boxSize.y / 2));
    rect.setPosition(pos.x, pos.y);
    rect.setFillColor(fillColor);
    rect.setOutlineThickness(4.0f);
    rect.setOutlineColor(outlineColor);
}
bool isLeftClick()
{
    if(GD::event.type == Event::MouseButtonPressed)
    {
        if (GD::event.mouseButton.button == Mouse::Left)
        {
            return true;
        }
    }
    return false;
}
void setSprite(Texture &texture, Sprite &sprite, float scaler, Vector2f pos, Vector2i origin, int offset)
{
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, offset, offset));
    if(origin != Vector2i(-1, -1))
        sprite.setOrigin(origin.x, origin.y);
    else sprite.setOrigin(offset / 2, offset / 2);
    sprite.setPosition(pos);
    sprite.setScale(scaler, scaler);
}
