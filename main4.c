#include <stdio.h>
#include <stdint.h>

#define MY_DEFINE 1

#ifdef MY_DEFINE
    #if MY_DEFINE == 1
        // Handler definition
        typedef void (*ButtonClickHandlerFunc_t)();

        // Button structure
        typedef struct {
            ButtonClickHandlerFunc_t clickHandler;
        } Button;

        // Function to handle button click event
        void HandleButtonClickA() {
            printf("Button A clicked!\n");
        }

        void HandleButtonClickB() {
            printf("Button B clicked!\n");
        }

        // Set the click handler for a button
        void SetButtonClickHandler(Button* button, ButtonClickHandlerFunc_t clickHandler) {
            button->clickHandler = clickHandler;
        }

        // Simulate button click
        void SimulateButtonClick(Button* button) {
            if (button->clickHandler != NULL) {
                button->clickHandler();
            }
        }

    #elif MY_DEFINE == 2
        // Handler definition
        typedef void (*EventHandlerFunc_t)();

        // Event structure
        typedef struct {
            EventHandlerFunc_t clickHandler;
            EventHandlerFunc_t doubleClickHandler;  // New handler for double click
        } Event;

        // Function to handle single click event
        void HandleClick() {
            printf("Single click!\n");
        }

        // Function to handle double click event
        void HandleDoubleClick() {
            printf("Double click!\n");
        }

        // Function to set the click handler for an event
        void SetClickHandler(Event* event, EventHandlerFunc_t clickHandler) {
            event->clickHandler = clickHandler;
        }

        // Function to set the double click handler for an event
        void SetDoubleClickHandler(Event* event, EventHandlerFunc_t doubleClickHandler) {
            event->doubleClickHandler = doubleClickHandler;
        }

        // Function to simulate a click event
        void SimulateClick(Event* event) {
            if (event->clickHandler != NULL) {
                event->clickHandler();
            }
        }

        // Function to simulate a double click event
        void SimulateDoubleClick(Event* event) {
            if (event->doubleClickHandler != NULL) {
                event->doubleClickHandler();
            }
        }

    #elif MY_DEFINE == 3
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

        // handle_function
        void my_handle_func(int32_t x, void* context_ptr) {
            if (context_ptr != NULL) {
                printf("\nHandle function is called. x = %d\n", x);
            } else {
                printf("\nHandle function is called. Context pointer is NULL.\n");
            }
        }

        // callback_function
        int32_t add_callback_func(uint32_t para, my_func_pointer_t handle_func, void* context_ptr) {
            // Check the validity of the context pointer
            if (context_ptr == NULL) {
                printf("Invalid context pointer.\n");
                return -1;
            }
            handle_func(((TestAHandler*)context_ptr)->x, context_ptr);

            return 0;  // Success
        }
    #endif
#endif

int main() {
    #if MY_DEFINE == 1
        // buttonA click
        Button buttonA;
        SetButtonClickHandler(&buttonA, HandleButtonClickA);
        SimulateButtonClick(&buttonA);
        // buttonB click
        Button buttonB;
        SetButtonClickHandler(&buttonB, HandleButtonClickB);
        SimulateButtonClick(&buttonB);
    #endif

    #if MY_DEFINE == 2
        // Create an event
        Event myEvent;

        // Set the click handler for the event
        SetClickHandler(&myEvent, HandleClick);

        // Set the double click handler for the event (new functionality)
        SetDoubleClickHandler(&myEvent, HandleDoubleClick);

        // Simulate a single click
        SimulateClick(&myEvent);

        // Simulate a double click (new functionality)
        SimulateDoubleClick(&myEvent);
    #endif

    #if MY_DEFINE == 3
        uint32_t ID = 42;
        TestAHandler handlerInstance = { 99 };	

        // Check the result of add_callback_func
        CHECK_CALLBACK(add_callback_func(ID, my_handle_func, &handlerInstance));
    #endif
    return 0;
}
