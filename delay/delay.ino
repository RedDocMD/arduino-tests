int delay_amt;

void setup() {
	delay_amt = 0;
}

void loop() {
	delay(delay_amt);
	++delay_amt;
}
