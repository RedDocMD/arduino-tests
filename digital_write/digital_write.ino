#ifdef delay
#undef delay
#endif

#define delay qemu_delay
#define QEMU_DELAY_ADDR 0x40800000

void qemu_delay(uint32_t time_ms) {
	volatile uint32_t *ptr = (volatile uint32_t *)QEMU_DELAY_ADDR;
	*ptr = time_ms;
}

void setup() {
	pinMode(5, OUTPUT);
}

// void fixed_delay() {
// 	for (int i = 0; i < (1 << 30); i++) {
// 		asm volatile ("nop" : : : "memory");
// 	}
// }

void loop() {
	digitalWrite(5, 0);
	delay(500);
	digitalWrite(5, 1);
	delay(500);
}
