//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"

#include "ignition_subsystem.h"
#include "smart_car_system.h"
#include "windshield_wiper_subsystem.h"


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

/**
* Initializes the smart car system by initializing the subsystems
*/
void smartCarSystemInit()
{
    ignitionSubsystemInit();
    windshieldWiperInit();
}


/**
* Updates the smart car system by updating its subsystems
*/
void smartCarSystemUpdate()
{
    ignitionSubsystemUpdate();
    windshieldWiperUpdate();
    delay(TIME_INCREMENT_MS);
}

//=====[Implementations of private functions]==================================