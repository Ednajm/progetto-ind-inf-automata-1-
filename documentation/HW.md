# **Hardware Documentation**

L’obiettivo della parte hardware è realizzare una **Macchina di Moore** su breadboard, in grado di accendere LED di colore diverso a seconda dello stato corrente della FSM.

Il sistema utilizza una **scheda STM32L475 (B-L475E-IOT01A2)** come microcontrollore.

---

### **Schema Hardware**

![Hardware](./images/hw_setup.png)

*(l’immagine deve mostrare la breadboard con i collegamenti tra STM32 e LED)*

---

### **Componenti Utilizzati**

| Componente                  | Quantità | Descrizione                       |
| --------------------------- | -------- | --------------------------------- |
| STM32L475 (B-L475E-IOT01A2) | 1        | Microcontrollore principale       |
| Breadboard                  | 1        | Piattaforma di montaggio circuiti |
| LED Blu                     | 1        | Stato iniziale (S0)               |
| LED Rosso                   | 1        | Stato di errore                   |
| LED Giallo                  | 1        | Stati intermedi (S1, S2)          |
| LED Verde                   | 1        | Stato finale (S3)                 |
| Resistenze (220 Ω)          | 4        | Limitazione corrente LED          |
| Cavi jumper                 | vari     | Collegamenti tra MCU e breadboard |
| Alimentazione 3.3V          | 1        | Fornita dalla scheda STM32        |

---

### **Mappatura GPIO – LED**

| LED   | Colore | Stato FSM           | GPIO Pin | Descrizione                   |
| ----- | ------ | ------------------- | -------- | ----------------------------- |
| LED 1 | Blu    | S0 (stato iniziale) | GPIO 0   | Even sequence of `a`          |
| LED 2 | Rosso  | Errore              | GPIO 1   | Input non valido              |
| LED 3 | Giallo | S1 / S2             | GPIO 2   | Sequenza `b` o `a` dispari    |
| LED 4 | Verde  | S3 (stato finale)   | GPIO 3   | Parola valida, termina in `c` |

---

### **Descrizione del Funzionamento**

* La **STM32** riceve in input i caratteri (`a`, `b`, `c`) tramite terminale seriale o pulsanti (a seconda della configurazione).
* In base all’input, la **FSM software** cambia stato.
* Ogni stato attiva un **GPIO diverso**, che accende il LED corrispondente.
* Le uscite sono di tipo **Moore**, quindi dipendono solo dallo stato corrente.
* Il circuito è alimentato a **3.3V** direttamente dalla scheda STM32.

---

### **Note Tecniche**

* Tutti i LED devono essere collegati con resistenze da **1000 Ω** per limitare la corrente.
* Le masse (GND) di LED e MCU devono essere **comuni**.
* È consigliato tenere i cavi ordinati e corti per evitare interferenze.