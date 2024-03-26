#pragma once
// MESSAGE USV_STATUS PACKING

#define MAVLINK_MSG_ID_USV_STATUS 150

MAVPACKED(
typedef struct __mavlink_usv_status_t {
 float x; /*< [m] The north distance to origin point*/
 float y; /*< [m] The east distance to origin point*/
 int32_t lat; /*< [degE7] Latitude (WGS84 ellipsoid)*/
 int32_t lon; /*< [degE7] Longitude (WGS84 ellipsoid)*/
 float course; /*< [deg] The course of USV*/
 float velocity; /*< [m/s] The velocity of USV*/
 float command_velocity; /*<  Command_velocity ranges -1(back)~1(forward)*/
 float command_turn; /*<  Command_turn ranges -1(left)~1(right)*/
 uint8_t stage; /*<  The stage of the task*/
}) mavlink_usv_status_t;

#define MAVLINK_MSG_ID_USV_STATUS_LEN 33
#define MAVLINK_MSG_ID_USV_STATUS_MIN_LEN 33
#define MAVLINK_MSG_ID_150_LEN 33
#define MAVLINK_MSG_ID_150_MIN_LEN 33

#define MAVLINK_MSG_ID_USV_STATUS_CRC 9
#define MAVLINK_MSG_ID_150_CRC 9



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_USV_STATUS { \
    150, \
    "USV_STATUS", \
    9, \
    {  { "stage", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_usv_status_t, stage) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_usv_status_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_usv_status_t, y) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_usv_status_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_usv_status_t, lon) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_usv_status_t, course) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_usv_status_t, velocity) }, \
         { "command_velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_usv_status_t, command_velocity) }, \
         { "command_turn", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_usv_status_t, command_turn) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_USV_STATUS { \
    "USV_STATUS", \
    9, \
    {  { "stage", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_usv_status_t, stage) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_usv_status_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_usv_status_t, y) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_usv_status_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_usv_status_t, lon) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_usv_status_t, course) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_usv_status_t, velocity) }, \
         { "command_velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_usv_status_t, command_velocity) }, \
         { "command_turn", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_usv_status_t, command_turn) }, \
         } \
}
#endif

