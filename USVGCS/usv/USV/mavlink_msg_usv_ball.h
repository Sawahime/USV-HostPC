#pragma once
// MESSAGE USV_BALL PACKING

#define MAVLINK_MSG_ID_USV_BALL 152

MAVPACKED(
typedef struct __mavlink_usv_ball_t {
 int32_t ball_lat; /*< [degE7] Latitude (WGS84 ellipsoid) of ball*/
 int32_t ball_lon; /*< [degE7] Longitude (WGS84 ellipsoid) of ball*/
 uint8_t ball_id; /*<  Id of ball*/
 uint8_t ball_color; /*<  Color of Ball: 0(red); 1(blue); 2(yellow);3(green); 4(black)*/
}) mavlink_usv_ball_t;

#define MAVLINK_MSG_ID_USV_BALL_LEN 10
#define MAVLINK_MSG_ID_USV_BALL_MIN_LEN 10
#define MAVLINK_MSG_ID_152_LEN 10
#define MAVLINK_MSG_ID_152_MIN_LEN 10

#define MAVLINK_MSG_ID_USV_BALL_CRC 43
#define MAVLINK_MSG_ID_152_CRC 43



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_USV_BALL { \
    152, \
    "USV_BALL", \
    4, \
    {  { "ball_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_usv_ball_t, ball_id) }, \
         { "ball_color", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_usv_ball_t, ball_color) }, \
         { "ball_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_usv_ball_t, ball_lat) }, \
         { "ball_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_usv_ball_t, ball_lon) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_USV_BALL { \
    "USV_BALL", \
    4, \
    {  { "ball_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_usv_ball_t, ball_id) }, \
         { "ball_color", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_usv_ball_t, ball_color) }, \
         { "ball_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_usv_ball_t, ball_lat) }, \
         { "ball_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_usv_ball_t, ball_lon) }, \
         } \
}
#endif

