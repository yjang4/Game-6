#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <Basic.h>
#include <Button.h>

class MainScreen : public Drawable
{
    public:
        MainScreen();
        virtual void draw(RenderTarget& target, RenderStates states) const;
        void update();

    private:
        Button b_newGame, b_loadGame, b_exitGame;
        Text title;

};

#endif // MAINSCREEN_H
