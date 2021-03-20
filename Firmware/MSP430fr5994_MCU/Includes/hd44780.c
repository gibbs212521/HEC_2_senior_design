#include "hd44780.h"


#ifdef HD44780_PARALLEL_MODE
  #ifdef HD44780_MIXED_PINS_MODE
    #ifdef HD44780_8BIT_MODE
      #ifdef HD44780_D0_INVERTED
        #define HD44780_D0_HIGH             HD44780_D0_MCU_OUT_PORT &= ~HD44780_D0_MCU_OUT_PIN
        #define HD44780_D0_LOW              HD44780_D0_MCU_OUT_PORT |=  HD44780_D0_MCU_OUT_PIN
      #else
        #define HD44780_D0_HIGH             HD44780_D0_MCU_OUT_PORT |=  HD44780_D0_MCU_OUT_PIN
        #define HD44780_D0_LOW              HD44780_D0_MCU_OUT_PORT &= ~HD44780_D0_MCU_OUT_PIN
      #endif
      #ifdef HD44780_D1_INVERTED
        #define HD44780_D1_HIGH             HD44780_D1_MCU_OUT_PORT &= ~HD44780_D1_MCU_OUT_PIN
        #define HD44780_D1_LOW              HD44780_D1_MCU_OUT_PORT |=  HD44780_D1_MCU_OUT_PIN
      #else
        #define HD44780_D1_HIGH             HD44780_D1_MCU_OUT_PORT |=  HD44780_D1_MCU_OUT_PIN
        #define HD44780_D1_LOW              HD44780_D1_MCU_OUT_PORT &= ~HD44780_D1_MCU_OUT_PIN
      #endif
      #ifdef HD44780_D2_INVERTED
        #define HD44780_D2_HIGH             HD44780_D2_MCU_OUT_PORT &= ~HD44780_D2_MCU_OUT_PIN
        #define HD44780_D2_LOW              HD44780_D2_MCU_OUT_PORT |=  HD44780_D2_MCU_OUT_PIN
      #else
        #define HD44780_D2_HIGH             HD44780_D2_MCU_OUT_PORT |=  HD44780_D2_MCU_OUT_PIN
        #define HD44780_D2_LOW              HD44780_D2_MCU_OUT_PORT &= ~HD44780_D2_MCU_OUT_PIN
      #endif
      #ifdef HD44780_D3_INVERTED
        #define HD44780_D3_HIGH             HD44780_DB3_MCU_OUT_PORT &= ~HD44780_DB3_MCU_OUT_PIN
        #define HD44780_D3_LOW              HD44780_DB3_MCU_OUT_PORT |=  HD44780_DB3_MCU_OUT_PIN
      #else
        #define HD44780_D3_HIGH             HD44780_D3_MCU_OUT_PORT |=  HD44780_D3_MCU_OUT_PIN
        #define HD44780_D3_LOW              HD44780_D3_MCU_OUT_PORT &= ~HD44780_D3_MCU_OUT_PIN
      #endif
    #endif
    #ifdef HD44780_D4_INVERTED
      #define HD44780_D4_HIGH               HD44780_D4_MCU_OUT_PORT &= ~HD44780_D4_MCU_OUT_PIN
      #define HD44780_D4_LOW                HD44780_D4_MCU_OUT_PORT |=  HD44780_D4_MCU_OUT_PIN
    #else
      #define HD44780_D4_HIGH               HD44780_D4_MCU_OUT_PORT |=  HD44780_D4_MCU_OUT_PIN
      #define HD44780_D4_LOW                HD44780_D4_MCU_OUT_PORT &= ~HD44780_D4_MCU_OUT_PIN
    #endif
    #ifdef HD44780_D5_INVERTED
      #define HD44780_D5_HIGH               HD44780_D5_MCU_OUT_PORT &= ~HD44780_D5_MCU_OUT_PIN
      #define HD44780_D5_LOW                HD44780_D5_MCU_OUT_PORT |=  HD44780_D5_MCU_OUT_PIN
    #else
      #define HD44780_D5_HIGH               HD44780_D5_MCU_OUT_PORT |=  HD44780_D5_MCU_OUT_PIN
      #define HD44780_D5_LOW                HD44780_D5_MCU_OUT_PORT &= ~HD44780_D5_MCU_OUT_PIN
    #endif
    #ifdef HD44780_D6_INVERTED
      #define HD44780_D6_HIGH               HD44780_D6_MCU_OUT_PORT &= ~HD44780_D6_MCU_OUT_PIN
      #define HD44780_D6_LOW                HD44780_D6_MCU_OUT_PORT |= HD44780_D6_MCU_OUT_PIN
    #else
      #define HD44780_D6_HIGH               HD44780_D6_MCU_OUT_PORT |=  HD44780_D6_MCU_OUT_PIN
      #define HD44780_D6_LOW                HD44780_D6_MCU_OUT_PORT &= ~HD44780_D6_MCU_OUT_PIN
    #endif
    #ifdef HD44780_D7_INVERTED
      #define HD44780_D7_HIGH               HD44780_D7_MCU_OUT_PORT &= ~HD44780_D7_MCU_OUT_PIN
      #define HD44780_D7_LOW                HD44780_D7_MCU_OUT_PORT |=  HD44780_D7_MCU_OUT_PIN
    #else
      #define HD44780_D7_HIGH               HD44780_D7_MCU_OUT_PORT |=  HD44780_D7_MCU_OUT_PIN
      #define HD44780_D7_LOW                HD44780_D7_MCU_OUT_PORT &= ~HD44780_D7_MCU_OUT_PIN
    #endif
  #endif
