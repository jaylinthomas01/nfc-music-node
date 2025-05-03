#include <Wire.h>
#include <Adafruit_PN532.h>
#include <WiFi.h>

// Define I2C pins
#define SDA_PIN 21
#define SCL_PIN 22

// Initialize PN532 using I2C
Adafruit_PN532 nfc(SDA_PIN, SCL_PIN);

// Playlist map (tag UID → Spotify link)
std::map<String, String> playlistMap = {
  {"04A22418B26B80", "https://open.spotify.com/playlist/123abc"},
  {"047FEF88327C81", "https://open.spotify.com/playlist/456def"}
};

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("Booting NFC Music Node...");
  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.println("Didn't find PN532 board");
    while (1); // halt
  }

  // Configure board to read RFID tags
  nfc.SAMConfig();
  Serial.println("NFC ready. Tap a tag...");
}

void loop() {
  uint8_t uid[7];  // Buffer to store UID
  uint8_t uidLength;

  if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength)) {
    // Convert UID to hex string
    String tagUID = "";
    for (uint8_t i = 0; i < uidLength; i++) {
      if (uid[i] < 0x10) tagUID += "0";
      tagUID += String(uid[i], HEX);
    }
    tagUID.toUpperCase();

    Serial.print("Tag detected: ");
    Serial.println(tagUID);

    // Check against playlist map
    if (playlistMap.count(tagUID)) {
      String link = playlistMap[tagUID];
      Serial.println("🎵 Matched playlist:");
      Serial.println(link);

      // Optional: trigger link via serial → something like Node-RED or another handler can use this
    } else {
      Serial.println("❌ Unknown tag. Add this UID to your map:");
      Serial.println(tagUID);
    }

    delay(2000); // Debounce
  }
}
