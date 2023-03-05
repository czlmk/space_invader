#pragma once
#include <cstdint>
#include <cstdio>
void buffer_draw_text(Buffer* buffer, const Sprite& text_spritesheet, const char* text, size_t x,size_t y, uint32_t color);
void buffer_draw_number(Buffer* buffer, const Sprite& number_spritesheet, size_t number, size_t x, size_t y, uint32_t color);