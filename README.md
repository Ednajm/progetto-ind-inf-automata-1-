# Picolo — Finite State Machine (Moore) project

Picolo is an educational project that implements a Moore finite-state machine (FSM) that recognizes a small language and demonstrates state outputs via LEDs (or a simulated console). The repository contains two main targets:

- Laptop simulation (platform-independent C++ code) under `LaptopCode/`.
- STM32 MCU target (hardware implementation) under `stm_basic_code/`.

The machine recognizes strings made of `a`, `b`, `c` according to the project specification:
Identify even sequences of `a` (even including empty), followed by zero or more `b`, ended by `c`.

Repository layout
--------------

- `LaptopCode/` — Desktop-friendly C++ implementation and Makefile to build a console simulation.
- `stm_basic_code/` — STM32 project with HAL-based code for running on B-L475E-IOT01A2.
- `documentation/` — Hardware and software documentation (FSM diagram, wiring, design notes).

Quick start — laptop simulation
-------------------------------

1. Build:

```bash
cd LaptopCode
make
```

2. Run the simulation (binary `main`):

```bash
./main
# or if build output went to build/ or bin/, run the generated executable there
```

The program reads input characters (`a`, `b`, `c`) from stdin (or a test vector) and prints state transitions and output LED mapping.

STM32 target (flash to board)
-----------------------------

Open `stm_basic_code/INF_IND.ioc` or load the `stm_basic_code/` project into STM32CubeIDE. Build and flash according to your toolchain. The HAL layer in `LaptopCode/include/interaction_simulated.h` shows the expected HAL interface.

Documentation
-------------

See `documentation/SW.md` for software design, FSM diagram and interfaces. See `documentation/HW.md` for wiring and hardware notes.

Contributing
------------

If you'd like expanded documentation (English translation, Doxygen for C++ sources, README examples, diagrams), tell me the desired scope and I'll add it.

License
-------

Check project files for license information or ask the original authors.
# Progetto Ind. Inf. Automata 1
# progetto-ind-inf-automata-1-
