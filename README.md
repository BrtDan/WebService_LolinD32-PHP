# WebService_LolinD32-PHP - Progetto ESP32 (LolinD32) e BME280

Questo progetto utilizza un ESP32 e un sensore BME280 per rilevare la temperatura e l'umidità, e invia i dati a un server PHP tramite una richiesta HTTP.

## Requisiti

- ESP32 (LolinD32)
- Sensore BME280
- Server PHP

## Installazione

1. Carica il codice `lolind32.ino` sul tuo ESP32 utilizzando l'IDE Arduino.
2. Assicurati che il tuo ESP32 sia connesso alla stessa rete del tuo server PHP.
3. Modifica le variabili `ssid`, `password` e `serverAddress` nel codice per corrispondere alla tua configurazione di rete e al tuo server.

## Utilizzo

Premi il bottone collegato al tuo ESP32 per inviare i dati di temperatura e umidità al server PHP.