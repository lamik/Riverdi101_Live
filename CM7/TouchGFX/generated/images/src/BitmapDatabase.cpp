// 4.18.1 0xc003b554
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_bg[]; // BITMAP_BG_ID = 0, Size: 1280x800 pixels
extern const unsigned char image_blue_buttons_round_edge_small[]; // BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID = 1, Size: 170x60 pixels
extern const unsigned char image_blue_buttons_round_edge_small_pressed[]; // BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID = 2, Size: 170x60 pixels
extern const unsigned char image_msalamon_pl_nowe_transparent[]; // BITMAP_MSALAMON_PL_NOWE_TRANSPARENT_ID = 3, Size: 896x208 pixels
extern const unsigned char image_msalamonpl_nowe_big_icon_2488x772_png_transparent[]; // BITMAP_MSALAMONPL_NOWE_BIG_ICON_2488X772_PNG_TRANSPARENT_ID = 4, Size: 2488x772 pixels
extern const unsigned char image_msalamonpl_nowe_big_icon_2508x792_png_transparent_biale_obramowanie[]; // BITMAP_MSALAMONPL_NOWE_BIG_ICON_2508X792_PNG_TRANSPARENT_BIALE_OBRAMOWANIE_ID = 5, Size: 2508x792 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_bg, 0, 1280, 800, 0, 0, 1280, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 800, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_blue_buttons_round_edge_small, 0, 170, 60, 11, 4, 148, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 50, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_buttons_round_edge_small_pressed, 0, 170, 60, 11, 4, 148, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 50, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_msalamon_pl_nowe_transparent, 0, 896, 208, 56, 44, 117, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 117, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_msalamonpl_nowe_big_icon_2488x772_png_transparent, 0, 2488, 772, 169, 165, 438, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 438, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_msalamonpl_nowe_big_icon_2508x792_png_transparent_biale_obramowanie, 0, 2508, 792, 164, 161, 468, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 467, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
