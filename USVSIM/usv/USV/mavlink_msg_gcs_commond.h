#pragma once
// MESSAGE GCS_COMMOND PACKING

#define MAVLINK_MSG_ID_GCS_COMMOND 151

MAVPACKED(
typedef struct __mavlink_gcs_commond_t {
 float P; /*<  PID controller parameter*/
 float I; /*<  PID controller parameter*/
 float D; /*<  PID controller parameter*/
 uint8_t Stop_flag; /*<  1-run,0-stop*/
}) mavlink_gcs_commond_t;

#define MAVLINK_MSG_ID_GCS_COMMOND_LEN 13
#define MAVLINK_MSG_ID_GCS_COMMOND_MIN_LEN 13
#define MAVLINK_MSG_ID_151_LEN 13
#define MAVLINK_MSG_ID_151_MIN_LEN 13

#define MAVLINK_MSG_ID_GCS_COMMOND_CRC 62
#define MAVLINK_MSG_ID_151_CRC 62



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GCS_COMMOND { \
    151, \
    "GCS_COMMOND", \
    4, \
    {  { "P", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gcs_commond_t, P) }, \
         { "I", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gcs_commond_t, I) }, \
         { "D", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gcs_commond_t, D) }, \
         { "Stop_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_gcs_commond_t, Stop_flag) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GCS_COMMOND { \
    "GCS_COMMOND", \
    4, \
    {  { "P", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gcs_commond_t, P) }, \
         { "I", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gcs_commond_t, I) }, \
         { "D", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gcs_commond_t, D) }, \
         { "Stop_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_gcs_commond_t, Stop_flag) }, \
         } \
}
#endif

