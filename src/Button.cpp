#include "Button.h"

Button::Button(string name, Vector2f pos)
{
    setButton(name, pos);
}
void Button::setButton(string name, Vector2f pos)
{
    int rgb = 150;
    buttonColor = Color(rgb, rgb, rgb);
    setBox(rect, pos, Vector2f(200, 50), buttonColor, Color::Black, true);

    setText(text, name, pos, 30, Color::Black, true);
}
void Button::update()
{
    if(isMouseOn())
    {
        int rgb = 230;
        rect.setFillColor(Color(rgb, rgb, rgb));
        if(trigger)
        {
            GD::sm["touch"].play();
            trigger = 0;
        }
        if(isLeftClick())
        {
            if(trigger2)
            {
                GD::sm["select"].play();
                trigger2 = 0;
            }
            rgb = 50;
            rect.setFillColor(Color(rgb, rgb, rgb));
        }
    }
    else
    {
        rect.setFillColor(buttonColor);
        trigger = 1;
        trigger2 = 1;
    }
}
void Button::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(rect, states);
    target.draw(text, states);
}

bool Button::isMouseOn()
{
    Vector2i mousePos = Mouse::getPosition(GD::window);
    FloatRect fl = rect.getGlobalBounds();
    return mousePos.x > fl.left && mousePos.x < fl.left + fl.width
            && mousePos.y > fl.top && mousePos.y < fl.top + fl.height;
}
bool Button::isClicked()
{
    return isMouseOn() && isLeftClick();
}
