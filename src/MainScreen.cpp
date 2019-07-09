#include "MainScreen.h"

MainScreen::MainScreen()
{
    float _x = GD::gm["screenX"] / 2;
    float _y = GD::gm["screenY"] / 2;
    float offset = 60;
    b_newGame.setButton("New Game", Vector2f(_x, _y + offset * 0));
    b_loadGame.setButton("Load Game", Vector2f(_x, _y + offset * 1));
    b_exitGame.setButton("Exit", Vector2f(_x, _y + offset * 2));

    setText(title, "Peaceful RPG", Vector2f(_x, _y + offset * -2), 40, Color(230, 230, 230), true);
}
void MainScreen::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(title, states);
    target.draw(b_newGame, states);
    target.draw(b_loadGame, states);
    target.draw(b_exitGame, states);
}
void MainScreen::update()
{
    b_newGame.update();
    b_loadGame.update();
    b_exitGame.update();

    if(b_newGame.isClicked())
    {
        GD::gm["stage"] = 1;
    }
    if(b_exitGame.isClicked())
    {
        GD::window.close();
    }
}
