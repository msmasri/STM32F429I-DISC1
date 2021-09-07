
/* Private variables */
typedef enum {GREEN,RED}LED;

/**
 * @brief   Init LEDs
 * @note
 * @param   LED enum type
 * @retval  Init_LED
 */
void Init_LED(LED led);

/**
 * @brief   TurnON LEDs
 * @note
 * @param   LED enum type
 * @retval  Set_LED
 */
void Set_LED(LED led);

/**
 * @brief   TurnOFF LEDs
 * @note
 * @param   LED enum type
 * @retval  Set_LED
 */
void Reset_LED(LED led);
