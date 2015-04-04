
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
} meguco_user_market_state;

typedef struct
{
  zlimdb_entity entity;
  uint64_t bot_market_id;
  uint8_t state;
  // todo: credentials
} meguco_user_market_entity;

typedef struct
{
  zlimdb_entity entity;
  uint16_t name_size;
  uint64_t bot_engine_id;
  uint64_t bot_market_id;
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
