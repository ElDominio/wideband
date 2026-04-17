#include "port_shared.h"

// board-specific stuff shared between bootloader and firmware

static const CANConfig canConfig1000 =
{
    CAN_MCR_ABOM | CAN_MCR_AWUM | CAN_MCR_TXFP,
    /*
     For 24MHz http://www.bittiming.can-wiki.info/ gives us Pre-scaler=3, Seq 1=13 and Seq 2=2. Subtract '1' for register values
    */
   CAN_BTR_SJW(0) | CAN_BTR_BRP(1) | CAN_BTR_TS1(14) | CAN_BTR_TS2(1),
};

const CANConfig& GetCanConfig() {
    return canConfig1000;
}
