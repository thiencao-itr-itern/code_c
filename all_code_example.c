#include <stdio.h>

#define MY_DEFINE 2

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

// Set the click handler for a buttons
void SetButtonClickHandler(Button* button, ButtonClickHandlerFunc_t clickHandler) {
    button->clickHandler = clickHandler;
}

// Simulate button 
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
    #endif
#endif

int main() {
    #if MY_DEFINE == 1
    // buttonA click
        Button buttonA;
        SetButtonClickHandler(&buttonA, HandleButtonClickA);
        SimulateButtonClick(&buttonA);

        Button buttonB;
        SetButtonClickHandler(&buttonB, HandleButtonClickB);
        SimulateButtonClick(&buttonB);
    #endif
    // buttonB click
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
    return 0;
}



// //======================================================================================================
// #include <stdio.h>

// // Biến toàn cục (Không nên sử dụng)
// int globalVariable = 10;

// // Hàm truy cập thay vì trực tiếp sử dụng biến toàn cục
// int getGlobalVariable() {
//     return globalVariable;
// }

// void setGlobalVariable(int value) {
//     globalVariable = value;
// }

// int main() {
//     printf("Initial Global Variable: %d\n", getGlobalVariable());

//     // Thay đổi giá trị bằng hàm truy cập
//     setGlobalVariable(20);

//     // In giá trị mới bằng hàm truy cập
//     printf("Modified Global Variable: %d\n", getGlobalVariable());

//     return 0;
// }


// //========================================== const pointer =================================