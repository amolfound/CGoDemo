#ifndef MOCK_MULTICASTSDK_H
#define MOCK_MULTICASTSDK_H

typedef struct MockMarlinSdk MockMarlinSdk;

typedef void (*did_recv_message_func) (
	MockMarlinSdk* client,
	const char* message
);

struct MockMarlinSdk {
	int foo;
	int bar;

	did_recv_message_func cb_recv_message;
};

MockMarlinSdk* sdk_create (int foo, int bar);
void sdk_set_foo (MockMarlinSdk* msdk, int foo);
void sdk_set_bar (MockMarlinSdk* msdk, int bar);
void sdk_send_message (MockMarlinSdk* msdk, char* message);
void sdk_set_recv_cb (MockMarlinSdk* msdk, did_recv_message_func cb_recv_message);
//void sdk_set_cb(cb_func);

#endif
