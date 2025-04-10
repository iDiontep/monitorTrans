/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen_screen/screenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

screenViewBase::screenViewBase()
{
    __background.setPosition(0, 0, 800, 600);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    image1.setXY(0, -8);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_BACKGROUNDS_1024X600_PUZZLE_ID));
    add(image1);

    flexButton1.setBoxWithBorderPosition(0, 0, 200, 50);
    flexButton1.setBorderSize(5);
    flexButton1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1.setText(TypedText(T___SINGLEUSE_QBAD));
    flexButton1.setTextPosition(0, 9, 200, 50);
    flexButton1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton1.setPosition(300, 257, 200, 50);
    add(flexButton1);
}

screenViewBase::~screenViewBase()
{

}

void screenViewBase::setupScreen()
{

}
