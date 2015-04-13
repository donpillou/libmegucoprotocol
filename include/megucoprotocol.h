
#ifndef _MEGUCO_PROTOCOL_H
#define _MEGUCO_PROTOCOL_H

#include <zlimdbprotocol.h>

#pragma pack(push, 1)

typedef struct
{
  zlimdb_entity entity;
  double price;
  double amount;
  uint32_t flags;
} meguco_trade_entity;

typedef struct
{
  zlimdb_entity entity;
  double bid;
  double ask;
} meguco_ticker_entity;

typedef struct
{
  zlimdb_entity entity;
  uint16_t name_size;
} meguco_bot_market_entity;

typedef struct
{
  zlimdb_entity entity;
  uint16_t name_size;
} meguco_bot_engine_entity;

typedef enum
{
  meguco_user_market_stopped,
  meguco_user_market_starting,
  meguco_user_market_running,
  meguco_user_market_stopping,
} meguco_user_market_state;

typedef struct
{
  zlimdb_entity entity;
  uint64_t bot_market_id;
  uint8_t state;
  uint16_t user_name_size;
  uint16_t key_size;
  uint16_t secret_size;
} meguco_user_market_entity;

typedef enum
{
  //meguco_user_market_order_draft,
  meguco_user_market_order_opening,
  meguco_user_market_order_open,
  meguco_user_market_order_canceling,
  meguco_user_market_order_canceled,
  meguco_user_market_order_closed,
  meguco_user_market_order_error,
} meguco_user_market_order_state;

typedef struct
{
  zlimdb_entity entity;
  uint8_t state;
  double price;
  double amount;
  uint64_t raw_id;
} meguco_user_market_order_entity;

typedef enum
{
  meguco_user_session_stopped,
  meguco_user_session_starting,
  meguco_user_session_running,
  meguco_user_session_stopping,
} meguco_user_session_state;

typedef struct
{
  zlimdb_entity entity;
  uint64_t bot_engine_id;
  uint32_t user_market_id;
  uint8_t state;
} meguco_user_session_entity;

typedef struct
{
  zlimdb_entity entity;
  uint32_t process_id;
  uint16_t cmd_size;
} meguco_process_entity;

#pragma pack(pop)

#endif // _MEGUCO_PROTOCOL_H
