#include <Arduboy2.h>
#include <ArduboyTones.h>
#include <time.h>
#include <Tinyfont.h>
Arduboy2 arduboy;
#define ARDBITMAP_SBUF arduboy.getBuffer()
#include <ArdBitmap.h>
ArdBitmap<WIDTH, HEIGHT> ardbitmap;
ArduboyTones sound(arduboy.audio.enabled);


const unsigned char PROGMEM BUD_TERENCE[] ={
0x7f, 0xb7, 0x7f, 0x76, 0xe0, 0xc8, 0xbf, 0x41, 0xcb, 0x85, 0x78, 0x51, 0xfe, 0xeb, 0xc1, 0x69, 
0xc8, 0x16, 0xc2, 0xbf, 0x3b, 0x16, 0xee, 0xde, 0x32, 0x1d, 0x7e, 0x88, 0x0b, 0x97, 0xec, 0x1b, 
0x67, 0xfe, 0x6d, 0x0d, 0x79, 0xcb, 0x6d, 0x1d, 0xf6, 0x61, 0xee, 0xc3, 0x08, 0x25, 0x3d, 0x7a, 
0x75, 0x36, 0x11, 0xe4, 0xdf, 0x11, 0x7b, 0x30, 0x99, 0x6c, 0x8e, 0x23, 0x26, 0xc3, 0x65, 0xd0, 
0xa5, 0xea, 0x12, 0xc9, 0x5e, 0x87, 0x23, 0x1b, 0xf2, 0x2f, 0xca, 0xd3, 0xdc, 0x39, 0xc3, 0xcf, 
0x54, 0x4e, 0x1e, 0x57, 0xff, 0x7d, 0xf1, 0x31, 0xae, 0xd4, 0x1d, 0xf8, 0x0c, 0xc7, 0xf1, 0x9c, 
0x8b, 0x72, 0xe3, 0xee, 0x95, 0x3f, 0x37, 0xf2, 0x98, 0xf3, 0x1a, 0x87, 0x24, 0xa3, 0x23, 0xcd, 
0x4a, 0x72, 0x50, 0x2f, 0xc1, 0x8b, 0xe4, 0xb0, 0x28, 0x0b, 0xf8, 0x9b, 0xf3, 0x63, 0x39, 0xf4, 
0x52, 0xc6, 0xba, 0xac, 0xcb, 0xba, 0x8c, 0x5b, 0x8f, 0x7c, 0xab, 0x7a, 0x78, 0xc1, 0xe7, 0x3d, 
0x22, 0x37, 0xe4, 0xc4, 0xe0, 0xce, 0xe0, 0x6d, 0x6e, 0x3d, 0xad, 0x53, 0x61, 0x0e, 0x3a, 0x44, 
0x00, 0x6c, 0x5b, 0x99, 0x84, 0x27, 0x9e, 0xa2, 0x7b, 0xef, 0xc3, 0x3a, 0xe5, 0x33, 0xcc, 0xec, 
0x77, 0xdc, 0x18, 0x1d, 0x72, 0xe2, 0xa0, 0x49, 0x75, 0x31, 0xbd, 0x7a, 0xdb, 0xe3, 0x1f, 0x41, 
0x4e, 0x73, 0xc0, 0x89, 0x5f, 0xfd, 0x27, 0x63, 0x20, 0xe0, 0x81, 0x01, 0x2c, 0xc7, 0xb4, 0x29, 
0xa4, 0xa3, 0xc3, 0x8e, 0x75, 0x77, 0xd0, 0x81, 0x10, 0xe1, 0x87, 0xf5, 0x92, 0xcd, 0x01, 0x6e, 
0xec, 0xca, 0xc5, 0x05, 0x74, 0x25, 0x70, 0x64, 0x86, 0x83, 0x4e, 0xe1, 0x0e, 0x16, 0xc9, 0xea, 
0xb0, 0xfe, 0x8b, 0xe0, 0x36, 0xc7, 0xe7, 0x3d, 0xed, 0xf1, 0xd7, 0x03,
};

const unsigned char PROGMEM TIGRE[] ={
0x79, 0xff, 0xff, 0x39, 0xc8, 0x69, 0x1d, 0xf6, 0xde, 0x7b, 0x5e, 0xd6, 0x65, 0xdc, 0xf2, 0x9a,
0xff, 0x36, 0x9a, 0x76, 0xf4, 0xe8, 0x31, 0xbf, 0x51, 0x3a, 0x4f, 0x4e, 0xff, 0x43, 0x47, 0x7d,
0x97, 0x59, 0x97, 0x32, 0x18, 0x3d, 0xec, 0x23, 0x4f, 0x79, 0xc3, 0x0f, 0xe0, 0xc4, 0x94, 0x43,
0xfe, 0x43, 0x97, 0xd3, 0x18, 0x66, 0x5a, 0x2e, 0xfc, 0x35, 0x2c, 0x68, 0x38, 0x72, 0xe2, 0xbf,
0x7e, 0x61, 0xac, 0x4b, 0x65, 0x63, 0x60, 0xef, 0x43, 0x7e, 0x65, 0x0f, 0xff, 0x71, 0xf4, 0x50,
0xc0, 0x8d, 0x1c, 0xbc, 0xa8, 0x1b, 0x2e, 0x7c, 0x3e, 0x97, 0xc3, 0xf8, 0x2f, 0xa5, 0xf4, 0xe4,
0x63, 0xb2, 0x98, 0xbe, 0xea, 0xe1, 0x30, 0xfe, 0xd3, 0x3c, 0xfe, 0x15, 0x02,
};

