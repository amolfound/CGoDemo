#include "MockMulticastSdk.h"
#include <stdlib.h>
#include <stdio.h>

MockMarlinSdk* sdk_create(int foo, int bar) {
	MockMarlinSdk* sdk_pointer = malloc(sizeof(MockMarlinSdk));
	sdk_pointer->foo = foo;
	sdk_pointer->bar = bar;
	sdk_pointer->cb_recv_message = NULL;
	return sdk_pointer;
}

void sdk_set_foo(MockMarlinSdk* msdk, int foo) {
	msdk->foo = foo;
}

void sdk_set_bar(MockMarlinSdk* msdk, int bar) {
	msdk->bar = bar;
}

// dummy function to send message to itself
// recv callback function (cb_recv_message) is invoked

void sdk_send_message(MockMarlinSdk* msdk, char* message){
	printf("sending message: %s\n", message);

	if (msdk->cb_recv_message != NULL) {
		printf("callign recv callback: %s\n", message);
		msdk->cb_recv_message(msdk, message);
	}
}

void sdk_set_recv_cb (MockMarlinSdk* msdk, did_recv_message_func cb_recv_message) {
	msdk->cb_recv_message = cb_recv_message;
}

