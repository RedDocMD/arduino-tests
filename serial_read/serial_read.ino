#define NO_USB
#undef Serial
#define Serial _UART1_

void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.println("Enter your name:");
    String name;
    while (true) {
        while (!Serial.available()) {}
        char byte = Serial.read();
        if (byte == '\r' || byte == '\n') break;
        Serial.print(byte);
        name += byte;
    }
    // while (!Serial.available()) {}
    // char name = Serial.read();
    Serial.println();
    Serial.print("Welcome to Arduino on QEMU, ");
    Serial.print(name);
    Serial.println("!");
}
