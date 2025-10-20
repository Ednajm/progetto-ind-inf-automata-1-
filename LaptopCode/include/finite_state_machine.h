#pragma once
#include <array>



class FiniteSateMachine {
private: 
    FiniteSateMachine();
    static int index;

public: 
    FiniteSateMachine(FiniteSateMachine&) = delete; // prevent from copying
    static FiniteSateMachine& getInstance();
    static int currentState;
    
    void setCurrentState(int state);
    int getCurrentState();
    char next_input(const std::array<char, 4>& inputsIn,int InputSizeIn);
    int computeNextState(int currentState, char character);
    void computeOutput(int currentState, int nextState);
};
