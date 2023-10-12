#define NO_USB
#define Serial _UART1_

int i;

void setup() {
	Serial.begin(9600);
	i = 0;
}

void loop() {
	Serial.print("Hello: ");
	Serial.print(i);
	Serial.println();
	delay(500);
	i++;
	i %= 256;
}
