
#ifndef _MEGUCO_PROTOCOL_H
#define _MEGUCO_PROTOCOL_H

#include <zlimdbprotocol.h>

#pragma pack(push, 1)

typedef struct
{
  zlimdb_entity entity;
  double price;
  double amount;
  uint32_t flags; // unused?
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
} meguco_bot_market_entity; // todo: rename in meguco_market_entity

typedef struct
{
  zlimdb_entity entity;
  uint16_t name_size;
} meguco_bot_engine_entity; // todo: rename in meguco_bot_entity

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
} meguco_user_market_entity; // todo: rename in meguco_user_broker_entity

typedef enum
{
  meguco_user_market_control_refresh_orders,
  meguco_user_market_control_refresh_transactions,
  meguco_user_market_control_refresh_balance,
} meguco_user_market_control_code;

typedef enum
{
  meguco_user_broker_order_submitting,
  meguco_user_broker_order_open,
  //meguco_user_broker_order_canceling, // ??
  meguco_user_broker_order_canceled,
  //meguco_user_broker_order_updating, // ??
  meguco_user_broker_order_closed,
  //meguco_user_broker_order_removing, // ??
  meguco_user_broker_order_error,
  //meguco_user_broker_order_draft,
} meguco_user_broker_order_state;

typedef enum
{
  meguco_user_broker_order_buy,
  meguco_user_broker_order_sell,
} meguco_user_broker_order_type;

typedef struct
{
  zlimdb_entity entity;
  uint8_t type;
  uint8_t state;
  double price;
  double amount;
  double total;
  uint64_t raw_id;
  uint64_t timeout;
} meguco_user_broker_order_entity;

typedef enum
{
  meguco_user_broker_order_control_cancel,
  meguco_user_broker_order_control_update,
} meguco_user_broker_order_control_code;

typedef struct
{
  double price;
  double amount;
} meguco_user_broker_order_control_update_params;

typedef struct
{
  zlimdb_entity entity;
  double reserved_usd; // usd in open orders
  double reserved_btc; // btc in open orders
  double available_usd;
  double available_btc;
  double fee;
} meguco_user_market_balance_entity; // todo: rename in meguco_user_broker_balance_entity

typedef enum
{
  meguco_user_market_transaction_buy,
  meguco_user_market_transaction_sell,
} meguco_user_market_transaction_type;

typedef struct
{
  zlimdb_entity entity;
  uint8_t type;
  double price;
  double amount;
  double total;
  uint64_t raw_id;
} meguco_user_market_transaction_entity; // todo: rename in meguco_user_broker_transaction_entity

typedef enum
{
  meguco_user_session_asset_buy,
  meguco_user_session_asset_sell,
} meguco_user_session_asset_type;

typedef enum
{
  meguco_user_session_asset_submitting,
  meguco_user_session_asset_wait_buy,
  meguco_user_session_asset_buying,
  meguco_user_session_asset_wait_sell,
  meguco_user_session_asset_selling,
} meguco_user_session_asset_state;

typedef struct
{
  zlimdb_entity entity;
  uint8_t type;
  uint8_t state;
  double price;
  double invest_comm;
  double invest_base;
  double balance_comm;
  double balance_base;
  double profitable_price;
  double flip_price;
  uint64_t order_id;
} meguco_user_session_asset_entity;

typedef enum
{
  meguco_user_session_asset_control_update,
} meguco_user_session_asset_control_code;

typedef enum
{
  meguco_user_session_stopped,
  meguco_user_session_starting,
  meguco_user_session_running,
  meguco_user_session_stopping,
} meguco_user_session_state;

typedef enum
{
  meguco_user_session_none,
  meguco_user_session_live,
  meguco_user_session_simulation,
} meguco_user_session_mode;

typedef struct
{
  zlimdb_entity entity;
  uint16_t name_size;
  uint64_t bot_engine_id;
  uint32_t user_market_id;
  uint8_t state;
  uint8_t mode;
} meguco_user_session_entity;

typedef enum
{
  meguco_user_session_control_start_live,
  meguco_user_session_control_start_simulation,
  meguco_user_session_control_stop,
} meguco_user_session_control_code;

typedef enum
{
  meguco_user_session_property_number,
  meguco_user_session_property_string,
} meguco_user_session_property_type;

typedef enum
{
  meguco_user_session_property_none = 0x00,
  meguco_user_session_property_read_only = 0x01,
} meguco_user_session_property_flag;

typedef struct
{
  zlimdb_entity entity;
  uint8_t type;
  uint32_t flags;
  uint16_t name_size;
  uint16_t value_size;
  uint16_t unit_size;
} meguco_user_session_property_entity;

typedef enum
{
  meguco_user_session_property_control_update,
} meguco_user_session_property_control_code;

typedef struct
{
  uint16_t value_size;
} meguco_user_session_property_control_update_params;

typedef enum
{
  meguco_user_session_marker_buy,
  meguco_user_session_marker_sell,
  meguco_user_session_marker_buy_attempt,
  meguco_user_session_marker_sell_attempt,
  meguco_user_session_marker_good_buy,
  meguco_user_session_marker_good_sell,
} meguco_user_session_marker_type;

typedef struct
{
  zlimdb_entity entity;
  uint8_t type;
} meguco_user_session_marker_entity;

typedef struct
{
  zlimdb_entity entity;
  uint16_t cmd_size;
} meguco_process_entity;

typedef enum
{
  meguco_log_info,
  meguco_log_warning,
  meguco_log_error,
} meguco_log_type;

typedef struct
{
  zlimdb_entity entity;
  uint8_t type;
  uint16_t message_size;
} meguco_log_entity;

#pragma pack(pop)

#endif // _MEGUCO_PROTOCOL_H
