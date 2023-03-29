#include "DHTesp.h"

#define LOW_BOUND 21.66
#define UPPER_BOUND 36.66

DHTesp dht;

#define ENA 4
#define IN1 0
#define IN2 2

int currentSpeed = 0;

void setup()
{
    dht.setup(5, DHTesp::DHT22);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    analogWriteRange(255);
    updateSpeed(128);

    Serial.begin(9600);
    Serial.println("Motor Started");
}

void loop()
{
    checkTemperature();
    delay(1000);
}

void checkTemperature()
{
    if (dht.getStatusString() == "OK")
    {
        float temperature = constrain(dht.getTemperature(), LOW_BOUND, UPPER_BOUND);
        int speed = 128 + map(temperature, LOW_BOUND, UPPER_BOUND, 0, 127);

        Serial.print("Temperature: ");
        Serial.print(temperature, 1);
        Serial.print(" °C\t\t Fan speed: ");
        Serial.print(speed / 255 * 100);
        Serial.println("%");

        updateSpeed(speed);
    }
}

void updateSpeed(int speed)
{
    if (currentSpeed != speed)
    {
        currentSpeed = speed;
        analogWrite(ENA, currentSpeed);
    }
}
