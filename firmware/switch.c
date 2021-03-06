#include <avr/io.h>
#include <avr/interrupt.h>  /* for sei() */
#include <util/delay.h>     /* for _delay_ms() */
#include <avr/pgmspace.h>   /* required by usbdrv.h */

#include "peri.h"
#include "usbdrv.h"
#define RQ_GET_SWITCH_1      1
#define RQ_GET_SWITCH_2      2
#define RQ_GET_SWITCH_3      3
#define RQ_GET_SWITCH_4      4
#define RQ_GET_SWITCH_5      5
/* ------------------------------------------------------------------------- */
/* ----------------------------- USB interface ----------------------------- */
/* ------------------------------------------------------------------------- */
usbMsgLen_t usbFunctionSetup(uint8_t data[8])
{
    usbRequest_t *rq = (void *)data;

    /* declared as static so they stay valid when usbFunctionSetup returns */
    static uint8_t switch_state; 
    

     if (rq->bRequest == RQ_GET_SWITCH_1)
    {
        switch_state = IS_SWITCH1_PRESSED();
	

        /* point usbMsgPtr to the data to be returned to host */
        usbMsgPtr = &switch_state;

        /* return the number of bytes of data to be returned to host */
        return 1;
    }else if (rq->bRequest == RQ_GET_SWITCH_2)
    {
        switch_state = IS_SWITCH2_PRESSED();
	

        /* point usbMsgPtr to the data to be returned to host */
        usbMsgPtr = &switch_state;

        /* return the number of bytes of data to be returned to host */
        return 1;
    }else if (rq->bRequest == RQ_GET_SWITCH_3){
    
        switch_state = IS_SWITCH3_PRESSED();
	

        /* point usbMsgPtr to the data to be returned to host */
        usbMsgPtr = &switch_state;

        /* return the number of bytes of data to be returned to host */
        return 1;
    }else if (rq->bRequest == RQ_GET_SWITCH_4){
    
        switch_state = IS_SWITCH4_PRESSED();
	

        /* point usbMsgPtr to the data to be returned to host */
        usbMsgPtr = &switch_state;

        /* return the number of bytes of data to be returned to host */
        return 1;
    }else if (rq->bRequest == RQ_GET_SWITCH_5){
    
        switch_state = IS_SWITCH5_PRESSED();
	

        /* point usbMsgPtr to the data to be returned to host */
        usbMsgPtr = &switch_state;

        /* return the number of bytes of data to be returned to host */
        return 1;
    }
    

    /* default for not implemented requests: return no data back to host */
    return 0;
}

/* ------------------------------------------------------------------------- */
int main(void)
{
    init_peripheral();

    usbInit();

    /* enforce re-enumeration, do this while interrupts are disabled! */
    usbDeviceDisconnect();
    _delay_ms(300);
    usbDeviceConnect();

    /* enable global interrupts */
    sei();

    /* main event loop */
    for(;;)
    {
        usbPoll();
    }

    return 0;
}

/* ------------------------------------------------------------------------- */