/**
 * @brief Pack a usv_ball message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ball_id  Id of ball
 * @param ball_color  Color of Ball: 0(red); 1(blue); 2(yellow);3(green); 4(black)
 * @param ball_lat [degE7] Latitude (WGS84 ellipsoid) of ball
 * @param ball_lon [degE7] Longitude (WGS84 ellipsoid) of ball
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_ball_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ball_id, uint8_t ball_color, int32_t ball_lat, int32_t ball_lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_BALL_LEN];
    _mav_put_int32_t(buf, 0, ball_lat);
    _mav_put_int32_t(buf, 4, ball_lon);
    _mav_put_uint8_t(buf, 8, ball_id);
    _mav_put_uint8_t(buf, 9, ball_color);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_BALL_LEN);
#else
    mavlink_usv_ball_t packet;
    packet.ball_lat = ball_lat;
    packet.ball_lon = ball_lon;
    packet.ball_id = ball_id;
    packet.ball_color = ball_color;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_BALL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_BALL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_USV_BALL_MIN_LEN, MAVLINK_MSG_ID_USV_BALL_LEN, MAVLINK_MSG_ID_USV_BALL_CRC);
}

/**
 * @brief Pack a usv_ball message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ball_id  Id of ball
 * @param ball_color  Color of Ball: 0(red); 1(blue); 2(yellow);3(green); 4(black)
 * @param ball_lat [degE7] Latitude (WGS84 ellipsoid) of ball
 * @param ball_lon [degE7] Longitude (WGS84 ellipsoid) of ball
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_ball_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ball_id,uint8_t ball_color,int32_t ball_lat,int32_t ball_lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_BALL_LEN];
    _mav_put_int32_t(buf, 0, ball_lat);
    _mav_put_int32_t(buf, 4, ball_lon);
    _mav_put_uint8_t(buf, 8, ball_id);
    _mav_put_uint8_t(buf, 9, ball_color);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_BALL_LEN);
#else
    mavlink_usv_ball_t packet;
    packet.ball_lat = ball_lat;
    packet.ball_lon = ball_lon;
    packet.ball_id = ball_id;
    packet.ball_color = ball_color;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_BALL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_BALL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_USV_BALL_MIN_LEN, MAVLINK_MSG_ID_USV_BALL_LEN, MAVLINK_MSG_ID_USV_BALL_CRC);
}

/**
 * @brief Encode a usv_ball struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param usv_ball C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_ball_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_usv_ball_t* usv_ball)
{
    return mavlink_msg_usv_ball_pack(system_id, component_id, msg, usv_ball->ball_id, usv_ball->ball_color, usv_ball->ball_lat, usv_ball->ball_lon);
}

/**
 * @brief Encode a usv_ball struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usv_ball C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_ball_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_usv_ball_t* usv_ball)
{
    return mavlink_msg_usv_ball_pack_chan(system_id, component_id, chan, msg, usv_ball->ball_id, usv_ball->ball_color, usv_ball->ball_lat, usv_ball->ball_lon);
}

/**
 * @brief Send a usv_ball message
 * @param chan MAVLink channel to send the message
 *
 * @param ball_id  Id of ball
 * @param ball_color  Color of Ball: 0(red); 1(blue); 2(yellow);3(green); 4(black)
 * @param ball_lat [degE7] Latitude (WGS84 ellipsoid) of ball
 * @param ball_lon [degE7] Longitude (WGS84 ellipsoid) of ball
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_usv_ball_send(mavlink_channel_t chan, uint8_t ball_id, uint8_t ball_color, int32_t ball_lat, int32_t ball_lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_BALL_LEN];
    _mav_put_int32_t(buf, 0, ball_lat);
    _mav_put_int32_t(buf, 4, ball_lon);
    _mav_put_uint8_t(buf, 8, ball_id);
    _mav_put_uint8_t(buf, 9, ball_color);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_BALL, buf, MAVLINK_MSG_ID_USV_BALL_MIN_LEN, MAVLINK_MSG_ID_USV_BALL_LEN, MAVLINK_MSG_ID_USV_BALL_CRC);
#else
    mavlink_usv_ball_t packet;
    packet.ball_lat = ball_lat;
    packet.ball_lon = ball_lon;
    packet.ball_id = ball_id;
    packet.ball_color = ball_color;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_BALL, (const char *)&packet, MAVLINK_MSG_ID_USV_BALL_MIN_LEN, MAVLINK_MSG_ID_USV_BALL_LEN, MAVLINK_MSG_ID_USV_BALL_CRC);
#endif
}

/**
 * @brief Send a usv_ball message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_usv_ball_send_struct(mavlink_channel_t chan, const mavlink_usv_ball_t* usv_ball)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_usv_ball_send(chan, usv_ball->ball_id, usv_ball->ball_color, usv_ball->ball_lat, usv_ball->ball_lon);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_BALL, (const char *)usv_ball, MAVLINK_MSG_ID_USV_BALL_MIN_LEN, MAVLINK_MSG_ID_USV_BALL_LEN, MAVLINK_MSG_ID_USV_BALL_CRC);
#endif
}

#if MAVLINK_MSG_ID_USV_BALL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_usv_ball_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ball_id, uint8_t ball_color, int32_t ball_lat, int32_t ball_lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, ball_lat);
    _mav_put_int32_t(buf, 4, ball_lon);
    _mav_put_uint8_t(buf, 8, ball_id);
    _mav_put_uint8_t(buf, 9, ball_color);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_BALL, buf, MAVLINK_MSG_ID_USV_BALL_MIN_LEN, MAVLINK_MSG_ID_USV_BALL_LEN, MAVLINK_MSG_ID_USV_BALL_CRC);
#else
    mavlink_usv_ball_t *packet = (mavlink_usv_ball_t *)msgbuf;
    packet->ball_lat = ball_lat;
    packet->ball_lon = ball_lon;
    packet->ball_id = ball_id;
    packet->ball_color = ball_color;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_BALL, (const char *)packet, MAVLINK_MSG_ID_USV_BALL_MIN_LEN, MAVLINK_MSG_ID_USV_BALL_LEN, MAVLINK_MSG_ID_USV_BALL_CRC);
#endif
}
#endif

#endif

// MESSAGE USV_BALL UNPACKING


/**
 * @brief Get field ball_id from usv_ball message
 *
 * @return  Id of ball
 */
static inline uint8_t mavlink_msg_usv_ball_get_ball_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field ball_color from usv_ball message
 *
 * @return  Color of Ball: 0(red); 1(blue); 2(yellow);3(green); 4(black)
 */
static inline uint8_t mavlink_msg_usv_ball_get_ball_color(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field ball_lat from usv_ball message
 *
 * @return [degE7] Latitude (WGS84 ellipsoid) of ball
 */
static inline int32_t mavlink_msg_usv_ball_get_ball_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field ball_lon from usv_ball message
 *
 * @return [degE7] Longitude (WGS84 ellipsoid) of ball
 */
static inline int32_t mavlink_msg_usv_ball_get_ball_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Decode a usv_ball message into a struct
 *
 * @param msg The message to decode
 * @param usv_ball C-struct to decode the message contents into
 */
static inline void mavlink_msg_usv_ball_decode(const mavlink_message_t* msg, mavlink_usv_ball_t* usv_ball)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    usv_ball->ball_lat = mavlink_msg_usv_ball_get_ball_lat(msg);
    usv_ball->ball_lon = mavlink_msg_usv_ball_get_ball_lon(msg);
    usv_ball->ball_id = mavlink_msg_usv_ball_get_ball_id(msg);
    usv_ball->ball_color = mavlink_msg_usv_ball_get_ball_color(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_USV_BALL_LEN? msg->len : MAVLINK_MSG_ID_USV_BALL_LEN;
        memset(usv_ball, 0, MAVLINK_MSG_ID_USV_BALL_LEN);
    memcpy(usv_ball, _MAV_PAYLOAD(msg), len);
#endif
}
