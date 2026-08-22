#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <INA226_WE.h>
#include <avr/wdt.h>

// ADDRESSES
const uint8_t I2C_LCD_ADDRESS = 0x3B;
const uint8_t INA226_ADDRESS = 0x40;

// DEFINITIONS
const uint8_t LED_RED_PIN = 8;   // PB0
const uint8_t LED_GREEN_PIN = 9; // PB1
const uint8_t LED_BLUE_PIN = 10; // PB2
LiquidCrystal_I2C lcd(I2C_LCD_ADDRESS, 16, 2);
INA226_WE ina226 = INA226_WE(INA226_ADDRESS);
// Stby function
unsigned long lastValidReadTime = 0;
const unsigned long STANDBY_TIMEOUT_MS = 30000; //
bool isStandby = false;

void setup()
{
    wdt_disable();
    Serial.begin(115200);
    Wire.begin();
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
    pinMode(LED_BLUE_PIN, OUTPUT);
    digitalWrite(LED_GREEN_PIN, LOW);
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_BLUE_PIN, LOW);

    // FAILSAFE Check LCD
    Wire.beginTransmission(I2C_LCD_ADDRESS);
    if (Wire.endTransmission() != 0)
    {
        Serial.println(F("ERROR: LCD (PCF8574AT) not found."));
        digitalWrite(LED_RED_PIN, HIGH);
        while (1);
    }

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print(F("System Boot"));

    // FAILSAFE 2: Check INA226
    if (!ina226.init())
    {
        Serial.println(F("ERROR: INA226 not found."));
        lcd.setCursor(0, 1);
        digitalWrite(LED_RED_PIN, HIGH);
        while (1);
    }
//shunt resistor
    ina226.setResistorRange(0.02, 3.2);
    ina226.waitUntilConversionCompleted();
    lcd.clear();
    lastValidReadTime = millis();
    wdt_enable(WDTO_2S); // Watchdog
}

void loop()
{
    wdt_reset();
    //Calculations
    float busVoltage_V = ina226.getBusVoltage_V();
    float current_A = ina226.getCurrent_mA() / 1000.0;
    bool validMeasurement = (busVoltage_V > 0.5);

    if (validMeasurement)
    {
        lastValidReadTime = millis();

        if (isStandby)
        {
            isStandby = false;
            lcd.backlight();
            lcd.clear();
        }
        // FAILSAFE Shuts down INA226
        if (busVoltage_V >= 36.0 && current_A > 3.5)
        {
            ina226.powerDown();
            digitalWrite(LED_RED_PIN, HIGH);
            digitalWrite(LED_GREEN_PIN, LOW);
            digitalWrite(LED_BLUE_PIN, LOW);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(F("OVERLOAD"));
            lcd.setCursor(0, 1);
            lcd.print(F("SENSOR SHUTDOWN"));
            Serial.println(F("Over-Range. Sensor powered down."));

            // Blocks system 
            while (1)
            {
                wdt_reset(); // watchdog 
            }
        }
        else
        {
            // STAT_OK
            digitalWrite(LED_RED_PIN, LOW);
            digitalWrite(LED_GREEN_PIN, HIGH);
            digitalWrite(LED_BLUE_PIN, LOW);
        }
        // LCD
        lcd.setCursor(0, 0);
        lcd.print(F("V: "));
        lcd.print(busVoltage_V, 2);
        lcd.print(F("V       "));
        lcd.setCursor(0, 1);
        lcd.print(F("I: "));
        lcd.print(current_A * 1000.0, 1);
        lcd.print(F("mA      "));
    }
    else
    {
        // STANDBY (this should work, but i'm not sure lol)
        if (millis() - lastValidReadTime > STANDBY_TIMEOUT_MS)
        {
            if (!isStandby)
            {
                isStandby = true;
                lcd.noBacklight();
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print(F("Standby"));
                digitalWrite(LED_BLUE_PIN, HIGH);
                digitalWrite(LED_GREEN_PIN, LOW);
                digitalWrite(LED_RED_PIN, LOW);
            }
        }
    }

    delay(500);
}
// Made by oct-karim
// 19/08/2026    V1.2
