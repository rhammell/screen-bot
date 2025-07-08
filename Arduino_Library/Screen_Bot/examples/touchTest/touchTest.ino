/*
 * Touch Test Example for Screen_Bot Library
 * 
 * This example demonstrates touch input functionality
 * by drawing red circles wherever the user touches the screen.
 */

#include <Screen_Bot.h>

Screen_Bot bot;

void setup() {
  // Initialize the Screen_Bot
  bot.begin();
  
  // Clear the screen with black background
  bot.fillScreen(ILI9341_BLACK);
  
  // Set text properties for instructions
  bot.setTextSize(2);
  bot.setTextColor(ILI9341_WHITE);
  
  // Display instructions
  bot.setCursor(10, 10);
  bot.println("Touch Test");
  bot.setTextSize(1);
  bot.setCursor(10, 40);
  bot.println("Touch anywhere on screen");
  bot.println("to draw red circles");
}

void loop() {
    // Check if screen is touched
  if (bot.isTouched()) {
    // Get the corrected touch point (handles orientation automatically)
    TS_Point p = bot.getCorrectedTouchPoint();
    
    // Draw a red circle at the touch location
    bot.fillCircle(p.x, p.y, 2, ILI9341_RED);
    
    // Small delay to prevent multiple readings from the same touch
    delay(50);
  }
} 