
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
} meguco_broker_type_entity;

typedef struct
{
  zlimdb_entity entity;
  uint16_t name_size;
} meguco_bot_type_entity;

typedef enum
{
  meguco_user_control_create_broker,
  meguco_user_control_remove_broker,
  meguco_user_control_create_session,
  meguco_user_control_remove_session,
  meguco_user_control_start_session,
  meguco_user_control_stop_session,
} meguco_user_control_code;

typedef enum
{
  meguco_user_broker_stopped,
  meguco_user_broker_starting,
  meguco_user_broker_stopping,
  meguco_user_broker_running,
} meguco_user_broker_state;

typedef struct
{
  zlimdb_entity entity;
  uint64_t broker_type_id;
  uint8_t state;
  uint16_t user_name_size;
  uint16_t key_size;
  uint16_t secret_size;
} meguco_user_broker_entity;

typedef enum
{
  meguco_user_broker_control_refresh_orders,
  meguco_user_broker_control_refresh_transactions,
  meguco_user_broker_control_refresh_balance,
  meguco_user_broker_control_create_order,
  meguco_user_broker_control_cancel_order,
  meguco_user_broker_control_update_order,
  meguco_user_broker_control_remove_order,
} meguco_user_broker_control_code;

typedef struct
{
  double price;
  double amount;
  double total;
} meguco_user_broker_control_update_order_params;

typedef enum
{
  meguco_user_broker_order_submitting,
  meguco_user_broker_order_open,
  // todo: meguco_user_broker_order_canceling
  meguco_user_broker_order_canceled,
  // todo: meguco_user_broker_order_updating
  meguco_user_broker_order_closed,
  // todo: meguco_user_broker_order_removing
  meguco_user_broker_order_error,
} meguco_user_broker_order_state;

typedef enum
{
  meguco_user_broker_order_buy,
  meguco_user_broker_order_sell,
} meguco_user_broker_order_type;

typedef struct
{
  zlimdb_entity entity;
  double price;
  double amount;
  double total;
  uint64_t raw_id;
  uint64_t timeout;
  uint8_t type;
  uint8_t state;
} meguco_user_broker_order_entity;

typedef struct
{
  zlimdb_entity entity;
  double reserved_usd; // usd in open orders
  double reserved_btc; // btc in open orders
  double available_usd;
  double available_btc;
  double fee;
} meguco_user_broker_balance_entity;

typedef enum
{
  meguco_user_broker_transaction_buy,
  meguco_user_broker_transaction_sell,
} meguco_user_broker_transaction_type;

typedef struct
{
  zlimdb_entity entity;
  double price;
  double amount;
  double total;
  uint64_t raw_id;
  uint8_t type;
} meguco_user_broker_transaction_entity;

typedef enum
{
  meguco_user_session_stopped,
  meguco_user_session_stopping,
  meguco_user_session_starting,
  meguco_user_session_running,
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
  uint64_t bot_type_id;
  uint32_t broker_id;
  uint8_t state;
  uint8_t mode;
} meguco_user_session_entity;

typedef enum
{
  meguco_user_session_control_create_asset,
  meguco_user_session_control_remove_asset,
  meguco_user_session_control_update_asset,
  meguco_user_session_control_update_property,
} meguco_user_session_control_code;

typedef struct
{
  uint16_t value_size;
} meguco_user_session_control_update_property_params;

typedef struct
{
  double flip_price;
} meguco_user_session_control_update_asset_params;

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
  double price;
  double invest_comm;
  double invest_base;
  double balance_comm;
  double balance_base;
  double profitable_price;
  double flip_price;
  uint64_t order_id;
  int64_t lastTransactionTime;
  uint8_t type;
  uint8_t state;
} meguco_user_session_asset_entity;

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
  uint32_t flags;
  uint8_t type;
  uint16_t name_size;
  uint16_t value_size;
  uint16_t unit_size;
} meguco_user_session_property_entity;

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
  meguco_process_control_start,
  meguco_process_control_stop,
} meguco_process_control_code;

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
} meguco_log_entity; // todo: rename meguco_session_message_entity

#pragma pack(pop)

#endif // _MEGUCO_PROTOCOL_H
