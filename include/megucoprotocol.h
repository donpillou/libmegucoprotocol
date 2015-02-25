
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
public:
  zlimdb_entity entity;
  double bid;
  double ask;
} meguco_ticker_entity;

#pragma pack(pop)

#endif // _MEGUCO_PROTOCOL_H
