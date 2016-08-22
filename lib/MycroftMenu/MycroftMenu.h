#include "MycroftDisplay.h"
#include "MycroftEncoder.h"

class MycroftMenu {
public:
    MycroftMenu(int pinCS1, int pinWR, int pinDATA, int pinENC1, int pinENC2, int pinBUTTON);
    enum menuState {
        MAIN, BRIGHTNESS
    };
    menuState getCurrentMenu();
    void run();
    void enter();
    void finishTest();
    void breatheStarted();
    void updateOptionIndex(bool up);
    bool isEntered();
    bool checkTest();
    bool checkBreathe();
    bool withinUpperBound();
    bool withinLowerBound();
    void checkButton();

private:
    MycroftDisplay display;
    MycroftEncoder encoder;
    bool entered, shouldTest, breathe;
    struct OptionContainer {
        enum Option{
            WIFI, RESET, REBOOT, SHUTDOWN, TEST, EXIT, BRIGHTNESS, BREATHE
        };
        Option option;
    };
    menuState currentState;
    OptionContainer menuOptions[8];
    uint8_t optionIndex;
    const uint8_t maxIndex = 7;
    void insertOptions();
    void drawOption(String option, bool arrow);
};
