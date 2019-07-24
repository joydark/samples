# Transfer 80000001

This contract sends 0xAAAA nanograms (43960 in decimal) 
to account number 0x80000001 (this account number is hardcoded in the contract).
This contract shows how to create and send internal messages.

## Methods

### Method `compute`
#### Input values
None

#### Output values
None

#### Notes
This method does not return any values, so it does not send external
messages. However, it sends internal message to account 0x80000001.
In order to properly test its execution, one can check balance of
account 0x80000001 before and after invocation of the method.

If you call this method for the first time on the given node, it is
highly probable that account 0x80000001 does not exist. In this case 
this message would create the account with balance of about 0xAAAA nanograms
(in reality it will be a little smaller, since message transfer is not free).

To check that, use `getaccount` command of test-lite-client (unluckily,
you cannot skip these 56 leading zeroes):

     getaccount 0:0000000000000000000000000000000000000000000000000000000080000001

## Persistent data
None