#else
  #ifdef HD44780_MIXED_PINS_MODE
    #ifdef HD44780_8BIT_MODE
      #ifdef HD44780_D0_INVERTED
        #define SET_BIT_HD44780_D0_HIGH     &= ~HD44780_D0_SR_PIN
        #define SET_BIT_HD44780_D0_LOW      |=  HD44780_D0_SR_PIN
      #else
        #define SET_BIT_HD44780_D0_HIGH     |=  HD44780_D0_SR_PIN
        #define SET_BIT_HD44780_D0_LOW      &= ~HD44780_D0_SR_PIN
      #endif
      #ifdef HD44780_D1_INVERTED
        #define SET_BIT_HD44780_D1_HIGH     &= ~HD44780_D1_SR_PIN
        #define SET_BIT_HD44780_D1_LOW      |=  HD44780_D1_SR_PIN
      #else
        #define SET_BIT_HD44780_D1_HIGH     |=  HD44780_D1_SR_PIN
        #define SET_BIT_HD44780_D1_LOW      &= ~HD44780_D1_SR_PIN
      #endif
      #ifdef HD44780_D2_INVERTED
        #define SET_BIT_HD44780_D2_HIGH     &= ~HD44780_D2_SR_PIN
        #define SET_BIT_HD44780_D2_LOW      |=  HD44780_D2_SR_PIN
      #else
        #define SET_BIT_HD44780_D2_HIGH     |=  HD44780_D2_SR_PIN
        #define SET_BIT_HD44780_D2_LOW      &= ~HD44780_D2_SR_PIN
      #endif
      #ifdef HD44780_D3_INVERTED
        #define SET_BIT_HD44780_D3_HIGH     &= ~HD44780_D3_SR_PIN
        #define SET_BIT_HD44780_D3_LOW      |=  HD44780_D3_SR_PIN
      #else
        #define SET_BIT_HD44780_D3_HIGH     |=  HD44780_D3_SR_PIN
        #define SET_BIT_HD44780_D3_LOW      &= ~HD44780_D3_SR_PIN
      #endif
    #endif
    #ifdef HD44780_D4_INVERTED
      #define SET_BIT_HD44780_D4_HIGH       &= ~HD44780_D4_SR_PIN
      #define SET_BIT_HD44780_D4_LOW        |=  HD44780_D4_SR_PIN
    #else
      #define SET_BIT_HD44780_D4_HIGH       |=  HD44780_D4_SR_PIN
      #define SET_BIT_HD44780_D4_LOW        &= ~HD44780_D4_SR_PIN
    #endif
    #ifdef HD44780_D5_INVERTED
      #define SET_BIT_HD44780_D5_HIGH       &= ~HD44780_D5_SR_PIN
      #define SET_BIT_HD44780_D5_LOW        |=  HD44780_D5_SR_PIN
    #else
      #define SET_BIT_HD44780_D5_HIGH       |=  HD44780_D5_SR_PIN
      #define SET_BIT_HD44780_D5_LOW        &= ~HD44780_D5_SR_PIN
    #endif
    #ifdef HD44780_D6_INVERTED
      #define SET_BIT_HD44780_D6_HIGH       &= ~HD44780_D6_SR_PIN
      #define SET_BIT_HD44780_D6_LOW        |=  HD44780_D6_SR_PIN
    #else
      #define SET_BIT_HD44780_D6_HIGH       |=  HD44780_D6_SR_PIN
      #define SET_BIT_HD44780_D6_LOW        &= ~HD44780_D6_SR_PIN
    #endif
    #ifdef HD44780_D7_INVERTED
      #define SET_BIT_HD44780_D7_HIGH       &= ~HD44780_D7_SR_PIN
      #define SET_BIT_HD44780_D7_LOW        |=  HD44780_D7_SR_PIN
    #else
      #define SET_BIT_HD44780_D7_HIGH       |=  HD44780_D7_SR_PIN
      #define SET_BIT_HD44780_D7_LOW        &= ~HD44780_D7_SR_PIN
    #endif
  #endif
  #ifdef HD44780_SR_CLK_INVERTED
    #define HD44780_SR_CLOCK_HIGH           HD44780_SR_CLK_MCU_OUT_PORT &= ~HD44780_SR_CLK_MCU_OUT_PIN
    #define HD44780_SR_CLOCK_LOW            HD44780_SR_CLK_MCU_OUT_PORT |=  HD44780_SR_CLK_MCU_OUT_PIN
  #else
    #define HD44780_SR_CLOCK_HIGH           HD44780_SR_CLK_MCU_OUT_PORT |=  HD44780_SR_CLK_MCU_OUT_PIN
    #define HD44780_SR_CLOCK_LOW            HD44780_SR_CLK_MCU_OUT_PORT &= ~HD44780_SR_CLK_MCU_OUT_PIN
  #endif
  #ifdef HD44780_SR_DIN_INVERTED
    #define HD44780_SR_DATA_HIGH            HD44780_SR_DIN_MCU_OUT_PORT &= ~HD44780_SR_DIN_MCU_OUT_PIN
    #define HD44780_SR_DATA_LOW             HD44780_SR_DIN_MCU_OUT_PORT |=  HD44780_SR_DIN_MCU_OUT_PIN
  #else
    #define HD44780_SR_DATA_HIGH            HD44780_SR_DIN_MCU_OUT_PORT |=  HD44780_SR_DIN_MCU_OUT_PIN
    #define HD44780_SR_DATA_LOW             HD44780_SR_DIN_MCU_OUT_PORT &= ~HD44780_SR_DIN_MCU_OUT_PIN
  #endif
  #ifdef HD44780_SR_TYPE_595
    #ifdef HD44780_SR_LAT_INVERTED
      #define HD44780_SR_LAT_HIGH           HD44780_SR_LAT_MCU_OUT_PORT &= ~HD44780_SR_LAT_MCU_OUT_PIN
      #define HD44780_SR_LAT_LOW            HD44780_SR_LAT_MCU_OUT_PORT |=  HD44780_SR_LAT_MCU_OUT_PIN
    #else
      #define HD44780_SR_LAT_HIGH           HD44780_SR_LAT_MCU_OUT_PORT |=  HD44780_SR_LAT_MCU_OUT_PIN
      #define HD44780_SR_LAT_LOW            HD44780_SR_LAT_MCU_OUT_PORT &= ~HD44780_SR_LAT_MCU_OUT_PIN
    #endif
  #endif
