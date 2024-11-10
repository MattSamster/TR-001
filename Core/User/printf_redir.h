/**
 * @file printf_redir.h
 * @author Matthew Sam (mathcsam@gmail.com)
 * @brief enable printf to serial via uart
 * @version 0.1
 * @date 2024-11-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __PRINTF_REDIR_H
#define __PRINTF_REDIR_H

#include "usart.h"

int __io_putchar(int ch){
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

#endif
