#include "../include/finite_state_machine.h"
#include "../include/interaction_simulated.h"
#include <iostream>


/*
This module implement the class FiniteStateMachine who is responsible for the behaviour of the led.
Based on the type of interaction.h we include we will have different behaviours.
interaction_simulated.h: simulated led that prints to the shell the led's behaviours.
interaction_real.h: real library of GPIO for the led. #ToDO
*/

int FiniteSateMachine::index = 0;
int FiniteSateMachine::currentState = 0;

FiniteSateMachine::FiniteSateMachine() {}

FiniteSateMachine& FiniteSateMachine::getInstance() {
    static FiniteSateMachine instance;
    return instance;
}

char FiniteSateMachine::next_input(const std::array<char, 4>& inputsIn,int InputSizeIn) {
	//std::cout << "index next input = "<< index << std::endl;
	//std::cout << "inputSize next input = "<< inputSize << std::endl;
    if (index>=InputSizeIn) {
        std::cout << "[ERROR]Input quantity overflow" << std::endl;
        return 'x'; 
    }
    return inputsIn[index++];
}

void FiniteSateMachine::setCurrentState(int state) {
    currentState = state;
}

int FiniteSateMachine::getCurrentState() {
    return currentState;
}

/*
return (0<=2); returning correctly the next calculated state
return -1; character not allowed in that state
return -2; out of bound of inputs
return -3; internal error
return 3; Final state reached
*/
int FiniteSateMachine::computeNextState(int currentState, char character) {
			switch(currentState) {
				case 0:
					switch(character) {
						case 'x' :return -2;
						case 'a' : 
							setCurrentState(2);
							return 2;
						case 'b' : 
							setCurrentState(1);
							return 1;
						case 'c': 
							setCurrentState(3);
							return 3; 
						break;
					}
					break;
				case 1: 
					switch(character) {
						case 'x' :return -2;
						case 'b' : 
							setCurrentState(1);
							return 1;
						case 'c' : 
							setCurrentState(3);
							return 3; 
						case 'a' : return -1;
						break;

					}
					break;
				case 2:
					switch(character) {
						case 'x' :return -2;
						case 'a' : 
							setCurrentState(0);	
							return 0;
						case 'b' : return -1;
						case 'c': return -1; 
						break;
					}
					break;
				case 3: 
					return 3;
					break;
			}
			return -3;
		}

void FiniteSateMachine::computeOutput(int currentState, int nextState) {
			//std::array<std::string, 4>& SimulatedLed = Led.getLed();
			std::cout << "[INFO] Board switched from " << currentState << " to " << nextState << std::endl;
			switch(nextState){
				case 0:
					interaction(nextState,currentState); //depending on the hardware (in this case we use print_out_fsm.cpp)
					break;
				case 1:
					interaction(nextState,currentState);
					break;
				case 2:
					interaction(nextState,currentState);
					break;
				case 3:
					interaction(nextState,currentState);
					std::cout << "[INFO] FINAL STATE REACHED!!!" << std::endl;
					break;
				case -1: 
					std::cout << "[ERROR] Next state not allowed from this state" << std::endl; 
					break;
				case -2:
					std::cout << "[ERROR] Input out of bound, modify the input array size if you want to give more inputs to the board" << std::endl;
					break;
				case -3:
					std::cout << "[ERROR] Internal error, idk" << std::endl;
					break;
				default:
					std::cout << "[ERROR] Unknown state" << std::endl;
					break;
			}
		
		}

