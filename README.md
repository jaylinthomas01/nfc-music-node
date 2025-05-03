# NFC Music Node 🎶🔍

Trigger Spotify playlists using NFC tags, an ESP32, and a PN532 reader—because buttons are boring.

## ✨ What It Does

- Tap an NFC tag to instantly play a Spotify playlist on your Google Home speaker
- Auto-logs unknown NFC tags to help you easily add new ones
- Designed to be offline and local-first—no cloud nonsense or data leaks

## 🧠 Why I Built This

I wanted my home to respond like a scene change: walk in, tap something, and the vibe flips. This project lets me trigger music with physical tags—something about that blend of digital + tactile just *feels* right.

It also gave me a way to explore ESP32 programming, smart speaker control, and NFC tech—without relying on janky apps or subscriptions.

## 🛠 Tech Stack

- **ESP32-WROOM** microcontroller  
- **PN532** NFC module (I2C mode)  
- **Arduino IDE** (for flashing)  
- **Google Home** speaker (linked to Spotify)  
- **ESPHome** *(optional if you go YAML instead of C++)*

## 🧩 Features

- 🎵 Instant playlist triggering via NFC tag UID
- 🧠 Smart fallback: unknown tags get logged for easy assignment
- ⚡ Fast boot time, local control, no Wi-Fi streaming delays
- 🧘 Built for home vibes, party shifts, and subtle flexes

## 📸 Demo

![Demo GIF placeholder]

_Imagine tapping a coaster and the room turns into a lo-fi lounge._

## 🧪 How To Use

1. Wire your ESP32 to the PN532 (see diagram below)
2. Open `code/main.ino` in Arduino IDE
3. Flash to your ESP32
4. Tap a tag, watch the UID appear in Serial Monitor
5. Add that UID to your playlist map
6. Done. You’re a DJ now.

---

## 🧰 Wiring Diagram

| PN532 Pin | ESP32 Pin |
|-----------|-----------|
| VCC       | 3.3V      |
| GND       | GND       |
| SDA       | D21 (GPIO 21) |
| SCL       | D22 (GPIO 22) |

> ⚠️ Note: On the ESP32 board I used, the pins are labeled `D21` and `D22`.  
> 📌 Also, my PN532 reader came with a sticker covering the DIP switch. You'll need to peel it off and flip the switches to I2C mode (usually both switches ON or OFF, depending on your board).


> 📌 I’m using I2C mode. If you’re using UART/SPI, wiring will differ.

---

## 🧾 Playlist Map Snippet

```cpp
std::map<String, String> playlistMap = {
  {"04A22418B26B80", "https://open.spotify.com/playlist/123abc"},
  {"047FEF88327C81", "https://open.spotify.com/playlist/456def"}
};
