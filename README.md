# Fanatic

Fanatic is a automatic fan speed based on temperature & humidity. It detect temperature changes and updates the fan speed accordingly while maintaining a minimum threshold.

# Requirements

- Nodemcu
- L298N Motor Driver
- DHT22 Sensor
- DC Motor
- Breadboard
- Connecting wires

# Software prerequisites

Clone this repository
```
git clone <repo>
```

<br>

Install arduino_cli
```
brew install arduino_cli
```

and follow the instruction mentions in this [blog](https://ericslenk.com/posts/getting-started-with-the-nodemcu-esp8266-and-arduino-cli).

<br>

Install DHTesp.h
```
arduino-cli lib install "DHT sensor library for ESPx"
```

# Compile and Upload

To compile the project,
```
arduino-cli compile --fqbn esp8266:esp8266:nodemcuv2 fanatic.ino
```

<br>

Now, connect the nodemcu to your computer and connect other components in the breadboard as shown in the [Circuit Diagram](./Circuit%20Diagram.pdf)

<br>

To upload the project,
```
arduino-cli upload --port <your-port> --fqbn esp8266:esp8266:nodemcuv2 fanatic.ino
```

For more details, check out the [blog](https://ericslenk.com/posts/getting-started-with-the-nodemcu-esp8266-and-arduino-cli).