const unsigned char PROGMEM CARTA[] ={
0x75, 0xbf, 0x5f, 0xe9, 0x4b, 0x9e, 0xf1, 0x75, 0x9e, 0xf1, 0x67, 0xe0, 0x20, 0x4e, 0xc2, 0x13,
0x60, 0x02, 0x00, 0xe1, 0xe8, 0x9d, 0xf8, 0x29, 0xbe, 0xc0, 0x6f, 0xe1, 0xd7, 0xf1, 0x1d, 0xe5,
0x39, 0x4f, 0x01, 0xb9, 0x00, 0xff, 0xfa, 0x79, 0xee, 0x3f, 0x2b, 0xee, 0x9c, 0xb8, 0x71, 0x67,
0xf2, 0x47, 0xe2, 0xc6, 0x17, 0xb9, 0x21, 0x7f, 0x4a, 0x4e, 0xdc, 0xf9, 0x18, 0xb2, 0x59, 0x9c,
0x38, 0x51, 0x5e, 0x12, 0xe0, 0x47, 0xf0, 0x05, 0x7e, 0x1f, 0xbf, 0x93, 0xc1, 0xa2, 0xbc, 0x43,
0xfe, 0x69, 0xf2, 0xa7, 0xe4, 0x11, 0x9b, 0x27, 0x4c, 0x3e, 0xca, 0xef, 0xe1, 0xc4, 0x4f, 0x60,
0xf8, 0x6f, 0x97, 0xdf, 0xc9, 0xbf, 0x46, 0xfe, 0xd5, 0xf1, 0x98, 0x3f, 0x09, 0x07, 0x2e, 0xfc,
0xbb, 0x41, 0x5e, 0x30, 0x11, 0x91, 0xf0, 0x8e, 0xfa, 0x86, 0xcd, 0x27, 0xb9, 0x3a, 0x79, 0xc6,
0x41, 0xf9, 0x67, 0x89, 0xfc, 0x2a, 0x26, 0x93, 0x23, 0x7f, 0x7d, 0xfe, 0x0c, 0xfc, 0x9b, 0x66,
0xf0, 0x2f, 0x8b, 0x3f, 0x0c,
};


void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(60);
}

int scena=0;
int x=0;
int raggio=7;
int note=NOTE_G6;
int times=5;
unsigned long now;
unsigned long end = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (!(arduboy.nextFrame())){
    return;
  }
  arduboy.clear();
  arduboy.pollButtons();
  now=millis()-end;

  if(scena==0){
    arduboy.setCursor(40, 25);
    arduboy.print("INTANTO");
    if(now>3000){
      scena++;
    }
  }
  else if(scena==1){
    arduboy.setCursor(2, 25);
    arduboy.print("NELLA TANA DEL TIGRE");
    if(now>6000){
      scena++;
    }
  }
  else if(scena==2){
    ardbitmap.drawCompressed(WIDTH / 2 ,(HEIGHT / 2)-1, CARTA, WHITE, ALIGN_CENTER, MIRROR_NONE);
    arduboy.fillCircle(10, 10, raggio, WHITE);
    if(arduboy.everyXFrames(5)){
      raggio--;
      if(raggio<=0){
        raggio=7;
      }
    }

    if(times){
      if(x==0){
        sound.tone(NOTE_AS7,150);     
        x++;  
        note=NOTE_G6;
      }
          
      if(x==1 && !sound.playing() && note>NOTE_D6){
        sound.tone(note-=30,30);      
      }
      if(note<=NOTE_D6){
        x=0;
        times--;
      }
    }
    
    if(now>9000){
      scena++;
      raggio=10;
      note=NOTE_DS4;
    }
  }
  else if(scena==3){
    ardbitmap.drawCompressed(WIDTH / 2 ,(HEIGHT / 2)-1, CARTA, WHITE, ALIGN_CENTER, MIRROR_NONE);
    arduboy.fillCircle(10, 10, raggio, WHITE);
    if(arduboy.everyXFrames(12) && raggio){
      raggio--;
    }
    if(!sound.playing() && note>=NOTE_DS3){
        sound.tone(note,30);
        note-=2;
    }
    if(now>11000){
      scena++;
    }
  }
  else if(scena==4){
    ardbitmap.drawCompressed(WIDTH / 2 ,(HEIGHT / 2)-5, BUD_TERENCE, WHITE, ALIGN_CENTER, MIRROR_NONE);
    arduboy.setCursor(0, 57);

    if(now<13500){
      arduboy.print("Hanno freddato il");
    }

    if(now>13500){
      arduboy.print("nostro uomo in Alaska");
    }

    if(now>16000){
      scena++;
    }
  }
  else if(scena==5){
    ardbitmap.drawCompressed(WIDTH / 2 ,(HEIGHT / 2)-5, BUD_TERENCE, WHITE, ALIGN_CENTER, MIRROR_NONE);
    arduboy.setCursor(75, 57);

    arduboy.print("Peccato!");

    if(now>19000){
      scena++;
    }
  }
  else if(scena==6){
    ardbitmap.drawCompressed(WIDTH / 2 ,(HEIGHT / 2)-4, TIGRE, WHITE, ALIGN_CENTER, MIRROR_NONE);

    arduboy.setCursor(0, 57);

    if(now<21000){
      arduboy.print("Eh si!");
    }
    else{
      arduboy.print("era un ottimo agente!");
    }

    if(now>24000){
      scena++;
    }
    
  }
  else{
    arduboy.setCursor(45, 25);
    arduboy.print("FINE");

    arduboy.setCursor(25, 40);
    arduboy.print("Premi A per");
    arduboy.setCursor(10, 50);
    arduboy.print("guardare da capo");

    if(arduboy.justPressed(A_BUTTON)){
      scena=0;
      x=0;
      raggio=7;
      note=NOTE_G6;
      times=5;
      end=now;
    }

  }

  arduboy.display();
}
