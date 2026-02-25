#include <NimBLEDevice.h>     // Librería BLE con soporte de seguridad + PIN
#include <BleKeyboard.h>      // Versión BLE Keyboard compatible con NimBLE

/**************************************************
 * CONFIGURACIONES AJUSTABLES POR EL USUARIO
 **************************************************/
String TEXTO_A_ENVIAR = "Hola mundo soy un @ ESP32";  
const uint32_t PIN_BLUETOOTH = 175175;               // PIN numérico de 6 dígitos

const int BUTTON_PIN = 14; // Para ESP32‑S3 Zero, usa 14 (seguro y libre)
/**************************************************/

BleKeyboard bleKeyboard("Teclado Blue", "ESP32-S3", 100);

bool lastState = HIGH;
unsigned long lastChange = 0;
const unsigned long debounceMs = 30;
bool sentOnThisPress = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);

  // ---------- CONFIGURAR SEGURIDAD BLE ----------
  NimBLEDevice::init("Teclado Blue");
  
  NimBLEDevice::setSecurityAuth(true, true, true);  
  // bonding = true, MITM = true, secure connections = true
  
  NimBLEDevice::setSecurityIOCap(BLE_HS_IO_DISPLAY_ONLY);
  // El PC introduce el PIN
  
  NimBLEDevice::setSecurityPasskey(PIN_BLUETOOTH);

  // ---------- INICIAR EL TECLADO BLE ----------
  bleKeyboard.begin();
  Serial.println("BLE HID Teclado iniciado con PIN 175175.");
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastState) {
    lastChange = millis();
    lastState = reading;
  }

  if (millis() - lastChange > debounceMs) {
    if (bleKeyboard.isConnected()) {

      if (reading == LOW && !sentOnThisPress) {
        bleKeyboard.print(TEXTO_A_ENVIAR);
        sentOnThisPress = true;
        Serial.println("Texto enviado por BLE HID.");
      } 
      else if (reading == HIGH) {
        sentOnThisPress = false;
      }

    }
  }

  delay(5);
}
