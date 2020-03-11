package main

/*
#include <stdlib.h>
#include "./cfiles/MockMulticastSdk.h"
#cgo LDFLAGS: ./cfiles/libMockMulticastSdk.a

// Forward declaration of gateway function
extern void did_recv_message_cgo (
	MockMarlinSdk* client,
	const char* message);
*/
import "C"
import (
	"fmt"
	"unsafe"
)

//export go_did_recv_message
func go_did_recv_message (client *C.struct_MockMarlinSdk, message *C.char) {
	fmt.Printf("Hello\n")
}

func main() {
	var msdk_pointer *C.struct_MockMarlinSdk
	msdk_pointer = C.sdk_create(C.int(1), C.int(2))
	C.sdk_set_recv_cb(
		msdk_pointer,
		C.did_recv_message_func(unsafe.Pointer(C.did_recv_message_cgo)),
	)


	goMessage := "go message"
	message := C.CString(goMessage)
	C.free(unsafe.Pointer(message))
	C.sdk_send_message(msdk_pointer, message)

	msdk2 := C.struct_MockMarlinSdk {
		foo: 3,
		bar: 4,
	}

	C.sdk_set_bar(&msdk2, 3)


	fmt.Printf("sdk_pointer foo %d\n", msdk_pointer.foo)
	fmt.Printf("sdk2 foo %d\n", msdk2.foo)
}
