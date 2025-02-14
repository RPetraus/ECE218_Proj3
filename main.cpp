//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"

#include "smart_car_system.h"

//=====[Defines]===============================================================

/*
#define BUZZER_ON 0
#define BUZZER_OFF 1
#define TIME_INCREMENT_MS 10
#define TIME_DEBOUNCE_MS 30
*/

//=====[Declaration of public data types]======================================

/*
typedef enum{
    BUTTON_UP,
    BUTTON_FALLING,
    BUTTON_DOWN,
    BUTTON_RISING
} debouncedIgnitionReleasedStateMachine_t;
*/

//=====[Declaration and initialization of public global objects]===============

/*
DigitalIn driverPresent(D10);
DigitalIn passengerPresent(D11);
DigitalIn driverSeatbelt(D12);
DigitalIn passengerSeatbelt(D13);
DigitalIn ignitionButton(BUTTON1);

DigitalOut greenLED(LED1);
DigitalOut blueLED(LED2);
DigitalOut sirenPin(PE_10);

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);
*/

//=====[Declaration and initialization of public global variables]=============

/*
int accumulatedButtonTime = 0;

bool engineStarted = false;
bool driverWelcomed = false;

debouncedIgnitionReleasedStateMachine_t ignitionButtonState;
*/

//=====[Declarations (prototypes) of public functions]=========================

/*
void inputsInit();
void outputsInitIgnition();

void welcomeMessage();
void errorMessage();

void debounceIgnitionInit();
bool debounceIgnition();

void ignitionEnable();
bool ignitionUpdate();
*/

int main()
{
    smartCarSystemInit();
    while (true) {
        smartCarSystemUpdate();
    }
}


//=====[Implementations of public functions]===================================

/*
void inputsInit()
{
    driverPresent.mode(PullDown);
    passengerPresent.mode(PullDown);
    driverSeatbelt.mode(PullDown);
    passengerSeatbelt.mode(PullDown);
}

void outputsInitIgnition()
{
    greenLED = OFF;
    blueLED = OFF;
    sirenPin = BUZZER_OFF;
}

void debounceIgnitionInit()
{
    if( ignitionButton ) {
        ignitionButtonState = BUTTON_UP;
    } else {
        ignitionButtonState = BUTTON_DOWN;
    }
}

bool debounceIgnition()
{
    bool ignitionReleased = false;

    switch( ignitionButtonState ) {
        case BUTTON_UP:
            if( ignitionButton ) {
                ignitionButtonState = BUTTON_FALLING;
                accumulatedButtonTime = 0;
            }
            break;

        case BUTTON_FALLING:
            if( accumulatedButtonTime >= TIME_DEBOUNCE_MS ) {
                if( ignitionButton ) {
                    ignitionButtonState = BUTTON_DOWN;
                } else {
                ignitionButtonState = BUTTON_UP;
                }
            }
            accumulatedButtonTime = accumulatedButtonTime + TIME_INCREMENT_MS;
            break;
        
        case BUTTON_DOWN:
            if (!ignitionButton){
                ignitionButtonState = BUTTON_RISING;
                accumulatedButtonTime = 0;
            }
            break;

        case BUTTON_RISING:
            if (!ignitionButton){
                ignitionButtonState = BUTTON_UP;
                ignitionReleased = true;
            }
            else{
                ignitionButtonState = BUTTON_DOWN;
            }
            accumulatedButtonTime = accumulatedButtonTime + TIME_INCREMENT_MS;
            break;
    }
    return ignitionReleased;
}

void ignitionEnable()
{
    if (driverPresent && driverSeatbelt && passengerPresent && passengerSeatbelt){
        greenLED = ON;
    }
    else{
        greenLED = OFF;
    }
}

void welcomeMessage()
{
    if (driverPresent && !driverWelcomed){
        uartUsb.write("Welcome to enhanced alarm system model 218-W25\r\n", 48);
        driverWelcomed = true;
    }
    else if (!driverPresent){
        driverWelcomed = false;
    }
}

void errorMessage()
{

    uartUsb.write("Ignition Inhibited\r\n", 20);
    
    if(!driverPresent){
        uartUsb.write("Driver seat not occupied.\r\n", 27);
    } 
    if(!driverSeatbelt){
        uartUsb.write("Driver seatbelt not fastened.\r\n", 31);
    }
    if(!passengerPresent){
        uartUsb.write("Passenger seat not occupied.\r\n", 30);
    }
    if(!passengerSeatbelt){
        uartUsb.write("Passenger seatbelt not fastened.\r\n", 34);
    }
}

bool ignitionUpdate()
{
    welcomeMessage();
    ignitionEnable();
    if (!engineStarted && debounceIgnition()){
        uartUsb.write("Ignition attempted.\r\n", 21);
        if (!greenLED){
            sirenPin = BUZZER_ON;
            errorMessage();
            engineStarted = false;
        }
        else{
            sirenPin = BUZZER_OFF;
            greenLED = OFF;
            blueLED = ON;
            uartUsb.write("Engine started.\r\n", 17);
            engineStarted = true;
        }
    }
    else if (engineStarted && debounceIgnition()){
        uartUsb.write("Engine off.\r\n", 13);
        engineStarted = false;
        blueLED = OFF;
    }
    
    return engineStarted;
}
*/