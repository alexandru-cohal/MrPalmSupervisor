#include <DHT.h>

#define ENABLE_UART           true
#define UART_BAUD_RATE        9600
#define UART_DELAY_INIT_MS    500

#define TEMP_HUMID_SENS_PIN   2
#define TEMP_HUMID_SENS_TYPE  DHT11

#define LOOP_DELAY_MS         5000

/**
 * Temperature and humidity sensor object
 */
DHT TempHumidSens(TEMP_HUMID_SENS_PIN, TEMP_HUMID_SENS_TYPE);

#if (ENABLE_UART == true)
/** 
 * Initializes the UART.
 *
 * @param None
 *
 * @return The result of UART initialization.
 */
bool Serial_Init(void)
{
  bool RetVal = true;

  Serial.begin(UART_BAUD_RATE);

  // Wait until the serial connection is open
  while (!Serial); 
  delay(UART_DELAY_INIT_MS);

  return RetVal;
}
#endif

/** 
 * Reads the temperature (°C) and humidity (%) sensor values and calculates the apparent temperature value (°C).
 *
 * @param None
 *
 * @return The result of temperature and humidity sensor reading.
 */
bool TempHumidSens_Read(float *Temp, float *Humid, float *ApparentTemp)
{
  bool RetVal = true;

  *Humid = TempHumidSens.readHumidity();
  *Temp = TempHumidSens.readTemperature(); 
  *ApparentTemp = TempHumidSens.computeHeatIndex(*Temp, *Humid, false);

  if (isnan(*Temp) || isnan(*Humid)) 
  {
    RetVal = false;
  }

  return RetVal;
}

void setup() 
{
  bool RetVal = true; 

  // Initialize UART
#if (ENABLE_UART == true)
  RetVal = Serial_Init();
#endif 

#if (ENABLE_UART == true)
  Serial.println("Start of setup");
#endif

  // Initialize temperature and humidity sensor
  TempHumidSens.begin();

  // End of initializations
#if (ENABLE_UART == true)
  if (RetVal == true)
  {
    Serial.println("End of setup. Result: OK");
  }
  else
  {
    Serial.println("End of setup. Result: FAIL");
  }
#endif
}

void loop() 
{
  bool RetVal = true;

  // Read temperature and humidity sensor values and calculates apparent temperature value
  float Temp = 0;
  float Humid = 0;
  float ApparentTemp = 0;

  RetVal = TempHumidSens_Read(&Temp, &Humid, &ApparentTemp);

  if (RetVal == true)
  {
#if (ENABLE_UART == true)
    Serial.print("Humidity: ");
    Serial.print(Humid);
    Serial.print("%  Temperature: ");
    Serial.print(Temp);
    Serial.print("°C  Apparent Temperature: ");
    Serial.print(ApparentTemp);
    Serial.print(F("°C "));
    Serial.println();
#endif
  } 
  else
  {
#if (ENABLE_UART == true)
    Serial.println("Failed to read from temperature and humidity sensor!");
#endif
  }

  delay(LOOP_DELAY_MS);
}
