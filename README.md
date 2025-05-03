# NFC Music Node 🎶🔍

A DIY ESP32-based NFC trigger that launches specific Spotify playlists or songs when tagged. Built with ESPHome, PN532, and NFC tags. Designed to work with Google Home and Home Assistant.

## 💡 Project Goals
- Tap an NFC tag to launch a Spotify playlist or song.
- Sync with Google Home speaker.
- Modular config to support multiple tags (tested with Ultralight & Classic).

## 🛠 What You’ll Need
- ESP32 dev board
- PN532 module (I2C)
- NFC tags (Ultralight/Classic)
- Jumper wires / breadboard / solder kit (optional)
- Home Assistant w/ Spotify + media integrations


## 🔌 Setup Instructions
See the `software/` folder for the YAML config. Use `nfc_music_node.yaml` in ESPHome.

## 🎶 Tags In Use
See `hardware/tag_uids.txt` for all scanned tags and their assigned functions.

## 📖 Logs + Progress
Detailed log dumps in `/logs` and project notes in `reference/`.

---

This was my first ESP project — powered by way too much trial-and-error.
