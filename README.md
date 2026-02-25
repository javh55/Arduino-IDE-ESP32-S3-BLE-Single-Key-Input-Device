Descripción para GitHub (README intro)
Descripción general
Este proyecto implementa un teclado Bluetooth BLE (HID) basado en un ESP32‑S3, capaz de enviar un texto predefinido al sistema host al presionar un botón físico.
El ESP32 se anuncia como un dispositivo BLE con el nombre “Teclado Blue” y utiliza un PIN numérico de emparejamiento para mayor seguridad.
El objetivo es proporcionar un macro‑botón inalámbrico, simple y confiable, compatible con Windows, macOS, Linux, Android y otros sistemas con soporte HID BLE.

Características principales

✔ Emulación completa de Teclado BLE HID.

✔ Envío de texto predefinido mediante un botón físico con pull‑up interno.

✔ PIN de emparejamiento configurado (seguridad BLE).

✔ Nombre del dispositivo visible: “Teclado Blue”.

✔ Compatible con placas ESP32‑S3 Zero.

✔ Código claro, modular y configurable desde la cabecera.

✔ Funciona como macro‑pad, atajo rápido o automatización inalámbrica.



Hardware utilizado

ESP32‑S3 Zero
Pulsador momentáneo
Conexión simple: GPIO14 → Botón → GND


📌 Conexión física del botón

BOTÓN

└──> GPIO 14 (BUTTON_PIN)  
└───────────> GND


Usamos INPUT_PULLUP, así que:

Estado normal: ALTO (HIGH)
Pulsado a GND: BAJO (LOW)



Aplicaciones:

Automatizar comandos repetitivos
Sistemas de accesibilidad
Enviar mensajes predeterminados
Activar funciones rápidas sin cables
Demostraciones educativas de BLE HID
Botones macro para software (OBS, Notepad, browsers, etc.)

Librerias:
https://github.com/h2zero/NimBLE-Arduino
https://github.com/h2zero/NimBLE-Arduino


Estado del proyecto:
Versión inicial funcional y estable.
Se pueden agregar más botones, combinaciones de teclas, modos de energía y perfiles BLE adicionales.
