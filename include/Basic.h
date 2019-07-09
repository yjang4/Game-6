#ifndef BASIC_H
#define BASIC_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <GlobalData.h>

void setText(Text &text, string s, Vector2f pos, float ctrSize, Color color, bool center);
void setBox(RectangleShape &rect, Vector2f pos, Vector2f boxSize, Color fillColor, Color outlineColor, bool center);
bool isLeftClick();
void setSprite(Texture &texture, Sprite &sprite, float scaler, Vector2f pos = Vector2f(500, 500), Vector2i origin = Vector2i(-1, -1), int offset = 32);
#endif // BASIC_H
