#include <Wire.h>  // Library for I2C communication
#include <LiquidCrystal_I2C.h>  // Library for I2C LCD
#include <DHT.h>  // Library for DHT sensor
#include <SoftwareSerial.h>  // Library for SoftwareSerial communication

#define DHTPIN 6  // Pin for DHT sensor
#define DHTTYPE DHT11  // Type of DHT sensor
#define LDR_SENSOR A0  // Analog pin for LDR sensor
#define PULSE_SENSOR A1 // Analog pin for pulse sensor

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor

// Setup for I2C LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change 0x27 to your I2C address if it's different

// Communication
#define BLUETOOTH_RX 0  // Define the RX pin of the Bluetooth module
#define BLUETOOTH_TX 1  // Define the TX pin of the Bluetooth module

SoftwareSerial bluetoothSerial(BLUETOOTH_RX, BLUETOOTH_TX);  // Define SoftwareSerial object for Bluetooth

void setup() {
    Serial.begin(9600);  // Start serial communication for debugging
    bluetoothSerial.begin(9600);  // Start Bluetooth serial communication
    // Test Bluetooth communication
    bluetoothSerial.println("Hello, Bluetooth!");
    dht.begin();  // Start DHT sensor
    lcd.begin(16,2);
    lcd.init();
    lcd.backlight();
}

