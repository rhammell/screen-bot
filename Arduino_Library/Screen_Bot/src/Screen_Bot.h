/*
 * Screen_Bot Library Header
 * A library for controlling wheeled robots with TFT displays
 */

#ifndef SCREEN_BOT_H
#define SCREEN_BOT_H

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>
#include "config.h"

class Screen_Bot {
public:
    Screen_Bot();
    
    // Initialize the robot hardware
    void begin();
    
    // Display management
    void clearDisplay();
    void setRotation(uint8_t rotation);
    void setBrightness(uint8_t brightness);
    void setTextSize(uint8_t size);
    void setTextColor(uint16_t color);
    void setCursor(int16_t x, int16_t y);
    void print(const char* text);
    void println(const char* text);
    void fillScreen(uint16_t color);
    void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    void drawCircle(int16_t x, int16_t y, int16_t r, uint16_t color);
    void fillCircle(int16_t x, int16_t y, int16_t r, uint16_t color);
    void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    
    // Touch handling
    bool isTouched();
    void getTouchPoint(int16_t &x, int16_t &y);
    TS_Point getTSPoint();
    TS_Point getCorrectedTouchPoint();
    
    // Get display and touch objects for advanced usage
    Adafruit_ILI9341& getDisplay();
    Adafruit_FT6206& getTouch();
    
    // Get screen dimensions
    int16_t getWidth();
    int16_t getHeight();

private:
    // TFT Display object
    Adafruit_ILI9341 tft;
    
    // Touch screen object
    Adafruit_FT6206 ts;
};

#endif // SCREEN_BOT_H 