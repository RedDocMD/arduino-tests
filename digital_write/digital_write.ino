
void setup() {
	pinMode(5, OUTPUT);
}

void fixed_delay() {
	for (int i = 0; i < (1 << 30); i++) {
		asm volatile ("nop" : : : "memory");
	}
}

void loop() {
	digitalWrite(5, 0);
	fixed_delay();
	digitalWrite(5, 1);
	fixed_delay();
}
