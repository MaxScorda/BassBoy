#include <Arduboy2.h>
#include <ArduboyTones.h>
#include <Tinyfont.h>

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());
// =========== fine parametri BOOT

// ======= scala =======

  String scoreb[] = {("C"), ("Db"), ("D"), ("Eb"),
             ("E"), ("F"), ("Gb"), ("G"),
             ("Ab"), ("A"), ("Bb"), ("B")
            };

  String scoreN [] = {("Do"), ("Reb"), ("Re"), ("Mib"),
              ("Mi"), ("Fa"), ("Sob"), ("Sol"),
              ("Lab"), ("La"), ("Sib"), ("Si")
             };

char scalamaggiore[] = {0, 2, 2, 1, 2, 2, 2 };
char scalaminore[] = {0, 2, 1, 2, 2, 1, 2 };
char bassfret[] = {7, 2, 9, 4};

const uint16_t allNotes[] PROGMEM = {262, 277, 294, 311,
                                     330, 349, 370, 392,
                                     415, 440, 466, 494
                                    };
//indice scala
int scalapos = 0; //da 0 a 23, 0..11 Maggiore, 12...23 minore
int fretpos = 0;


//contatore di inversione schermo
long blinktime;
//contatore funzioni speciali
long specialcount; 
//stato di inversione
boolean statusInvert = false;
//Status (vedi funzione)
byte statusMode = 1;
//mute
boolean mute=false;

void setup() {
  arduboy.boot();
  //arduboy.begin();  //old mode
  Serial.begin(9600);
  initDisplay();

  //audio
  sound.volumeMode(VOLUME_ALWAYS_HIGH);
  blinktime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  arduboy.pollButtons();
  LeggiPulsanti();
  if (millis() - blinktime > 10000) {
    statusInvert = !statusInvert;
    arduboy.invert(statusInvert);
    blinktime = millis();
  }

}
