#ifndef ROTARY_SPEED_ENCODER
#define ROTARY_SPEED_ENCODER

/*******************************************************************************
*                               Standard Libraries
*******************************************************************************/

/*******************************************************************************
*                               Header Files
*******************************************************************************/

#include "utilities/util-vars.h"

/*******************************************************************************
*                               Static Functions
*******************************************************************************/

/*******************************************************************************
*                               Constants
*******************************************************************************/

/*******************************************************************************
*                               Structures
*******************************************************************************/

typedef enum {
    ROLLER_SPEED_ENCODER
} rotary_speed_encoder_id_t;

typedef struct {
    const uint8_t                   pin;
    const rotary_speed_encoder_id_t id;
    void                            (*isr)(void);
    unsigned long                   lastInterruptTime;
    bool                            initialized;
} rotary_speed_encoder_t;

/*******************************************************************************
*                               Variables
*******************************************************************************/

/*******************************************************************************
*                               Functions
*******************************************************************************/

robot_status_t rotarySpeedEncoder_init(rotary_speed_encoder_t* encoder);

rotary_speed_encoder_t* rotarySpeedEncoder_get(rotary_speed_encoder_id_t id);

#endif // ROTARY_SPEED_ENCODER