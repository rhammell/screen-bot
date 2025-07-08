/*
 * Display Test Example for Screen_Bot Library
 * 
 * This example demonstrates basic text display functionality
 * by showing "Hello World" on the screen.
 */

 #include <Screen_Bot.h>

 Screen_Bot bot;
 
 void setup() {
   // Initialize the Screen_Bot
   bot.begin();
   
   // Set text properties
   bot.setTextSize(2);
   bot.setTextColor(ILI9341_WHITE);
   
   // Position text in the center of the screen
   bot.setCursor(25, 120);
   
   // Display "Hello World"
   bot.println("Hello World");
 }
 
 void loop() {
   // Nothing to do in the loop for this simple example
 } 