#endif
#ifdef HD44780_ENABLE_INVERTED
  #define HD44780_ENABLE_HIGH               HD44780_ENABLE_MCU_OUT_PORT &= ~HD44780_ENABLE_MCU_OUT_PIN
  #define HD44780_ENABLE_LOW                HD44780_ENABLE_MCU_OUT_PORT |=  HD44780_ENABLE_MCU_OUT_PIN
#else
  #define HD44780_ENABLE_HIGH               HD44780_ENABLE_MCU_OUT_PORT |=  HD44780_ENABLE_MCU_OUT_PIN
  #define HD44780_ENABLE_LOW                HD44780_ENABLE_MCU_OUT_PORT &= ~HD44780_ENABLE_MCU_OUT_PIN
#endif
#ifdef HD44780_RS_PIN_BY_SR
  #ifdef HD44780_RS_INVERTED
    #define SET_BIT_HD44780_RS_HIGH         &= ~HD44780_RS_SR_PIN
    #define SET_BIT_HD44780_RS_LOW          |=  HD44780_RS_SR_PIN
  #else
    #define SET_BIT_HD44780_RS_HIGH         |=  HD44780_RS_SR_PIN
    #define SET_BIT_HD44780_RS_LOW          &= ~HD44780_RS_SR_PIN
  #endif
  #define SET_BIT_HD44780_DATA              SET_BIT_HD44780_RS_HIGH
  #define SET_BIT_HD44780_COMMAND           SET_BIT_HD44780_RS_LOW
