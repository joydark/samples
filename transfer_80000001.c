#include "transfer_80000001.h"
#include "ton-sdk/tvm.h"
#include "ton-sdk/messages.h"

void transfer_Impl () {
    // MsgAddressInt structure corresponds to the structure from TON 
    // blockchain document.
    MsgAddressInt dest;

    // Anycast messages are not supported in current C SDK, so specify 0 in 
    // this field.
    dest.anycast = 0; 

    // We work with workchain 0.
    dest.workchain_id = 0;

    // Destination address: unsigned ints in TVM are 256-bits, so a contract 
    // address easily fits into unsigned.
    dest.address = 0x80000001;

    // Call library function, which builds empty internal message (internal
    // message with empty payload). Note that MsgAddressInt structure is 
    // passed by pointer. The message is built in work slice, which is kept 
    // deep in standard library. You can not work with its value directly, 
    // however you can serialize values to it and deserialize values from it.
    //
    // The function build_internal_message in its turn empties the work slice, 
    // and then performs several serializations, thus preparing an internal 
    // message.
    build_internal_message (&dest, 0xAAAA);

    // Call library function, which sends message, prepared in work slice.
    // The argument of the function is sending flag.
    send_raw_message (0);
}
