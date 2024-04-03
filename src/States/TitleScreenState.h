#include "State.h"
#include "ofMain.h"
#include "Button.h"

class TitleScreenState : public State {

    private:
        ofImage logo;
        int count;      // Used for the sinosoidal effect on the logo
        int amplitude;  // The amplitude of the sinosoidal effect
        int divisor;    // The divisor of the sinosoidal effect
        Button* startButton;
        Button* quitButton;
        ofTrueTypeFont font;

    public:
        TitleScreenState(){
            logo.load("logo.png");
            font.load("font.otf", 12);
            reset();
        }

        void update();
        void draw();
        void reset();
        void mousePressed(int x, int y, int button);
};