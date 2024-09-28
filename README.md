
---



$$\Huge \textcolor{red}{\text{ESP8266 OTA (Over-the-Air) Code Upload}}$$

---


## Overview

This project enables **wireless code updates** to an ESP8266 microcontroller using **Over-the-Air (OTA)** functionality. Once the initial setup is complete, you can upload code to the ESP8266 wirelessly without needing to physically connect it via USB, making development and updates more convenient.

## Features

- **OTA Updates**: Upload new firmware to the ESP8266 wirelessly after it is connected to a Wi-Fi network.
- **Wi-Fi Connectivity**: Automatically connects to a specified Wi-Fi network for enabling OTA functionality.
- **No Physical Connection Required**: After the first upload via USB, all future updates can be performed over the air.

## Requirements

### Hardware
- ESP8266 microcontroller (e.g., NodeMCU, Wemos D1 Mini)
- USB cable (for the initial code upload)

### Software
- Arduino IDE with ESP8266 board support installed
- Wi-Fi credentials (SSID and password)
- Optional: OTA password for securing wireless updates

### Libraries
- `ESP8266WiFi.h`: For handling Wi-Fi connections
- `ArduinoOTA.h`: For managing OTA functionality

## How to Use

1. **Initial Setup**:
   - Connect the ESP8266 to your computer via USB.
   - In the Arduino IDE, upload the provided code, which contains Wi-Fi credentials and OTA setup.
   - This initial upload configures the ESP8266 for OTA updates.

2. **Connect to Wi-Fi**:
   - Upon startup, the ESP8266 will attempt to connect to the specified Wi-Fi network. You can monitor the connection status via the Serial Monitor.
   
3. **Perform OTA Updates**:
   - Once connected to Wi-Fi, the OTA port will appear in the Arduino IDE under **Tools > Port**.
   - Select the OTA port and upload new sketches wirelessly.
   - If a password was set in the code, you’ll be prompted to enter it before the upload starts.

4. **Subsequent Updates**:
   - After the initial configuration, future firmware updates can be uploaded over the air without reconnecting the ESP8266 via USB.
   - Simply connect your computer to the same Wi-Fi network as the ESP8266, select the OTA port in the Arduino IDE, and upload the new code.

## OTA Updates

- **What is OTA?**: OTA (Over-the-Air) updates allow you to wirelessly upload new firmware or sketches to your ESP8266 once it is connected to a Wi-Fi network.
- **Benefits**: This method eliminates the need for physical access to the ESP8266 after the initial USB upload, saving time and effort when making updates or changes.
- **Security**: You can set an OTA password to secure your updates and prevent unauthorized users from uploading firmware to your ESP8266.
  
## License

This project is open-source. Feel free to use, modify, and distribute the code as per the project’s license.
