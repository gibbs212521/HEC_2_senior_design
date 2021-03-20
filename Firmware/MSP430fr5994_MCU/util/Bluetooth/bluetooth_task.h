#ifndef __MC_MSP430_H
#define __MC_MSP430_H
#include <msp430fr5994.h>
#endif

#ifndef __MC_BLUETOOTH_INIT_H
#include "bluetooth_init.h"
#endif

#ifndef __MC_BLUETOOTH_CONN_H
#include "bluetooth_conn.h"
#endif


#ifndef __MC_BLUETOOTH_TRANS_H
#include "bluetooth_trans.h"
#endif

#ifndef __MC_BLUETOOTH_H
#define __MC_BLUETOOTH_H

void mc_bluetooth_task(short * pintroit);
/*
    This method should be done functionally.
*/

#endif
