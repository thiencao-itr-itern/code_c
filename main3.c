#include <stdio.h>

// Handler definition
typedef void (*ButtonClickHandlerFunc_t)();

// Button structure
typedef struct {
    ButtonClickHandlerFunc_t clickHandler;
} Button;

// Function to handle button click event
void HandleButtonClick() {
    printf("Button clicked!\n");
}

// Function to set the click handler for a button
void SetButtonClickHandler(Button* button, ButtonClickHandlerFunc_t clickHandler) {
    button->clickHandler = clickHandler;
}

// Function to simulate button click event
void SimulateButtonClick(Button* button) {
    if (button->clickHandler != NULL) {
        button->clickHandler();
    }
}

int main() {
    // Create a button
    Button myButton;

    // Set the click handler for the button
    SetButtonClickHandler(&myButton, HandleButtonClick);

    // Simulate a button click
    SimulateButtonClick(&myButton);

    return 0;
}