/**
 * @brief Pack a usv_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param stage  The stage of the task
 * @param x [m] The north distance to origin point
 * @param y [m] The east distance to origin point
 * @param lat [degE7] Latitude (WGS84 ellipsoid)
 * @param lon [degE7] Longitude (WGS84 ellipsoid)
 * @param course [deg] The course of USV
 * @param velocity [m/s] The velocity of USV
 * @param command_velocity  Command_velocity ranges -1(back)~1(forward)
 * @param command_turn  Command_turn ranges -1(left)~1(right)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t stage, float x, float y, int32_t lat, int32_t lon, float course, float velocity, float command_velocity, float command_turn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_STATUS_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, course);
    _mav_put_float(buf, 20, velocity);
    _mav_put_float(buf, 24, command_velocity);
    _mav_put_float(buf, 28, command_turn);
    _mav_put_uint8_t(buf, 32, stage);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_STATUS_LEN);
#else
    mavlink_usv_status_t packet;
    packet.x = x;
    packet.y = y;
    packet.lat = lat;
    packet.lon = lon;
    packet.course = course;
    packet.velocity = velocity;
    packet.command_velocity = command_velocity;
    packet.command_turn = command_turn;
    packet.stage = stage;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_USV_STATUS_MIN_LEN, MAVLINK_MSG_ID_USV_STATUS_LEN, MAVLINK_MSG_ID_USV_STATUS_CRC);
}

/**
 * @brief Pack a usv_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param stage  The stage of the task
 * @param x [m] The north distance to origin point
 * @param y [m] The east distance to origin point
 * @param lat [degE7] Latitude (WGS84 ellipsoid)
 * @param lon [degE7] Longitude (WGS84 ellipsoid)
 * @param course [deg] The course of USV
 * @param velocity [m/s] The velocity of USV
 * @param command_velocity  Command_velocity ranges -1(back)~1(forward)
 * @param command_turn  Command_turn ranges -1(left)~1(right)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t stage,float x,float y,int32_t lat,int32_t lon,float course,float velocity,float command_velocity,float command_turn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_STATUS_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, course);
    _mav_put_float(buf, 20, velocity);
    _mav_put_float(buf, 24, command_velocity);
    _mav_put_float(buf, 28, command_turn);
    _mav_put_uint8_t(buf, 32, stage);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_STATUS_LEN);
#else
    mavlink_usv_status_t packet;
    packet.x = x;
    packet.y = y;
    packet.lat = lat;
    packet.lon = lon;
    packet.course = course;
    packet.velocity = velocity;
    packet.command_velocity = command_velocity;
    packet.command_turn = command_turn;
    packet.stage = stage;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_USV_STATUS_MIN_LEN, MAVLINK_MSG_ID_USV_STATUS_LEN, MAVLINK_MSG_ID_USV_STATUS_CRC);
}

/**
 * @brief Encode a usv_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param usv_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_usv_status_t* usv_status)
{
    return mavlink_msg_usv_status_pack(system_id, component_id, msg, usv_status->stage, usv_status->x, usv_status->y, usv_status->lat, usv_status->lon, usv_status->course, usv_status->velocity, usv_status->command_velocity, usv_status->command_turn);
}

/**
 * @brief Encode a usv_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usv_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_usv_status_t* usv_status)
{
    return mavlink_msg_usv_status_pack_chan(system_id, component_id, chan, msg, usv_status->stage, usv_status->x, usv_status->y, usv_status->lat, usv_status->lon, usv_status->course, usv_status->velocity, usv_status->command_velocity, usv_status->command_turn);
}

/**
 * @brief Send a usv_status message
 * @param chan MAVLink channel to send the message
 *
 * @param stage  The stage of the task
 * @param x [m] The north distance to origin point
 * @param y [m] The east distance to origin point
 * @param lat [degE7] Latitude (WGS84 ellipsoid)
 * @param lon [degE7] Longitude (WGS84 ellipsoid)
 * @param course [deg] The course of USV
 * @param velocity [m/s] The velocity of USV
 * @param command_velocity  Command_velocity ranges -1(back)~1(forward)
 * @param command_turn  Command_turn ranges -1(left)~1(right)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_usv_status_send(mavlink_channel_t chan, uint8_t stage, float x, float y, int32_t lat, int32_t lon, float course, float velocity, float command_velocity, float command_turn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_STATUS_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, course);
    _mav_put_float(buf, 20, velocity);
    _mav_put_float(buf, 24, command_velocity);
    _mav_put_float(buf, 28, command_turn);
    _mav_put_uint8_t(buf, 32, stage);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATUS, buf, MAVLINK_MSG_ID_USV_STATUS_MIN_LEN, MAVLINK_MSG_ID_USV_STATUS_LEN, MAVLINK_MSG_ID_USV_STATUS_CRC);
#else
    mavlink_usv_status_t packet;
    packet.x = x;
    packet.y = y;
    packet.lat = lat;
    packet.lon = lon;
    packet.course = course;
    packet.velocity = velocity;
    packet.command_velocity = command_velocity;
    packet.command_turn = command_turn;
    packet.stage = stage;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATUS, (const char *)&packet, MAVLINK_MSG_ID_USV_STATUS_MIN_LEN, MAVLINK_MSG_ID_USV_STATUS_LEN, MAVLINK_MSG_ID_USV_STATUS_CRC);
#endif
}

/**
 * @brief Send a usv_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_usv_status_send_struct(mavlink_channel_t chan, const mavlink_usv_status_t* usv_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_usv_status_send(chan, usv_status->stage, usv_status->x, usv_status->y, usv_status->lat, usv_status->lon, usv_status->course, usv_status->velocity, usv_status->command_velocity, usv_status->command_turn);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATUS, (const char *)usv_status, MAVLINK_MSG_ID_USV_STATUS_MIN_LEN, MAVLINK_MSG_ID_USV_STATUS_LEN, MAVLINK_MSG_ID_USV_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_USV_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_usv_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t stage, float x, float y, int32_t lat, int32_t lon, float course, float velocity, float command_velocity, float command_turn)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, course);
    _mav_put_float(buf, 20, velocity);
    _mav_put_float(buf, 24, command_velocity);
    _mav_put_float(buf, 28, command_turn);
    _mav_put_uint8_t(buf, 32, stage);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATUS, buf, MAVLINK_MSG_ID_USV_STATUS_MIN_LEN, MAVLINK_MSG_ID_USV_STATUS_LEN, MAVLINK_MSG_ID_USV_STATUS_CRC);
#else
    mavlink_usv_status_t *packet = (mavlink_usv_status_t *)msgbuf;
    packet->x = x;
    packet->y = y;
    packet->lat = lat;
    packet->lon = lon;
    packet->course = course;
    packet->velocity = velocity;
    packet->command_velocity = command_velocity;
    packet->command_turn = command_turn;
    packet->stage = stage;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_STATUS, (const char *)packet, MAVLINK_MSG_ID_USV_STATUS_MIN_LEN, MAVLINK_MSG_ID_USV_STATUS_LEN, MAVLINK_MSG_ID_USV_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE USV_STATUS UNPACKING


/**
 * @brief Get field stage from usv_status message
 *
 * @return  The stage of the task
 */