#else
  #ifdef HD44780_RS_INVERTED
    #define HD44780_RS_HIGH                 HD44780_RS_MCU_OUT_PORT &= ~HD44780_RS_MCU_OUT_PIN
    #define HD44780_RS_LOW                  HD44780_RS_MCU_OUT_PORT |=  HD44780_RS_MCU_OUT_PIN
  #else
    #define HD44780_RS_HIGH                 HD44780_RS_MCU_OUT_PORT |=  HD44780_RS_MCU_OUT_PIN
    #define HD44780_RS_LOW                  HD44780_RS_MCU_OUT_PORT &= ~HD44780_RS_MCU_OUT_PIN
  #endif
  #define HD44780_RS_DATA                   HD44780_RS_HIGH
  #define HD44780_RS_COMMAND                HD44780_RS_LOW
#endif
#ifdef HD44780_TYPE_1x8
  #define HD44780_DATA_BUFFER_SIZE          8
  #define HD44780_NR_OF_ROWS                1
  #define HD44780_NR_OF_COLUMNS             8
#elif defined HD44780_TYPE_1x16
  #define HD44780_DATA_BUFFER_SIZE          16
  #define HD44780_NR_OF_ROWS                1
  #define HD44780_NR_OF_COLUMNS             16
#elif defined HD44780_TYPE_1x20
  #define HD44780_DATA_BUFFER_SIZE          20
  #define HD44780_NR_OF_ROWS                1
  #define HD44780_NR_OF_COLUMNS             20
#elif defined HD44780_TYPE_2x8
  #define HD44780_DATA_BUFFER_SIZE          16
  #define HD44780_NR_OF_ROWS                2
  #define HD44780_NR_OF_COLUMNS             8
#elif defined HD44780_TYPE_2x16
  #define HD44780_DATA_BUFFER_SIZE          32
  #define HD44780_NR_OF_ROWS                2
  #define HD44780_NR_OF_COLUMNS             16
#elif defined HD44780_TYPE_2x20
  #define HD44780_DATA_BUFFER_SIZE          40
  #define HD44780_NR_OF_ROWS                2
  #define HD44780_NR_OF_COLUMNS             20
#elif defined HD44780_TYPE_4x16
  #define HD44780_DATA_BUFFER_SIZE          64
  #define HD44780_NR_OF_ROWS                4
  #define HD44780_NR_OF_COLUMNS             16
  #define HD44780_3RD_ROW_START_ADDRESS     0x10
  #define HD44780_4TH_ROW_START_ADDRESS     0x50
#elif defined HD44780_TYPE_4x20
  #define HD44780_DATA_BUFFER_SIZE          80
  #define HD44780_NR_OF_ROWS                4
  #define HD44780_NR_OF_COLUMNS             20
  #define HD44780_3RD_ROW_START_ADDRESS     0x14
  #define HD44780_4TH_ROW_START_ADDRESS     0x54
#endif


#ifdef HD44780_SR_SHARES_OTHER_FUNCTION
  static volatile uint8_t u8__sr_data_byte = 0x00;
#endif


static volatile uint8_t u8__hd44780_data_buffer[HD44780_DATA_BUFFER_SIZE];


