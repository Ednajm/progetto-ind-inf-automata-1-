#include "../include/finite_state_machine.h"

int main()
{   
    FiniteSateMachine& Fsm = FiniteSateMachine::getInstance();
    std::array<char, 4> inputs = {'a', 'a', 'b', 'c'};
    int inputSize = inputs.size();
    char character;

    while(1) {
        int prevState = Fsm.getCurrentState();
        //std::cout << "prev state = " << prevState << std::endl;

        character = Fsm.next_input(inputs,inputSize);
        //std::cout << "character = " << character << std::endl;

        int nextState = Fsm.computeNextState(prevState,character);
        //std::cout << "next state" << nextState << std::endl;

        Fsm.computeOutput(prevState,nextState);

        if (character == 'x' || nextState == 3) {
            break;
        }
    }    
    return 0;
}