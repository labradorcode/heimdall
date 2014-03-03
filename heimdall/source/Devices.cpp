/* Copyright (c) 2014 Quark Security Inc
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.*/

// C Standard Library
#include <stdio.h>

// Heimdall
#include "Arguments.h"
#include "BridgeManager.h"
#include "Heimdall.h"
#include "Interface.h"
#include "Devices.h"

using namespace std;
using namespace libpit;
using namespace Heimdall;

const char *Devices::usage = "Action: devices\n\
Description: Prints a list of bus:port pairs for devices that Heimdall recognizes\n\
	Use this with --usb-bus and --usb-port to specify which connected device to flash\n";

int Devices::Execute(int argc, char **argv)
{
        int communicationDelay = BridgeManager::kCommunicationDelayDefault;

        BridgeManager *bridgeManager = new BridgeManager(0, communicationDelay);

        bridgeManager->SetUsbLogLevel(BridgeManager::UsbLogLevel::None);

	bridgeManager->ListDevices();	
	return 0;
}
