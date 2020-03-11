package main

// CALLING THE GO FUNCTIONS FROM THE GATEWAY FUNCTION

/*
#include "./cfiles/MockMulticastSdk.h"

extern void go_did_recv_message (
	MockMarlinSdk* client,
	const char* message);

// Gateway function
void did_recv_message_cgo (
	MockMarlinSdk* client,
	const char* message) {
 	go_did_recv_message(client, message);
}
*/
import "C"
