// #include <stdio.h>
// #include <stdint.h>
// // declare function pointer
// typedef void (*my_func_pointer_t)(int32_t x, void *context_ptr);
// typedef struct {
//     int32_t x;
// } TestAHandler;
// // declare handle function
// void my_handle_func(int32_t x, void *context_ptr);
// int32_t add_callback_func(uint32_t para, my_func_pointer_t handle_func, void *context_ptr);
// int main(){
// 	uint32_t parameterValue = 42;
// 	TestAHandler handlerInstance = {99};
// 	add_callback_func(parameterValue,my_handle_func,&handlerInstance);
// 	return 0;
// }
// void my_handle_func(int32_t x, void *context_ptr){
// 	printf("\nHandle function is call");
// }
// int32_t add_callback_func(uint32_t para, my_func_pointer_t handle_func, void *context_ptr){
// 	handle_func(((TestAHandler*)context_ptr)->x, context_ptr);
// }


#include <stdio.h>
#include <stdint.h>

// Declare function pointer type
typedef void (*my_func_pointer_t)(int32_t x, void* context_ptr);

#define CHECK_CALLBACK(result) \
	do { \
		printf("Callback %s.\n", (result == 0) ? "added successfully" : "failed to add"); \
	} while (0)


// Structure to represent a handler
typedef struct {
    int32_t x;
} TestAHandler;

// Declare handle function
void my_handle_func(int32_t x, void* context_ptr);

// Declare callback function
int32_t add_callback_func(uint32_t para, my_func_pointer_t handle_func, void* context_ptr);

int main() {
    uint32_t parameterValue = 42;
    TestAHandler handlerInstance = { 99 };	

    // Check the result of add_callback_func
    CHECK_CALLBACK(add_callback_func(parameterValue, my_handle_func, &handlerInstance));

    return 0;
}

void my_handle_func(int32_t x, void* context_ptr) {
    if (context_ptr != NULL) {
        printf("\nHandle function is called. x = %d\n", x);
    } else {
        printf("\nHandle function is called. Context pointer is NULL.\n");
    }
}

int32_t add_callback_func(uint32_t para, my_func_pointer_t handle_func, void* context_ptr) {
    // Check the validity of the context pointer
    if (context_ptr == NULL) {
        printf("Error: Invalid context pointer.\n");
        return -1;
    }

    // Perform the callback
    handle_func(((TestAHandler*)context_ptr)->x, context_ptr);

    return 0;  // Success
}


