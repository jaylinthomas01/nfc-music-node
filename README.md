# NFC Music Node 🎶🔍

Trigger Spotify playlists using NFC tags, an ESP32, and a PN532 reader—because buttons are boring.

## ✨ What It Does

- Tap an NFC tag to instantly play a Spotify playlist via Google Home
- Auto-logs unknown NFC tags for easy configuration
- Designed for local offline logic with minimal dependencies

## 🧠 Why I Built This

I wanted to make my smart home a little smarter. Inspired by the idea of walking into a room and tapping a tag to change the vibe, this project lets me control music with simple objects.



## 🛠 Tech Stack

- **ESP32** microcontroller
- **PN532** NFC reader
- **ESPHome** (or Arduino/C++)
- **Google Home** speaker (connected via Spotify)
- Optional: **Home Assistant** for deeper automation

## 🧩 Features

- 🎵 Plays different playlists based on tag UID
- 📓 Logs unknown tags to serial monitor or file
- 🗃 Configurable YAML/JSON playlist map
- 🔒 Locally controlled—no sketchy cloud stuff

## 📸 Demo

*(Insert short GIF or photo of tag triggering playlist)*

## 🧪 How To Use

1. Flash the ESP32 with the code inside `code/`
2. Connect the PN532 to the ESP32 (see wiring diagram)
3. Power it up and open serial monitor
4. Tap a tag → get a log of the UID
5. Add that UID to your `playlist_map` config
6. Enjoy instant vibes™

## 🧾 Example Playlist Config (pseudo-code)

```cpp
std::map<String, String> playlistMap = {
  {"04A22418B26B80", "https://open.spotify.com/playlist/123abc"},
  {"047FEF88327C81", "https://open.spotify.com/playlist/456def"}
};
