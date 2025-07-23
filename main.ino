#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t RECV_PIN = 23;  // TSOP1738 OUT to GPIO23
const int LED_PIN = 2;         // Built-in LED or external

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println("IR Receiver Ready. Waiting for input...");
}

void loop() {
  if (irrecv.decode(&results)) {
    uint32_t code = results.value;
    Serial.print("Received Code: 0x");
    Serial.println(code, HEX);

    // Replace with your own remote codes
    if (code == 0xFFA25D) {         // POWER button (example)
      digitalWrite(LED_PIN, 0);  // LED ON
      Serial.println("LED ON");
    }
    else if (code == 0xFF629D) {    // VOL+ button (example)
      digitalWrite(LED_PIN, 1);   // LED OFF
      Serial.println("LED OFF");
    }

    irrecv.resume();  // Receive next
  }
}