void hd44780_timer_isr( void )
{
  static uint8_t  u8__buffer_counter = 0;
  static uint8_t  u8__data_byte;
  static uint16_t u16__flags = 0x00;

  #ifdef HD44780_SERIAL_MODE
    uint8_t u8__sr_bit_counter;
  #endif

  #ifndef HD44780_SR_SHARES_OTHER_FUNCTION
    #ifdef HD44780_SERIAL_MODE
      #if defined HD44780_4BIT_MODE || (defined HD44780_8BIT_MODE && !defined HD44780_CONSECUTIVE_PINS_MODE )
        uint8_t u8__sr_data_byte = 0x00;
      #endif
    #endif
  #endif

  #if HD44780_NR_OF_ROWS > 2
    static const uint8_t u8__row_start_address[3] = { 0x40, HD44780_3RD_ROW_START_ADDRESS, HD44780_4TH_ROW_START_ADDRESS };
  #endif

  HD44780_ENABLE_LOW;

  #ifdef HD44780_4BIT_MODE
  if( !(u16__flags & 0x2000) )
  {
  #endif
    if( u16__flags & 0x8000 )
    {
      if( u16__flags & 0x4000 )
      {
        #ifdef HD44780_RS_PIN_BY_SR
          u16__flags |= 0x0080;
        #else
          HD44780_RS_DATA;
        #endif

        u8__data_byte = u8__hd44780_data_buffer[u8__buffer_counter];

        #if HD44780_NR_OF_ROWS > 1
          if( !(++u8__buffer_counter % HD44780_NR_OF_COLUMNS) )
        #else
          if( ++u8__buffer_counter >= HD44780_DATA_BUFFER_SIZE )
        #endif
        {
          u16__flags &= ~0x4000;
        }
      }
      else
      {
        #ifdef HD44780_RS_PIN_BY_SR
          u16__flags &= ~0x0080;
        #else
          HD44780_RS_COMMAND;
        #endif

        #if HD44780_NR_OF_ROWS >= 2
          if( u8__buffer_counter < HD44780_DATA_BUFFER_SIZE )
          {
            #if HD44780_NR_OF_ROWS > 2
              u8__data_byte = u8__row_start_address[((u8__buffer_counter / HD44780_NR_OF_COLUMNS) - 1)];
            #else
              u8__data_byte = 0x40;
            #endif
          }
          else
          {
            u8__data_byte = 0x00;
            u8__buffer_counter = 0;
          }

          u8__data_byte |= 0x80;
        #else
          u8__data_byte = 0x80;
          u8__buffer_counter = 0;
        #endif

        u16__flags |= 0x4000;
      }
    }
    else
    {
      #ifdef HD44780_4BIT_MODE
        #if HD44780_NR_OF_ROWS < 2
          uint8_t u8__initialization_bytes[7] = { 0x30, 0x30, 0x20, 0x20, 0x08, 0x06, 0x0C };
        #else
          uint8_t u8__initialization_bytes[7] = { 0x30, 0x30, 0x20, 0x28, 0x08, 0x06, 0x0C };
        #endif
      #else
        #if HD44780_NR_OF_ROWS < 2
          uint8_t u8__initialization_bytes[6] = { 0x30, 0x30, 0x30, 0x08, 0x06, 0x0C };
        #else
          uint8_t u8__initialization_bytes[6] = { 0x30, 0x30, 0x38, 0x08, 0x06, 0x0C };
        #endif
      #endif

      #ifdef HD44780_RS_PIN_BY_SR
        u16__flags &= ~0x0080;
      #else
        HD44780_RS_COMMAND;
      #endif

      if( !(u16__flags & 0x007F) )
      {
        uint16_t u16__initialization_step;

        u16__initialization_step = ((u16__flags & 0x0F00) >> 8);

        if( u16__initialization_step == 0 )
        {
          u16__flags += (80 & 0x007F);
        }
        else if( u16__initialization_step == 1 )
        {
          u16__flags += (10 & 0x007F);
          u8__data_byte = 0x30;
          HD44780_ENABLE_HIGH;
        }
        else
        {
          u8__data_byte = u8__initialization_bytes[(u16__initialization_step - 2)];
          HD44780_ENABLE_HIGH;
        }

        u16__flags &= ~0x0F00;

        #ifdef HD44780_4BIT_MODE
        if( u16__initialization_step < 5 )
        {
          u16__flags |= 0x2000;
        }
        else
        {
          u16__flags |= 0x1000;
        }

        if( u16__initialization_step > 7 )
        #else
        if( u16__initialization_step > 6 )
        #endif
        {
          u16__flags |= (0x1000 | 0x8000);
          u8__buffer_counter = HD44780_DATA_BUFFER_SIZE;
        }
        else
        {
          u16__flags |= ((++u16__initialization_step) << 8);
        }
      }
      else
      {
        u16__flags--;
      }
    }
  #ifdef HD44780_4BIT_MODE
  }
  #endif

  #ifdef HD44780_PARALLEL_MODE
    #ifdef HD44780_4BIT_MODE
      #ifdef HD44780_CONSECUTIVE_PINS_MODE
        #ifdef HD44780_4BIT_MCU_HIGHER_NIBBLE
          HD44780_MCU_OUT_PORT = ((HD44780_MCU_OUT_PORT & 0x0F) | (u8__data_byte & 0xF0));
        #else
          HD44780_MCU_OUT_PORT = ((HD44780_MCU_OUT_PORT & 0xF0) | ((u8__data_byte >> 4) & 0x0F));
        #endif
      #else
        if( u8__data_byte & 0x80 ) { HD44780_D7_HIGH; } else { HD44780_D7_LOW; }
        if( u8__data_byte & 0x40 ) { HD44780_D6_HIGH; } else { HD44780_D6_LOW; }
        if( u8__data_byte & 0x20 ) { HD44780_D5_HIGH; } else { HD44780_D5_LOW; }
        if( u8__data_byte & 0x10 ) { HD44780_D4_HIGH; } else { HD44780_D4_LOW; }
      #endif

      if( u16__flags & 0x2000 )
      {
        u16__flags &= ~0x2000;
      }
      else
      {
        u8__data_byte <<= 4;
        u16__flags |= 0x2000;
      }
    #else
      #ifdef HD44780_MIXED_PINS_MODE
        if( u8__data_byte & 0x80 ) { HD44780_D7_HIGH; } else { HD44780_D7_LOW; }
        if( u8__data_byte & 0x40 ) { HD44780_D6_HIGH; } else { HD44780_D6_LOW; }
        if( u8__data_byte & 0x20 ) { HD44780_D5_HIGH; } else { HD44780_D5_LOW; }
        if( u8__data_byte & 0x10 ) { HD44780_D4_HIGH; } else { HD44780_D4_LOW; }
        if( u8__data_byte & 0x08 ) { HD44780_D3_HIGH; } else { HD44780_D3_LOW; }
        if( u8__data_byte & 0x04 ) { HD44780_D2_HIGH; } else { HD44780_D2_LOW; }
        if( u8__data_byte & 0x02 ) { HD44780_D1_HIGH; } else { HD44780_D1_LOW; }
        if( u8__data_byte & 0x01 ) { HD44780_D0_HIGH; } else { HD44780_D0_LOW; }
      #else
        HD44780_MCU_OUT_PORT = u8__data_byte;
      #endif
    #endif
  #else
    #ifdef HD44780_4BIT_MODE
      #ifdef HD44780_CONSECUTIVE_PINS_MODE
        #ifdef HD44780_SR_SHARES_OTHER_FUNCTION
          #ifdef HD44780_4BIT_SR_HIGHER_NIBBLE
            u8__sr_data_byte = ((u8__sr_data_byte & 0x0F) | (u8__data_byte & 0xF0));
          #else
            u8__sr_data_byte = ((u8__sr_data_byte & 0xF0) | ((u8__data_byte >> 4) & 0x0F));
          #endif
        #else
          #ifdef HD44780_4BIT_SR_HIGHER_NIBBLE
            u8__sr_data_byte = (u8__data_byte & 0xF0);
          #else
            u8__sr_data_byte = ((u8__data_byte >> 4) & 0x0F);
          #endif
        #endif
      #else
        if( u8__data_byte & 0x80 ) { u8__sr_data_byte SET_BIT_HD44780_D7_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D7_LOW; }
        if( u8__data_byte & 0x40 ) { u8__sr_data_byte SET_BIT_HD44780_D6_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D6_LOW; }
        if( u8__data_byte & 0x20 ) { u8__sr_data_byte SET_BIT_HD44780_D5_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D5_LOW; }
        if( u8__data_byte & 0x10 ) { u8__sr_data_byte SET_BIT_HD44780_D4_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D4_LOW; }
      #endif

      #ifdef HD44780_RS_PIN_BY_SR
        if( u16__flags & 0x0080)
        {
          u8__sr_data_byte SET_BIT_HD44780_DATA;
        }
        else
        {
          u8__sr_data_byte SET_BIT_HD44780_COMMAND;
        }
      #endif

      if( u16__flags & 0x2000 )
      {
        u16__flags &= ~0x2000;
      }
      else
      {
        u8__data_byte <<= 4;
        u16__flags |= 0x2000;
      }

    #else
      #ifdef HD44780_MIXED_PINS_MODE
        if( u8__data_byte & 0x80 ) { u8__sr_data_byte SET_BIT_HD44780_D7_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D7_LOW; }
        if( u8__data_byte & 0x40 ) { u8__sr_data_byte SET_BIT_HD44780_D6_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D6_LOW; }
        if( u8__data_byte & 0x20 ) { u8__sr_data_byte SET_BIT_HD44780_D5_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D5_LOW; }
        if( u8__data_byte & 0x10 ) { u8__sr_data_byte SET_BIT_HD44780_D4_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D4_LOW; }
        if( u8__data_byte & 0x08 ) { u8__sr_data_byte SET_BIT_HD44780_D3_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D3_LOW; }
        if( u8__data_byte & 0x04 ) { u8__sr_data_byte SET_BIT_HD44780_D2_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D2_LOW; }
        if( u8__data_byte & 0x02 ) { u8__sr_data_byte SET_BIT_HD44780_D1_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D1_LOW; }
        if( u8__data_byte & 0x01 ) { u8__sr_data_byte SET_BIT_HD44780_D0_HIGH; } else { u8__sr_data_byte SET_BIT_HD44780_D0_LOW; }
      #endif
    #endif

    for( u8__sr_bit_counter = 0; u8__sr_bit_counter < 8; u8__sr_bit_counter++ )
    {
      #if defined HD44780_4BIT_MODE || (defined HD44780_8BIT_MODE && !defined HD44780_CONSECUTIVE_PINS_MODE )
      if( u8__sr_data_byte & 0x80 )
      #else
      if( u8__data_byte & 0x80 )
      #endif
      {
        HD44780_SR_DATA_HIGH;
      }
      else
      {
        HD44780_SR_DATA_LOW;
      }

      #if defined HD44780_4BIT_MODE || (defined HD44780_8BIT_MODE && !defined HD44780_CONSECUTIVE_PINS_MODE )
      u8__sr_data_byte <<= 1;
      #else
      u8__data_byte <<= 1;
      #endif

      HD44780_SR_CLOCK_HIGH;
      HD44780_SR_CLOCK_LOW;
    }

    #ifdef HD44780_SR_TYPE_595
      HD44780_SR_LAT_HIGH;
      HD44780_SR_LAT_LOW;
    #endif
  #endif

  if( u16__flags & 0x1000 )
  {
    HD44780_ENABLE_HIGH;
  }
}