/**
 * @brief Pack a gcs_commond message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param P  PID controller parameter
 * @param I  PID controller parameter
 * @param D  PID controller parameter
 * @param Stop_flag  1-run,0-stop
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_commond_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float P, float I, float D, uint8_t Stop_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_COMMOND_LEN];
    _mav_put_float(buf, 0, P);
    _mav_put_float(buf, 4, I);
    _mav_put_float(buf, 8, D);
    _mav_put_uint8_t(buf, 12, Stop_flag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_COMMOND_LEN);
#else
    mavlink_gcs_commond_t packet;
    packet.P = P;
    packet.I = I;
    packet.D = D;
    packet.Stop_flag = Stop_flag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_COMMOND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_COMMOND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GCS_COMMOND_MIN_LEN, MAVLINK_MSG_ID_GCS_COMMOND_LEN, MAVLINK_MSG_ID_GCS_COMMOND_CRC);
}

/**
 * @brief Pack a gcs_commond message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param P  PID controller parameter
 * @param I  PID controller parameter
 * @param D  PID controller parameter
 * @param Stop_flag  1-run,0-stop
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_commond_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float P,float I,float D,uint8_t Stop_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_COMMOND_LEN];
    _mav_put_float(buf, 0, P);
    _mav_put_float(buf, 4, I);
    _mav_put_float(buf, 8, D);
    _mav_put_uint8_t(buf, 12, Stop_flag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_COMMOND_LEN);
#else
    mavlink_gcs_commond_t packet;
    packet.P = P;
    packet.I = I;
    packet.D = D;
    packet.Stop_flag = Stop_flag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_COMMOND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_COMMOND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GCS_COMMOND_MIN_LEN, MAVLINK_MSG_ID_GCS_COMMOND_LEN, MAVLINK_MSG_ID_GCS_COMMOND_CRC);
}

/**
 * @brief Encode a gcs_commond struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gcs_commond C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_commond_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gcs_commond_t* gcs_commond)
{
    return mavlink_msg_gcs_commond_pack(system_id, component_id, msg, gcs_commond->P, gcs_commond->I, gcs_commond->D, gcs_commond->Stop_flag);
}

/**
 * @brief Encode a gcs_commond struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gcs_commond C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_commond_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gcs_commond_t* gcs_commond)
{
    return mavlink_msg_gcs_commond_pack_chan(system_id, component_id, chan, msg, gcs_commond->P, gcs_commond->I, gcs_commond->D, gcs_commond->Stop_flag);
}

/**
 * @brief Send a gcs_commond message
 * @param chan MAVLink channel to send the message
 *
 * @param P  PID controller parameter
 * @param I  PID controller parameter
 * @param D  PID controller parameter
 * @param Stop_flag  1-run,0-stop
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gcs_commond_send(mavlink_channel_t chan, float P, float I, float D, uint8_t Stop_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_COMMOND_LEN];
    _mav_put_float(buf, 0, P);
    _mav_put_float(buf, 4, I);
    _mav_put_float(buf, 8, D);
    _mav_put_uint8_t(buf, 12, Stop_flag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_COMMOND, buf, MAVLINK_MSG_ID_GCS_COMMOND_MIN_LEN, MAVLINK_MSG_ID_GCS_COMMOND_LEN, MAVLINK_MSG_ID_GCS_COMMOND_CRC);
#else
    mavlink_gcs_commond_t packet;
    packet.P = P;
    packet.I = I;
    packet.D = D;
    packet.Stop_flag = Stop_flag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_COMMOND, (const char *)&packet, MAVLINK_MSG_ID_GCS_COMMOND_MIN_LEN, MAVLINK_MSG_ID_GCS_COMMOND_LEN, MAVLINK_MSG_ID_GCS_COMMOND_CRC);
#endif
}

/**
 * @brief Send a gcs_commond message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gcs_commond_send_struct(mavlink_channel_t chan, const mavlink_gcs_commond_t* gcs_commond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gcs_commond_send(chan, gcs_commond->P, gcs_commond->I, gcs_commond->D, gcs_commond->Stop_flag);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_COMMOND, (const char *)gcs_commond, MAVLINK_MSG_ID_GCS_COMMOND_MIN_LEN, MAVLINK_MSG_ID_GCS_COMMOND_LEN, MAVLINK_MSG_ID_GCS_COMMOND_CRC);
#endif
}

#if MAVLINK_MSG_ID_GCS_COMMOND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gcs_commond_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float P, float I, float D, uint8_t Stop_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, P);
    _mav_put_float(buf, 4, I);
    _mav_put_float(buf, 8, D);
    _mav_put_uint8_t(buf, 12, Stop_flag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_COMMOND, buf, MAVLINK_MSG_ID_GCS_COMMOND_MIN_LEN, MAVLINK_MSG_ID_GCS_COMMOND_LEN, MAVLINK_MSG_ID_GCS_COMMOND_CRC);
#else
    mavlink_gcs_commond_t *packet = (mavlink_gcs_commond_t *)msgbuf;
    packet->P = P;
    packet->I = I;
    packet->D = D;
    packet->Stop_flag = Stop_flag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_COMMOND, (const char *)packet, MAVLINK_MSG_ID_GCS_COMMOND_MIN_LEN, MAVLINK_MSG_ID_GCS_COMMOND_LEN, MAVLINK_MSG_ID_GCS_COMMOND_CRC);
#endif
}
#endif

#endif

// MESSAGE GCS_COMMOND UNPACKING


/**
 * @brief Get field P from gcs_commond message
 *
 * @return  PID controller parameter
 */
static inline float mavlink_msg_gcs_commond_get_P(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field I from gcs_commond message
 *
 * @return  PID controller parameter
 */
static inline float mavlink_msg_gcs_commond_get_I(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field D from gcs_commond message
 *
 * @return  PID controller parameter
 */
static inline float mavlink_msg_gcs_commond_get_D(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field Stop_flag from gcs_commond message
 *
 * @return  1-run,0-stop
 */
static inline uint8_t mavlink_msg_gcs_commond_get_Stop_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Decode a gcs_commond message into a struct
 *
 * @param msg The message to decode
 * @param gcs_commond C-struct to decode the message contents into
 */
static inline void mavlink_msg_gcs_commond_decode(const mavlink_message_t* msg, mavlink_gcs_commond_t* gcs_commond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gcs_commond->P = mavlink_msg_gcs_commond_get_P(msg);
    gcs_commond->I = mavlink_msg_gcs_commond_get_I(msg);
    gcs_commond->D = mavlink_msg_gcs_commond_get_D(msg);
    gcs_commond->Stop_flag = mavlink_msg_gcs_commond_get_Stop_flag(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GCS_COMMOND_LEN? msg->len : MAVLINK_MSG_ID_GCS_COMMOND_LEN;
        memset(gcs_commond, 0, MAVLINK_MSG_ID_GCS_COMMOND_LEN);
    memcpy(gcs_commond, _MAV_PAYLOAD(msg), len);
#endif
}
