#ifndef BUTTON_H
#define BUTTON_H

#include <Basic.h>

class Button : public Drawable
{
    public:
        Button(){}
        Button(string name, Vector2f pos);
        bool isMouseOn();
        void update();
        void setButton(string name, Vector2f pos);
        virtual void draw(RenderTarget& target, RenderStates states) const;
        bool isClicked();

    private:
        Text text;
        RectangleShape rect;
        Color buttonColor;

        bool trigger = false;
        bool trigger2 = false;
};

#endif // BUTTON_H
