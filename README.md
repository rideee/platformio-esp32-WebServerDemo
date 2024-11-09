# ESP32 Web Server

This project demonstrates how to create a web server using the ESP32 microcontroller. The web server allows you to control and monitor various aspects of the ESP32 through a web interface.

## Features

- Serve web pages to control ESP32 GPIOs
- Monitor sensor data in real-time
- Simple and intuitive web interface

## Requirements

- ESP32 development board
- PlatformIO IDE
- Basic knowledge of HTML, CSS, and JavaScript

## Installation

1. Clone this repository:
    ```sh
    git clone https://github.com/yourusername/esp32-WebServer.git
    ```
2. Open the project in PlatformIO IDE.
3. Connect your ESP32 board to your computer.
4. Upload the code to the ESP32:
    ```sh
    pio run --target upload
    ```
5. Upload the files from the `data` folder to the ESP32 SPIFFS:
    ```sh
    pio run --target uploadfs
    ```

## Usage

1. After uploading the code, open the Serial Monitor to find the IP address of the ESP32.
2. Open a web browser and enter the IP address to access the web server.
3. Use the web interface to control GPIOs and monitor sensor data.

## License

This project is licensed under the MIT License. 

## Acknowledgements

- [PlatformIO](https://platformio.org/)
- [ESP32](https://www.espressif.com/en/products/socs/esp32)

