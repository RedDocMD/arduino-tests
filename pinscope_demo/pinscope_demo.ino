#define NO_USB
#define Serial _UART1_

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
const int sawPin = 6;
const int digPin = 14;
const int stepDelay = 100;
const int halfPeriodStepCnt = 10;
const int resolution = 1 << 8;
int stepCnt, sawStepCnt;
int digVal;

#define PI 3.1415926535897932384626433832795

void setup() {
    Serial.begin(9600);
    stepCnt = 0;
    digVal = 0;
    sawStepCnt = 0;
    pinMode(digPin, OUTPUT);
}

void loop() {
    float angle = (stepCnt / (float)halfPeriodStepCnt) * PI;
    float value = 1 + sin(angle);
    int analogValue = (value / 2) * resolution;
    if (analogValue > resolution - 1)
	analogValue = resolution - 1;
    analogWrite(outPin, analogValue);
    Serial.println(analogValue);

    float sawFrac = sawStepCnt / (float)halfPeriodStepCnt;
    int sawVal = sawFrac * resolution;
    if (sawVal >= resolution)
	sawVal = resolution - 1;
    analogWrite(sawPin, sawVal);

    if (stepCnt % halfPeriodStepCnt == halfPeriodStepCnt / 2) {
	digVal = !digVal;
	digitalWrite(digPin, digVal);
    } else if (stepCnt % halfPeriodStepCnt == 0) {
	digVal = !digVal;
	digitalWrite(digPin, digVal);
    }

    stepCnt += 1;
    if (sawStepCnt == halfPeriodStepCnt)
	sawStepCnt = 0;
    else
	sawStepCnt += 1;
    delay(stepDelay);
}
