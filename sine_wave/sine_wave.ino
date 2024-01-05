#ifdef delay
#undef delay
#endif

#define delay qemu_delay
#define QEMU_DELAY_ADDR 0x40800000

void qemu_delay(uint32_t time_ms) {
	volatile uint32_t *ptr = (volatile uint32_t *)QEMU_DELAY_ADDR;
	*ptr = time_ms;
}

const int outPin = 5;
const int stepDelay = 50;
const int halfPeriodStepCnt = 10;
const int resolution = 1 << 8;
int stepCnt;

#define PI 3.1415926535897932384626433832795

void setup() {
    stepCnt = 0;
}

void loop() {
    float angle = (stepCnt / (float)halfPeriodStepCnt) * PI;
    float value = 1 + sin(angle);
    int analogValue = (value / 2) * resolution;
    analogWrite(outPin, analogValue);

    stepCnt += 1;
    delay(outPin);
}