uint8_t hd44780_write_string( char * ch__string, uint8_t u8__row, uint8_t u8__column, uint8_t u8__cr_lf )
{
  uint8_t u8__buffer_position;

  #if HD44780_NR_OF_ROWS > 1
    u8__buffer_position = (((u8__row - 1) * HD44780_NR_OF_COLUMNS) + (u8__column - 1));
  #else
    u8__buffer_position = (u8__column - 1);
  #endif

  if( u8__row <= HD44780_NR_OF_ROWS )
  {
    if( u8__column <= HD44780_NR_OF_COLUMNS )
    {
      while( *ch__string != 0 )
      {
        u8__hd44780_data_buffer[u8__buffer_position] = *(ch__string++);

        if( u8__cr_lf )
        {
          if( ++u8__buffer_position >= HD44780_DATA_BUFFER_SIZE )
          {
            u8__buffer_position = 0;
          }
        }
        else
        {
          #if HD44780_NR_OF_ROWS > 1
          if( !(++u8__buffer_position % HD44780_NR_OF_COLUMNS) )
          #else
          if( ++u8__buffer_position >= HD44780_DATA_BUFFER_SIZE )
          #endif
          {
            return HD44780_NR_OF_COLUMNS;
          }
        }
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }

  return (u8__buffer_position % HD44780_NR_OF_COLUMNS);
}


void hd44780_clear_row( uint8_t u8__row )
{
  if( u8__row <= HD44780_NR_OF_ROWS )
  {
    uint8_t u8__counter;

    #if HD44780_NR_OF_ROWS > 1
      if( u8__row <= HD44780_NR_OF_ROWS )
      {
        uint8_t u8__buffer_position;

        u8__buffer_position = ((u8__row - 1) * HD44780_NR_OF_COLUMNS);

        for( u8__counter = u8__buffer_position; u8__counter < (u8__buffer_position + HD44780_NR_OF_COLUMNS); u8__counter++ )
        {
          u8__hd44780_data_buffer[u8__counter] = ' ';
        }
      }
    #else
      for( u8__counter = 0; u8__counter < HD44780_NR_OF_COLUMNS; u8__counter++ )
      {
        u8__hd44780_data_buffer[u8__counter] = ' ';
      }
    #endif
  }
}


void hd44780_clear_screen( void )
{
  uint8_t u8__counter;

  for( u8__counter = 0; u8__counter < HD44780_DATA_BUFFER_SIZE; u8__counter++ )
  {
    u8__hd44780_data_buffer[u8__counter] = ' ';
  }
}


void hd44780_blank_out_remaining_row( uint8_t u8__row, uint8_t u8__column )
{
  if( u8__row <= HD44780_NR_OF_ROWS )
  {
    if( u8__column <= HD44780_NR_OF_COLUMNS )
    {
      uint8_t u8__counter;

      #if HD44780_NR_OF_ROWS > 1
        uint8_t u8__buffer_position;

        u8__buffer_position = ((u8__row - 1) * HD44780_NR_OF_COLUMNS);

        for( u8__counter = (u8__column - 1); u8__counter < HD44780_NR_OF_COLUMNS; u8__counter++ )
        {
          u8__hd44780_data_buffer[(u8__buffer_position + u8__counter)] = ' ';
        }
      #else
        for( u8__counter = (u8__column - 1); u8__counter < HD44780_NR_OF_COLUMNS; u8__counter++ )
        {
          u8__hd44780_data_buffer[u8__counter] = ' ';
        }
      #endif
    }
  }
}


void hd44780_write_shared_shift_register_bits( uint8_t u8__sr_bitmap )
{
  #ifdef HD44780_SR_SHARES_OTHER_FUNCTION
    u8__sr_data_byte = u8__sr_bitmap;
  #endif
}


uint8_t hd44780_output_adc_value_mv( uint32_t u32__adc_value, uint16_t u16__adc_reference_mv, uint8_t u8__adc_resolution_bits, uint8_t u8__leading_zero_handling, uint8_t u8__row, uint8_t u8__column, uint8_t u8__cr_lf )
{
  uint16_t u16__max_adc_result = 0;
  uint16_t u16__adc_value_mv;
  uint8_t  u8__last_written_buffer_position;

  if     ( u8__adc_resolution_bits ==  8 ) { u16__max_adc_result = 255;   }
  else if( u8__adc_resolution_bits == 10 ) { u16__max_adc_result = 1023;  }
  else if( u8__adc_resolution_bits == 12 ) { u16__max_adc_result = 4095;  }
  else if( u8__adc_resolution_bits == 14 ) { u16__max_adc_result = 16383; }
  else if( u8__adc_resolution_bits == 16 ) { u16__max_adc_result = 65535; }

  if( u16__max_adc_result )
  {
    u16__adc_value_mv = ((u16__adc_reference_mv * u32__adc_value) / u16__max_adc_result);
    u8__last_written_buffer_position = hd44780_output_unsigned_16bit_value( u16__adc_value_mv, u8__leading_zero_handling, u8__row, u8__column, u8__cr_lf );
  }

  return u8__last_written_buffer_position;
}


uint8_t hd44780_output_unsigned_16bit_value( uint16_t u16__value, uint8_t u8__leading_zero_handling, uint8_t u8__row, uint8_t u8__column, uint8_t u8__cr_lf )
{
  char ch__string_buffer[6];
  uint8_t u8__last_written_buffer_position;

  ch__string_buffer[0] = ((u16__value / 10000) + '0');
  u16__value %= 10000;
  ch__string_buffer[1] = ((u16__value / 1000)  + '0');
  u16__value %= 1000;
  ch__string_buffer[2] = ((u16__value / 100)   + '0');
  u16__value %= 100;
  ch__string_buffer[3] = ((u16__value / 10 )   + '0');
  ch__string_buffer[4] = ((u16__value % 10)    + '0');
  ch__string_buffer[5] = '\0';

  if( u8__leading_zero_handling )
  {
    uint8_t u8__counter;

    for( u8__counter = 0; u8__counter < 4; u8__counter++ )
    {
      if( ch__string_buffer[u8__counter] != '0' )
      {
        break;
      }
      else
      {
        ch__string_buffer[u8__counter] = ' ';
      }
    }

    if( u8__leading_zero_handling == BLANK_ZEROES )
    {
      u8__last_written_buffer_position = hd44780_write_string( ch__string_buffer, u8__row, u8__column, u8__cr_lf );
    }
    else
    {
      u8__last_written_buffer_position = hd44780_write_string( (ch__string_buffer + u8__counter), u8__row, u8__column, u8__cr_lf );
    }
  }
  else
  {
    u8__last_written_buffer_position = hd44780_write_string( ch__string_buffer, u8__row, u8__column, u8__cr_lf );
  }

  return u8__last_written_buffer_position;
}
