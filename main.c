#include <stdio.h>
#include <stdint.h>

// Handler definition
typedef void (*example_TestAHandlerFunc_t)(int32_t messageID, void* contextPtr);

// Structure to represent a message
typedef struct {
    int32_t messageID;
    const char* content;
} Message;

// Reference type used by Add/Remove functions for EVENT 'example_TestA'
typedef struct example_TestAHandler* example_TestAHandlerRef_t;

// Function to handle the 'example_TestA' event
void handleMessage(int32_t messageID, void* contextPtr) {
    printf("New message received. ID: %d\n", messageID);
    // You can access other information in the contextPtr if needed.
}

// Function to add a handler for 'example_TestA' event
example_TestAHandlerRef_t example_AddTestAHandler(
    uint32_t data,
    example_TestAHandlerFunc_t handlerPtr,
    void* contextPtr
) {
    // In a real scenario, you might want to store the handler information for later use (e.g., removal).
    // For simplicity, we'll just print a message here.
    printf("Handler added for 'example_TestA' event.\n");
    handlerPtr(data, contextPtr);  // Call the handler immediately for demonstration.
    return NULL;  // Return a reference (in a real scenario, this could be a structure containing handler info).
}

int main() {
    // Assume you have a message received from a network or some other source.
    Message receivedMessage = {123, "Hello, World!"};

    // Add a handler for the 'example_TestA' event
    example_AddTestAHandler(receivedMessage.messageID, handleMessage, &receivedMessage);

    return 0;
}