static inline uint8_t mavlink_msg_usv_status_get_stage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field x from usv_status message
 *
 * @return [m] The north distance to origin point
 */
static inline float mavlink_msg_usv_status_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y from usv_status message
 *
 * @return [m] The east distance to origin point
 */
static inline float mavlink_msg_usv_status_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field lat from usv_status message
 *
 * @return [degE7] Latitude (WGS84 ellipsoid)
 */
static inline int32_t mavlink_msg_usv_status_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field lon from usv_status message
 *
 * @return [degE7] Longitude (WGS84 ellipsoid)
 */
static inline int32_t mavlink_msg_usv_status_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field course from usv_status message
 *
 * @return [deg] The course of USV
 */
static inline float mavlink_msg_usv_status_get_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field velocity from usv_status message
 *
 * @return [m/s] The velocity of USV
 */
static inline float mavlink_msg_usv_status_get_velocity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field command_velocity from usv_status message
 *
 * @return  Command_velocity ranges -1(back)~1(forward)
 */
static inline float mavlink_msg_usv_status_get_command_velocity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field command_turn from usv_status message
 *
 * @return  Command_turn ranges -1(left)~1(right)
 */
static inline float mavlink_msg_usv_status_get_command_turn(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Decode a usv_status message into a struct
 *
 * @param msg The message to decode
 * @param usv_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_usv_status_decode(const mavlink_message_t* msg, mavlink_usv_status_t* usv_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    usv_status->x = mavlink_msg_usv_status_get_x(msg);
    usv_status->y = mavlink_msg_usv_status_get_y(msg);
    usv_status->lat = mavlink_msg_usv_status_get_lat(msg);
    usv_status->lon = mavlink_msg_usv_status_get_lon(msg);
    usv_status->course = mavlink_msg_usv_status_get_course(msg);
    usv_status->velocity = mavlink_msg_usv_status_get_velocity(msg);
    usv_status->command_velocity = mavlink_msg_usv_status_get_command_velocity(msg);
    usv_status->command_turn = mavlink_msg_usv_status_get_command_turn(msg);
    usv_status->stage = mavlink_msg_usv_status_get_stage(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_USV_STATUS_LEN? msg->len : MAVLINK_MSG_ID_USV_STATUS_LEN;
        memset(usv_status, 0, MAVLINK_MSG_ID_USV_STATUS_LEN);
    memcpy(usv_status, _MAV_PAYLOAD(msg), len);
#endif
}
