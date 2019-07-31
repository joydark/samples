## Callback implementation sample
One contract calls another one and gets a response with a callback.

Contract MyContract (contract05-a) demonstrates how to call a remote contract by passing an integer 'value'. 
The remote contract (contract05-b) saves this 'value' in persistance variable and call method of caller using the address of the first contract.
```
function remoteMethod(uint16 x) public {
		// save paramets x in persistent variable 'm_value'
		m_value = x;
		// cast address of caller to IRemoteContractCallback interface and
		// call its 'remoteMethodCallback' method
		IRemoteContractCallback(msg.sender).remoteMethodCallback(x * 16);
		return; 
	}
```
