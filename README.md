# Spotify Desk Display
![1000031835](https://github.com/user-attachments/assets/efe232be-5e75-4114-84c6-18c6fc755443)
### What is it?

This spotify desk display displays the current song + artists. This one has no controls and just sits on your desk! Check out this youtube demo

### Features

- Changeable font! See font section below on how to change font
- Runs on 3v3, decently low power consumption
- All the parts cost < $10! Super affordable
- Centers all media played, pretty aesthetic :)

### CAD 

See the .3mf file for the full CAD and case files can be found in the case folder! This design uses 3 M3 heatsets + M3 bolts. Technically it's optional and you can get away with gluing the back on. 

### Customization

If you would like to change the startup icon (big spotify logo), or any other icon that is drawn, follow this tutorial: https://www.instructables.com/Converting-Images-to-Flash-Memory-Iconsimages-for-/   
It goes very in depth on how to create bitmaps.  
  
You can also change the font! I played around with this for a few hours and found a pretty simple way.
- Head over here: https://oleddisplay.squix.ch/
- Select  TFT 2.4" (easier for viewing)
- You can tinker around with the size, in my code example I use both 19 & 14 pt font (for track and artist)
- Set library version to Adafruit GFX Font
- Change the Font Family to anything you'd like! Scroll through them and look at the preview on the screen. 
- Press Generate and copy the result
- Create a new text file, and paste it in there
- Go to the bottom line of your text file, it should look something like this:  

 (uint8_t  *)Dialog_plain_16Bitmaps,(GFXglyph *)Dialog_plain_16Glyphs,0x20, 0x7E, 0};

- Copy the "Dialog_plain_16" or whatever equivalent font name you have
- Click save as, and save the file to Documents\Arduino\libraries\Adafruit_GFX_Library\Fonts
- Save the file as "Dialog_plain_16.h" 
- In your code editor, include the font as such: #include <Fonts/Syncopate_Bold_16.h>
- Then after initializing your tft, set the font by using tft.setFont(&Syncopate_Bold_16)
- Remember the & before your font name! 

### Hardware required

This project is relatively cheap! As mentioned before, the whole thing came to under $10.
- Any esp32 board will work, I used a LOLIN C3 MINI
- A GC9A01A screen, 240 * 240 px 
- 3D printed parts, If you don't have your own 3D printer, this may be a little costly. 

### Setup

Install these libraries!  
- https://github.com/FinianLandes/SpotifyEsp32  
- Adafruit_ST7735  (can be found in library manager)
- Adafruit_GFX  (can be found in library manager)

Next, we will set up the client for Spotify.
- Hop over to https://developer.spotify.com/ and click on your profile in the top left and click dashboard.   
- Press create new app and you'll be prompted with this screen:   
![image](https://github.com/user-attachments/assets/08ea6cbd-1e50-4130-96ad-a5f4a30cbff7)  
- Name it anything you'd like and give it some random description. Add a random redirect URI for now. (we will change the redirect URI once we plug the ESP32 in)  
- Now, click on your newly created app and copy the client id + client secret and paste it into the code. Also, fill in the SSID and PASSWORD fields!
- Upload the code to the ESP and power it on, you should be prompted with a IP address on the screen or in the serial monitor.   
- Head back to the developer page and edit the app, and add in that IP as the callback URI. For example: I have 192.168.1.18 as my IP, the callback URI would be https://192.168.1.18/callback/, make sure to include the last slash!   
- You should be all good to go! Reset the ESP32 again and it should work once you login. Note you do not need to fill out the REFRESH_TOKEN field, it will be filled out by the code once you login!   
