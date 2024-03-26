#pragma once
// MESSAGE USV_SIMULATION_COMMOND PACKING

#define MAVLINK_MSG_ID_USV_SIMULATION_COMMOND 154

MAVPACKED(
typedef struct __mavlink_usv_simulation_commond_t {
 float command_velocity; /*<  Simulation command_velocity ranges -1(back)~1(forward)*/
 float command_turn; /*<  Simulation command_turn ranges -1(left)~1(right)*/
 uint8_t stage; /*<  The stage of the task*/
}) mavlink_usv_simulation_commond_t;

#define MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN 9
#define MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_MIN_LEN 9
#define MAVLINK_MSG_ID_154_LEN 9
#define MAVLINK_MSG_ID_154_MIN_LEN 9

#define MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_CRC 199
#define MAVLINK_MSG_ID_154_CRC 199



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_USV_SIMULATION_COMMOND { \
    154, \
    "USV_SIMULATION_COMMOND", \
    3, \
    {  { "stage", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_usv_simulation_commond_t, stage) }, \
         { "command_velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_usv_simulation_commond_t, command_velocity) }, \
         { "command_turn", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_usv_simulation_commond_t, command_turn) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_USV_SIMULATION_COMMOND { \
    "USV_SIMULATION_COMMOND", \
    3, \
    {  { "stage", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_usv_simulation_commond_t, stage) }, \
         { "command_velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_usv_simulation_commond_t, command_velocity) }, \
         { "command_turn", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_usv_simulation_commond_t, command_turn) }, \
         } \
}
#endif

/**
 * @brief Pack a usv_simulation_commond message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param stage  The stage of the task
 * @param command_velocity  Simulation command_velocity ranges -1(back)~1(forward)
 * @param command_turn  Simulation command_turn ranges -1(left)~1(right)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_simulation_commond_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t stage, float command_velocity, float command_turn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN];
    _mav_put_float(buf, 0, command_velocity);
    _mav_put_float(buf, 4, command_turn);
    _mav_put_uint8_t(buf, 8, stage);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN);
#else
    mavlink_usv_simulation_commond_t packet;
    packet.command_velocity = command_velocity;
    packet.command_turn = command_turn;
    packet.stage = stage;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_SIMULATION_COMMOND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_MIN_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_CRC);
}

/**
 * @brief Pack a usv_simulation_commond message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param stage  The stage of the task
 * @param command_velocity  Simulation command_velocity ranges -1(back)~1(forward)
 * @param command_turn  Simulation command_turn ranges -1(left)~1(right)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_simulation_commond_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t stage,float command_velocity,float command_turn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN];
    _mav_put_float(buf, 0, command_velocity);
    _mav_put_float(buf, 4, command_turn);
    _mav_put_uint8_t(buf, 8, stage);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN);
#else
    mavlink_usv_simulation_commond_t packet;
    packet.command_velocity = command_velocity;
    packet.command_turn = command_turn;
    packet.stage = stage;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_SIMULATION_COMMOND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_MIN_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_CRC);
}

/**
 * @brief Encode a usv_simulation_commond struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param usv_simulation_commond C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_simulation_commond_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_usv_simulation_commond_t* usv_simulation_commond)
{
    return mavlink_msg_usv_simulation_commond_pack(system_id, component_id, msg, usv_simulation_commond->stage, usv_simulation_commond->command_velocity, usv_simulation_commond->command_turn);
}

/**
 * @brief Encode a usv_simulation_commond struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usv_simulation_commond C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_simulation_commond_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_usv_simulation_commond_t* usv_simulation_commond)
{
    return mavlink_msg_usv_simulation_commond_pack_chan(system_id, component_id, chan, msg, usv_simulation_commond->stage, usv_simulation_commond->command_velocity, usv_simulation_commond->command_turn);
}

/**
 * @brief Send a usv_simulation_commond message
 * @param chan MAVLink channel to send the message
 *
 * @param stage  The stage of the task
 * @param command_velocity  Simulation command_velocity ranges -1(back)~1(forward)
 * @param command_turn  Simulation command_turn ranges -1(left)~1(right)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_usv_simulation_commond_send(mavlink_channel_t chan, uint8_t stage, float command_velocity, float command_turn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN];
    _mav_put_float(buf, 0, command_velocity);
    _mav_put_float(buf, 4, command_turn);
    _mav_put_uint8_t(buf, 8, stage);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND, buf, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_MIN_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_CRC);
#else
    mavlink_usv_simulation_commond_t packet;
    packet.command_velocity = command_velocity;
    packet.command_turn = command_turn;
    packet.stage = stage;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND, (const char *)&packet, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_MIN_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_CRC);
#endif
}

/**
 * @brief Send a usv_simulation_commond message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_usv_simulation_commond_send_struct(mavlink_channel_t chan, const mavlink_usv_simulation_commond_t* usv_simulation_commond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_usv_simulation_commond_send(chan, usv_simulation_commond->stage, usv_simulation_commond->command_velocity, usv_simulation_commond->command_turn);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND, (const char *)usv_simulation_commond, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_MIN_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_CRC);
#endif
}

#if MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_usv_simulation_commond_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t stage, float command_velocity, float command_turn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, command_velocity);
    _mav_put_float(buf, 4, command_turn);
    _mav_put_uint8_t(buf, 8, stage);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND, buf, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_MIN_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_CRC);
#else
    mavlink_usv_simulation_commond_t *packet = (mavlink_usv_simulation_commond_t *)msgbuf;
    packet->command_velocity = command_velocity;
    packet->command_turn = command_turn;
    packet->stage = stage;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND, (const char *)packet, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_MIN_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_CRC);
#endif
}
#endif

#endif

// MESSAGE USV_SIMULATION_COMMOND UNPACKING


/**
 * @brief Get field stage from usv_simulation_commond message
 *
 * @return  The stage of the task
 */
static inline uint8_t mavlink_msg_usv_simulation_commond_get_stage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field command_velocity from usv_simulation_commond message
 *
 * @return  Simulation command_velocity ranges -1(back)~1(forward)
 */
static inline float mavlink_msg_usv_simulation_commond_get_command_velocity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field command_turn from usv_simulation_commond message
 *
 * @return  Simulation command_turn ranges -1(left)~1(right)
 */
static inline float mavlink_msg_usv_simulation_commond_get_command_turn(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a usv_simulation_commond message into a struct
 *
 * @param msg The message to decode
 * @param usv_simulation_commond C-struct to decode the message contents into
 */
static inline void mavlink_msg_usv_simulation_commond_decode(const mavlink_message_t* msg, mavlink_usv_simulation_commond_t* usv_simulation_commond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    usv_simulation_commond->command_velocity = mavlink_msg_usv_simulation_commond_get_command_velocity(msg);
    usv_simulation_commond->command_turn = mavlink_msg_usv_simulation_commond_get_command_turn(msg);
    usv_simulation_commond->stage = mavlink_msg_usv_simulation_commond_get_stage(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN? msg->len : MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN;
        memset(usv_simulation_commond, 0, MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_LEN);
    memcpy(usv_simulation_commond, _MAV_PAYLOAD(msg), len);
#endif
}
