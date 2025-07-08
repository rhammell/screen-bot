/*
 * Screen_Bot Library Implementation
 */

#include "Screen_Bot.h"

Screen_Bot::Screen_Bot() : tft(TFT_CS, TFT_DC, TFT_RST) {
    // No initialization needed for capacitive touchscreen
}

void Screen_Bot::begin() {
    // Configure display LED pin
    pinMode(TFT_LED, OUTPUT);

    // Set display brightness to full
    analogWrite(TFT_LED, 255);

    // Initialize display object
    tft.begin();
    tft.setRotation(0);
    
    // Fill screen with black background
    tft.fillScreen(ILI9341_BLACK);
    
    // Set default text properties
    tft.setTextSize(1);
    tft.setTextColor(ILI9341_WHITE);
    
    // Initialize capacitive touchscreen
    ts.begin();
}

void Screen_Bot::clearDisplay() {
    tft.fillScreen(ILI9341_BLACK);
}

void Screen_Bot::setRotation(uint8_t rotation) {
    tft.setRotation(rotation);
}

void Screen_Bot::setBrightness(uint8_t brightness) {
    analogWrite(TFT_LED, brightness);
}

void Screen_Bot::setTextSize(uint8_t size) {
    tft.setTextSize(size);
}

void Screen_Bot::setTextColor(uint16_t color) {
    tft.setTextColor(color);
}

void Screen_Bot::setCursor(int16_t x, int16_t y) {
    tft.setCursor(x, y);
}

void Screen_Bot::print(const char* text) {
    tft.print(text);
}

void Screen_Bot::println(const char* text) {
    tft.println(text);
}

void Screen_Bot::fillScreen(uint16_t color) {
    tft.fillScreen(color);
}

void Screen_Bot::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    tft.drawRect(x, y, w, h, color);
}

void Screen_Bot::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    tft.fillRect(x, y, w, h, color);
}

void Screen_Bot::drawCircle(int16_t x, int16_t y, int16_t r, uint16_t color) {
    tft.drawCircle(x, y, r, color);
}

void Screen_Bot::fillCircle(int16_t x, int16_t y, int16_t r, uint16_t color) {
    tft.fillCircle(x, y, r, color);
}

void Screen_Bot::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
    tft.drawLine(x0, y0, x1, y1, color);
}

bool Screen_Bot::isTouched() {
    return ts.touched();
}

void Screen_Bot::getTouchPoint(int16_t &x, int16_t &y) {
    TS_Point p = ts.getPoint();
    x = p.x;
    y = p.y;
}

TS_Point Screen_Bot::getTSPoint() {
    return ts.getPoint();
}

TS_Point Screen_Bot::getCorrectedTouchPoint() {
    TS_Point p = ts.getPoint();
    
    // Get current rotation to determine mapping
    uint8_t rotation = tft.getRotation();
    
    // Apply coordinate correction based on screen orientation
    switch (rotation) {
        case 0: // Portrait
            p.x = map(p.x, 0, getWidth(), getWidth(), 0);
            p.y = map(p.y, 0, getHeight(), getHeight(), 0);
            break;
        case 1: // Landscape
            p.x = map(p.x, 0, getHeight(), getHeight(), 0);
            p.y = map(p.y, 0, getWidth(), 0, getWidth());
            break;
        case 2: // Portrait inverted
            p.x = map(p.x, 0, getWidth(), 0, getWidth());
            p.y = map(p.y, 0, getHeight(), 0, getHeight());
            break;
        case 3: // Landscape inverted
            p.x = map(p.x, 0, getHeight(), 0, getHeight());
            p.y = map(p.y, 0, getWidth(), getWidth(), 0);
            break;
    }
    
    return p;
}

Adafruit_ILI9341& Screen_Bot::getDisplay() {
    return tft;
}

Adafruit_FT6206& Screen_Bot::getTouch() {
    return ts;
}

int16_t Screen_Bot::getWidth() {
    return tft.width();
}

int16_t Screen_Bot::getHeight() {
    return tft.height();
}