void loop() {
    static unsigned long lastDisplayTime = 0; // Initialize a variable to store the time of the last display
    static int displayState = 0; // Variable to track the current display state
    static bool showMessage = false; // Flag to indicate whether to display the message
    const unsigned long displayDuration = 3000; // Duration to display each sensor value (3 seconds)
    const unsigned long messageDuration = 2000; // Duration to display the message (2 seconds)

    // Read temperature and humidity
    float temperature = dht.readTemperature();  // Read temperature from DHT sensor
    float humidity = dht.readHumidity();  // Read humidity from DHT sensor

    // Check for NaN or error readings
    if (isnan(temperature) || isnan(humidity)) {
        // Display error message on LCD
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Error: Sensor");
        Serial.println("Error: Sensor");

        // Wait for a while to ensure the error message is displayed
        delay(messageDuration);
        return; // Exit loop early to avoid further processing
    }

    // Read LDR sensor value
    int ldrValue = analogRead(LDR_SENSOR);

    // Read pulse sensor value
     int pulseValue = analogRead(PULSE_SENSOR);

    unsigned long currentTime = millis();
    if (currentTime - lastDisplayTime >= displayDuration) {
        displayState = (displayState + 1) % 3; // Cycle through display states (0, 1, 2)
        lastDisplayTime = currentTime; // Update the last display time

        lcd.clear(); // Clear LCD screen
        lcd.setCursor(0, 0); // Set cursor to the first line
        switch (displayState) {
            case 1: // Display temperature
                lcd.print("Temp: ");
                lcd.print(temperature);
                lcd.print((char)223);
                lcd.print("C");
                Serial.print("Temperature: ");
                Serial.print(temperature);
                Serial.println("°C");
                delay(3000);
                lcd.clear();
                if (temperature < 25) {
                    lcd.print("Pleasant weather");
                    lcd.setCursor(0, 1);
                    lcd.print("CHECK DEVICE!");
                    Serial.println("Pleasant weather today, you can carry out daily activities");
                } else if (temperature >= 25 && temperature < 30) {
                    lcd.print("Moderate weather");
                    lcd.setCursor(0, 1);
                    lcd.print("CHECK DEVICE!");
                    Serial.println("The weather is moderate, stay hydrated while working and try to put on sunscreen if you go outside during daytime");
                } else if (temperature >= 30 && temperature < 40) {
                    lcd.print("Hot weather");
                    lcd.setCursor(0, 1);
                    lcd.print("CHECK DEVICE!");
                    Serial.println("It is hot today, ensure you have enough hydration and stay under shade,ensure that you use sunscreen");
                } else {
                    lcd.print("Extremely hot");
                    lcd.setCursor(0, 1);
                    lcd.print("CHECK DEVICE!");
                    Serial.println("Extremely hot today, please stay indoors and in cooler areas, if you travel ensure to be covered properly and use sunscreen");
                }
                delay(messageDuration); // Display message for specified duration
    lcd.clear();
    lcd.print("MEASURING PULSE ");
    Serial.println("MEASURING PULSE");
    delay(5000);
    lcd.clear();
    lcd.print("PULSE IS: ");
    lcd.print(pulseValue/5);
    lcd.print("BPM");
    Serial.print("YOUR PULSE IS: ");
    Serial.print(pulseValue/5);
    Serial.print("BPM");
    delay(3000);
    if (pulseValue/5 > 140) {
        // Display high chance of heatstroke message
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("CHANCE OF");
        lcd.setCursor(0, 1);
        lcd.print("HEATSTROKE");
        Serial.println("PLEASE CONSULT A DOCTOR");
        delay(3000);
    } else {
        // Display you are fine message
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.println("YOU ARE FINE.....");
        Serial.println("\nYOU ARE FINE....");
        delay(3000);
    }
                break;
            case 2: // Display humidity
                lcd.print("Humidity: ");
                lcd.print(humidity);
                lcd.print("%");
                Serial.print("Humidity: ");
                Serial.print(humidity);
                Serial.print("%");
                delay(3000);
                lcd.clear();
                if (humidity > 70) {
                    lcd.print("HIGH HUMIDITY");
                    lcd.setCursor(0, 1);
                    lcd.print("SWEATY DAY");
                    Serial.println("\nPlease carry an umbrella, It will also be a day of high perspiration");
                } else {
                    lcd.print("AVG HUMIDITY");
                    lcd.setCursor(0, 1);
                    lcd.print("GOOD DAY TODAY");
                    Serial.println("\nIt will be a pleasant day");
                }
                delay(3000);
                break;

              default: // Display LDR value
                lcd.print("LDR: ");
                lcd.print(ldrValue);
                Serial.print("\nLDR: ");
                Serial.println(ldrValue);
                delay(3000);
                lcd.clear();
                if (ldrValue > 1010) {
                    Serial.println("IT MAYBE NIGHT OR LOW SUNLIGHT");
                        lcd.print("Carry Umbrella");
                        lcd.setCursor(0, 1);
                        lcd.print("Sunny day");
                    // Turn on LED for night
                    // digitalWrite(LED_PIN, HIGH);
                } 
                    if (ldrValue<700) {
                        Serial.println("Please carry an umbrella");
                        lcd.print("Carry Umbrella");
                        lcd.setCursor(0, 1);
                        lcd.print("Sunny day");
                    }
                    if (ldrValue>=700 && ldrValue < 1010) {
                        Serial.println("Please carry an umbrella");
                        lcd.print("Carry Umbrella");
                        lcd.setCursor(0, 1);
                        lcd.print("Sunny day");
                    }
                
                delay(3000);
                lcd.clear();
                lcd.print("CHECK DEVICE!!!");

                // Water intake recommendation
                Serial.println("Please enter your body weight in kilograms:");
                while (!Serial.available()) {
                    // Wait for user input
                }
                float bodyWeight = Serial.parseFloat(); // Read user input as float
                float recommendedWaterIntake = bodyWeight * 0.035; // Convert ml to liters

                // Display recommendation on Serial Monitor
                Serial.print("Recommended water intake: ");
                Serial.print(recommendedWaterIntake);
                Serial.println(" L");

                lcd.clear();
                lcd.print("Please Drink:");
                lcd.setCursor(0, 1);
                lcd.print(recommendedWaterIntake);
                lcd.println(" L of water ");
                delay(3000);
                while (Serial.available()) {
                    bluetoothSerial.write(Serial.read());
                }
                Serial.print("\n");
                Serial.print("NEXT CYCLE STARTS..");
                Serial.print("\n");

                break;
        }
    }
    delay(1000);  // Delay to prevent flickering and for overall timing
}