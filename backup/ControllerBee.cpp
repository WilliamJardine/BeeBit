#include "MicroBit.h"

#define GO_INPUT 28
#define PAUSE_INPUT 24
#define CLEAR_INPUT 20
#define FORWARD_INPUT 16
#define BACKWARD_INPUT 11
#define RIGHT_INPUT 6
#define LEFT_INPUT 1
#define GO 1
#define PAUSE 2
#define CLEAR 3
#define FORWARD 4
#define BACKWARD 5
#define RIGHT 6
#define LEFT 7
#define SLEEP_TIME 1000

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

//The storing of user commands
int actions[40];

//The current number of commands
int size = 0;

/*Adds an action command to the current stored actions
  Displays the command to the MicroBit LED display
 */
void addAction(int action, MicroBitImage image) {
    actions[size++] = action;
    uBit.display.print(image);
    uBit.sleep(500);
}

//Drives motors on or off

void motor(int p0, int p16, int p8, int p12, MicroBitImage image) {
    uBit.display.print(image);
    uBit.io.P16.setDigitalValue(p16);
    uBit.io.P0.setDigitalValue(p0);
    uBit.io.P12.setDigitalValue(p12);
    uBit.io.P8.setDigitalValue(p8);
    uBit.sleep(SLEEP_TIME);
}

void executeAction() {
    for (int i = 0; i < size; i++) {
        switch (actions[i]) {
            case PAUSE:
                motor(1, 1, 1, 1, PAUSE_IMG);
                break;
            case FORWARD:
                uBit.display.print(FORWARD_IMG);
                motor(1, 0, 1, 0, FORWARD_IMG);
                break;
            case BACKWARD:
                uBit.display.print(BACKWARD_IMG);
                motor(0, 1, 0, 1, BACKWARD_IMG);
                break;
            case RIGHT:
                uBit.display.print(RIGHT_IMG);
                motor(0, 0, 1, 0, RIGHT_IMG);
                break;
            case LEFT:
                uBit.display.print(LEFT_IMG);
                motor(1, 0, 0, 0, LEFT_IMG);
                break;
            default:
                motor(0, 0, 0, 0, DEFAULT_IMG);
        }
    }
    motor(0, 0, 0, 0, TICK_IMG);
}

int main() {
    // Initialize the micro:bit runtime.
    uBit.init();

    // The pin we are getting button presses from
    MicroBitPin P2(MICROBIT_ID_IO_P2, MICROBIT_PIN_P2, PIN_CAPABILITY_ALL);

    //Storage for the analog value
    int p2Value;

    while (1) {
        p2Value = P2.getAnalogValue();
        
        //Debugging to terminal
//        if (p2Value < 70) {
            uBit.serial.send(p2Value);
            uBit.serial.send('\n');
//            uBit.sleep(1000);
//        }

        //Turns on LEDs on pin 11 when light reading is below a threshold
        //        if (uBit.display.readLightLevel() < 10)
        //            uBit.io.P11.setDigitalValue(1);
        //        else
        //            uBit.io.P11.setDigitalValue(0);
        
        if (size == 40) {
            uBit.display.print(GO_IMG);
            executeAction();
            uBit.sleep(SLEEP_TIME * size);
            size = 0;
            uBit.display.clear();
        }

        switch (p2Value) {
            case GO_INPUT:
                uBit.display.print(GO_IMG);
                executeAction();
                break;
            case CLEAR_INPUT: //Clears LEDs and resets command counter
                uBit.display.print(CLEAR_IMG);
                size = 0; //Temp fix. Doesn't remove all elements from array.
                //memset(myarray, 0, sizeof(myarray));  
                uBit.sleep(SLEEP_TIME);
                break;
            case PAUSE_INPUT:
                addAction(PAUSE, PAUSE_IMG);
                break;
            case FORWARD_INPUT:
                addAction(FORWARD, FORWARD_IMG);
                break;
            case BACKWARD_INPUT:
                addAction(BACKWARD, BACKWARD_IMG);
                break;
            case RIGHT_INPUT:
                addAction(RIGHT, RIGHT_IMG);
                break;
            case LEFT_INPUT:
                addAction(LEFT, LEFT_IMG);
                break;
            default:
                uBit.display.clear();
                //uBit.sleep(1);
        }
    }
}