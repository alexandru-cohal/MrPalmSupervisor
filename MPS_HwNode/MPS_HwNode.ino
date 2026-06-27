#define ENABLE_UART           true
#define UART_BAUD_RATE        9600
#define UART_DELAY_INIT_MS    500

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

void setup() 
{
  bool RetVal = true; 
#if (ENABLE_UART == true)
  RetVal = Serial_Init();
#endif 

#if (ENABLE_UART == true)
  Serial.println("Start of setup");
#endif

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
}
