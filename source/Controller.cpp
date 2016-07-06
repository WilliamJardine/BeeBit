#include "MicroBit.h"
#include "controller.h"

MicroBit uBit;

//The default image

MicroBitImage DEFAULT_IMG("\
    1 1 1 1 1\n\
    1 1 1 1 1\n\
    1 1 1 1 1\n\
    1 1 1 1 1\n\
    1 1 1 1 1\n");

//The image of a forward arrow

MicroBitImage FORWARD_IMG("\
    0 0 1 0 0\n\
    0 1 1 1 0\n\
    1 0 1 0 1\n\
    0 0 1 0 0\n\
    0 0 1 0 0\n");

//The image of a backward arrow

MicroBitImage BACKWARD_IMG("\
    0 0 1 0 0\n\
    0 0 1 0 0\n\
    1 0 1 0 1\n\
    0 1 1 1 0\n\
    0 0 1 0 0\n");

//The image of a left arrow

MicroBitImage LEFT_IMG("\
    0 0 1 0 0\n\
    0 1 0 0 0\n\
    1 1 1 1 1\n\
    0 1 0 0 0\n\
    0 0 1 0 0\n");

//The image of a right arrow

MicroBitImage RIGHT_IMG("\
    0 0 1 0 0\n\
    0 0 0 1 0\n\
    1 1 1 1 1\n\
    0 0 0 1 0\n\
    0 0 1 0 0\n");

//The image of a smiley face

MicroBitImage GO_IMG("\
    0 1 0 1 0\n\
    0 1 0 1 0\n\
    0 0 0 0 0\n\
    1 0 0 0 1\n\
    0 1 1 1 0\n");

//The image of a straight face

MicroBitImage PAUSE_IMG("\
    0 1 0 1 0\n\
    0 1 0 1 0\n\
    0 0 0 0 0\n\
    1 1 1 1 1\n\
    0 0 0 0 0\n");

//The image of a sad face

MicroBitImage CLEAR_IMG("\
    0 1 0 1 0\n\
    0 1 0 1 0\n\
    0 0 0 0 0\n\
    0 1 1 1 0\n\
    1 0 0 0 1\n");

//The image of a tick 

MicroBitImage TICK_IMG("\
    0 0 0 0 0\n\
    0 0 0 0 1\n\
    0 0 0 1 0\n\
    1 0 1 0 0\n\
    0 1 0 0 0\n");

int actions[40];
int size = 0;

void addAction(int action, MicroBitImage image) {
    actions[size++] = action;
    uBit.display.print(image);
    uBit.sleep(SLEEP_TIME);
}

void motor(int p0, int p16, int p8, int p12, MicroBitImage image) {
    uBit.display.print(image);
    uBit.io.P16.setDigitalValue(p16);
    uBit.io.P0.setDigitalValue(p0);
    uBit.io.P12.setDigitalValue(p12);
    uBit.io.P8.setDigitalValue(p8);
    uBit.sleep(SLEEP_TIME);
}

void executeAction() {
    for (int i = 0; i < size; i ++) {
        switch (actions[i]) {
            case PAUSE:
            motor(1, 1, 1, 1, PAUSE_IMG);
            break;
            case FORWARD:
            uBit.display.print(FORWARD_IMG);
            motor(0, 1, 0, 1, FORWARD_IMG);
            break;
            case BACKWARD:
            uBit.display.print(BACKWARD_IMG);
            motor(1, 0, 1, 0, BACKWARD_IMG);
            break;
            case RIGHT:
            uBit.display.print(RIGHT_IMG);
            motor(1, 0, 0, 0, RIGHT_IMG);
            break;
            case LEFT:
            uBit.display.print(LEFT_IMG);
            motor(0, 0, 1, 0, LEFT_IMG);
            break;
            default:
            motor(0, 0, 0, 0, DEFAULT_IMG);
        }
    }
    motor(0, 0, 0, 0, TICK_IMG);
}

void go(){
    uBit.display.print(GO_IMG);
    executeAction();
    uBit.display.clear();
}

void clear(){
    uBit.display.print(CLEAR_IMG);
size = 0; //Temp fix. Doesn't remove all elements from array.
uBit.sleep(SLEEP_TIME);
}

//Returns 1 if value from analog pin is in specific range
int inRange(int min, int max, int curValue){
    if (curValue >= min && curValue <= max)
        return 1;
    return 0;
}

int main() {
// Initialize the micro:bit runtime.
    uBit.init();
    motor(0, 0, 0, 0, DEFAULT_IMG);
    uBit.sleep(200);

// THe pin we are getting button presses from
    MicroBitPin P2(MICROBIT_ID_IO_P2, MICROBIT_PIN_P2, PIN_CAPABILITY_ALL);

    int p2Value = -1;
    while (1) {
        p2Value = P2.getAnalogValue();
        if(inRange(GO_INPUT_MIN, GO_INPUT_MAX, p2Value))
            go(); 
        else if (inRange(PAUSE_INPUT_MIN, PAUSE_INPUT_MAX, p2Value))
            addAction(PAUSE, PAUSE_IMG);
        else if (inRange(CLEAR_INPUT_MIN, CLEAR_INPUT_MAX, p2Value))
            clear();
        else if (inRange(FORWARD_INPUT_MIN, FORWARD_INPUT_MAX, p2Value))
            addAction(FORWARD, FORWARD_IMG);
        else if (inRange(BACKWARD_INPUT_MIN, BACKWARD_INPUT_MAX, p2Value))
            addAction(BACKWARD, BACKWARD_IMG);
        else if (inRange(RIGHT_INPUT_MIN, RIGHT_INPUT_MAX, p2Value))
            addAction(RIGHT, RIGHT_IMG);
        else if (inRange(LEFT_INPUT_MIN, LEFT_INPUT_MAX, p2Value))
            addAction(LEFT, LEFT_IMG);
        else
            uBit.display.clear();
        uBit.sleep(50);
    }
}