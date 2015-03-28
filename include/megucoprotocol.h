
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

typedef struct
{
  zlimdb_entity entity;
  uint64_t bot_market_id;
  uint8_t state;
} meguco_user_market_entity;

typedef struct
{
  zlimdb_entity entity;
  uint16_t name_size;
  uint64_t bot_engine_id;
  uint64_t bot_market_id;
  uint8_t state;
} meguco_user_session_entity;

//todo: use this or remote it
typedef struct
{
  zlimdb_entity entity;
  uint8_t state;
  uint32_t pid;
  uint32_t exit_code;
  uint16_t cmd_size;
} meguco_process_entity;

#pragma pack(pop)

#endif // _MEGUCO_PROTOCOL_H
