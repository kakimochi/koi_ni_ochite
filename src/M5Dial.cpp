#include "M5Dial.h"

using namespace m5;

M5_DIAL M5Dial;

void M5_DIAL::begin(bool enableEncoder, bool enableRFID) {
    M5.begin();
    if (enableEncoder) {
        Encoder.begin();
    }
    if (enableRFID) {
        Rfid.begin();
    }
}

void M5_DIAL::begin(m5::M5Unified::config_t cfg, bool enableEncoder,
                    bool enableRFID) {
    M5.begin(cfg);
    if (enableEncoder) {
        Encoder.begin();
    }
    if (enableRFID) {
        Rfid.begin();
    }
}

void M5_DIAL::update(void) {
    M5.update();
}

void reset()
{
    M5Dial.Encoder.readAndReset();

    M5Dial.Display.clear();
    M5Dial.Display.setTextColor(WHITE);
    M5Dial.Display.setTextDatum(middle_center);
    M5Dial.Display.setTextFont(&fonts::Orbitron_Light_32);
    M5Dial.Display.setTextSize(1);
    M5Dial.Display.drawString("Koi ni Ochite", M5Dial.Display.width() / 2, M5Dial.Display.height() / 2);
}

void draw_message(String str)
{
    // M5Dial.Display.clear();
    M5Dial.Display.setTextColor(WHITE);
    M5Dial.Display.setTextDatum(middle_center);
    M5Dial.Display.setTextFont(&fonts::Orbitron_Light_32);
    M5Dial.Display.setTextSize(1);
    M5Dial.Display.drawString(str, M5Dial.Display.width() / 2, M5Dial.Display.height() / 2);
}

void draw_enc(int count)
{
    // M5Dial.Display.clear();
    M5Dial.Display.setTextColor(WHITE);
    M5Dial.Display.drawString(String(count), M5Dial.Display.width()/2, M5Dial.Display.height()/2);
}

void draw_heart(LovyanGFX* gfx)
{
    // M5Dial.Display.clear();
    gfx->setColor(RED);
    const float scale = 4;
    const int offset_x = M5Dial.Display.width() / 2;
    const int offset_y = M5Dial.Display.height() / 2;

    for(float theta=-PI; theta <= PI; theta+=0.01)
    {
        float x = scale * (16 * pow(sin(theta), 3));
        float y = scale * (13 * cos(theta) - 5 * cos(2*theta) - 2 * cos(3*theta) - cos(4*theta));
        x =  x + offset_x;
        y =  -y + offset_y;
        gfx->drawPixel(x, y);
    }
}

void setup()
{
    auto cfg = M5.config();
    M5Dial.begin(cfg, true, true);

    reset();
}

long preEncPos = -999;

void loop()
{
    M5Dial.update();

    if( M5Dial.BtnA.wasClicked() ) {
        reset();
    }

    if( M5Dial.BtnA.wasDoubleClicked() ) {
        // draw_function(&M5Dial.Display);
        // draw_heart(&M5Dial.Display);
    }

    long currentEncPos = M5Dial.Encoder.read();
    if( currentEncPos != preEncPos ) {
        preEncPos = currentEncPos;

        M5Dial.Display.clear();
        if((currentEncPos > 0) && (currentEncPos < 11)) {
            draw_enc(currentEncPos);
        } else if ((currentEncPos >= 12) && (currentEncPos < 23)) {
            draw_heart(&M5Dial.Display);
        } else if ((currentEncPos >= 24) && (currentEncPos < 35)) {
            draw_heart(&M5Dial.Display);
            draw_message("I'm");
        } else if ((currentEncPos >= 36) && (currentEncPos < 47)) {
            draw_heart(&M5Dial.Display);
            draw_message("just a ..");
        } else if ((currentEncPos >= 48) && (currentEncPos < 59)) {
            draw_heart(&M5Dial.Display);
            draw_message("woman.");
        } else if ((currentEncPos >= 60) && (currentEncPos < 71)) {
            draw_message("- fall in love -");
        }
    }
}

