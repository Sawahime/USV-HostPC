#pragma once
// MESSAGE GCS_SIMULATION_STATUS PACKING

#define MAVLINK_MSG_ID_GCS_SIMULATION_STATUS 153

MAVPACKED(
typedef struct __mavlink_gcs_simulation_status_t {
 int32_t ball_lat; /*< [degE7] Simulation latitude (WGS84 ellipsoid) of USV*/
 int32_t ball_lon; /*< [degE7] Simulation longitude (WGS84 ellipsoid) of USV*/
 float course; /*< [deg] Simulation  course of USV*/
}) mavlink_gcs_simulation_status_t;

#define MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN 12
#define MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_MIN_LEN 12
#define MAVLINK_MSG_ID_153_LEN 12
#define MAVLINK_MSG_ID_153_MIN_LEN 12

#define MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_CRC 99
#define MAVLINK_MSG_ID_153_CRC 99



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GCS_SIMULATION_STATUS { \
    153, \
    "GCS_SIMULATION_STATUS", \
    3, \
    {  { "ball_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gcs_simulation_status_t, ball_lat) }, \
         { "ball_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gcs_simulation_status_t, ball_lon) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gcs_simulation_status_t, course) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GCS_SIMULATION_STATUS { \
    "GCS_SIMULATION_STATUS", \
    3, \
    {  { "ball_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gcs_simulation_status_t, ball_lat) }, \
         { "ball_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gcs_simulation_status_t, ball_lon) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gcs_simulation_status_t, course) }, \
         } \
}
#endif

/**
 * @brief Pack a gcs_simulation_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ball_lat [degE7] Simulation latitude (WGS84 ellipsoid) of USV
 * @param ball_lon [degE7] Simulation longitude (WGS84 ellipsoid) of USV
 * @param course [deg] Simulation  course of USV
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_simulation_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t ball_lat, int32_t ball_lon, float course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN];
    _mav_put_int32_t(buf, 0, ball_lat);
    _mav_put_int32_t(buf, 4, ball_lon);
    _mav_put_float(buf, 8, course);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN);
#else
    mavlink_gcs_simulation_status_t packet;
    packet.ball_lat = ball_lat;
    packet.ball_lon = ball_lon;
    packet.course = course;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SIMULATION_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_CRC);
}

/**
 * @brief Pack a gcs_simulation_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ball_lat [degE7] Simulation latitude (WGS84 ellipsoid) of USV
 * @param ball_lon [degE7] Simulation longitude (WGS84 ellipsoid) of USV
 * @param course [deg] Simulation  course of USV
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gcs_simulation_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t ball_lat,int32_t ball_lon,float course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN];
    _mav_put_int32_t(buf, 0, ball_lat);
    _mav_put_int32_t(buf, 4, ball_lon);
    _mav_put_float(buf, 8, course);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN);
#else
    mavlink_gcs_simulation_status_t packet;
    packet.ball_lat = ball_lat;
    packet.ball_lon = ball_lon;
    packet.course = course;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GCS_SIMULATION_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_CRC);
}

/**
 * @brief Encode a gcs_simulation_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gcs_simulation_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_simulation_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gcs_simulation_status_t* gcs_simulation_status)
{
    return mavlink_msg_gcs_simulation_status_pack(system_id, component_id, msg, gcs_simulation_status->ball_lat, gcs_simulation_status->ball_lon, gcs_simulation_status->course);
}

/**
 * @brief Encode a gcs_simulation_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gcs_simulation_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gcs_simulation_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gcs_simulation_status_t* gcs_simulation_status)
{
    return mavlink_msg_gcs_simulation_status_pack_chan(system_id, component_id, chan, msg, gcs_simulation_status->ball_lat, gcs_simulation_status->ball_lon, gcs_simulation_status->course);
}

/**
 * @brief Send a gcs_simulation_status message
 * @param chan MAVLink channel to send the message
 *
 * @param ball_lat [degE7] Simulation latitude (WGS84 ellipsoid) of USV
 * @param ball_lon [degE7] Simulation longitude (WGS84 ellipsoid) of USV
 * @param course [deg] Simulation  course of USV
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gcs_simulation_status_send(mavlink_channel_t chan, int32_t ball_lat, int32_t ball_lon, float course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN];
    _mav_put_int32_t(buf, 0, ball_lat);
    _mav_put_int32_t(buf, 4, ball_lon);
    _mav_put_float(buf, 8, course);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS, buf, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_CRC);
#else
    mavlink_gcs_simulation_status_t packet;
    packet.ball_lat = ball_lat;
    packet.ball_lon = ball_lon;
    packet.course = course;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS, (const char *)&packet, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_CRC);
#endif
}

/**
 * @brief Send a gcs_simulation_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gcs_simulation_status_send_struct(mavlink_channel_t chan, const mavlink_gcs_simulation_status_t* gcs_simulation_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gcs_simulation_status_send(chan, gcs_simulation_status->ball_lat, gcs_simulation_status->ball_lon, gcs_simulation_status->course);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS, (const char *)gcs_simulation_status, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gcs_simulation_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t ball_lat, int32_t ball_lon, float course)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, ball_lat);
    _mav_put_int32_t(buf, 4, ball_lon);
    _mav_put_float(buf, 8, course);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS, buf, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_CRC);
#else
    mavlink_gcs_simulation_status_t *packet = (mavlink_gcs_simulation_status_t *)msgbuf;
    packet->ball_lat = ball_lat;
    packet->ball_lon = ball_lon;
    packet->course = course;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS, (const char *)packet, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE GCS_SIMULATION_STATUS UNPACKING


/**
 * @brief Get field ball_lat from gcs_simulation_status message
 *
 * @return [degE7] Simulation latitude (WGS84 ellipsoid) of USV
 */
static inline int32_t mavlink_msg_gcs_simulation_status_get_ball_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field ball_lon from gcs_simulation_status message
 *
 * @return [degE7] Simulation longitude (WGS84 ellipsoid) of USV
 */
static inline int32_t mavlink_msg_gcs_simulation_status_get_ball_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field course from gcs_simulation_status message
 *
 * @return [deg] Simulation  course of USV
 */
static inline float mavlink_msg_gcs_simulation_status_get_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a gcs_simulation_status message into a struct
 *
 * @param msg The message to decode
 * @param gcs_simulation_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_gcs_simulation_status_decode(const mavlink_message_t* msg, mavlink_gcs_simulation_status_t* gcs_simulation_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gcs_simulation_status->ball_lat = mavlink_msg_gcs_simulation_status_get_ball_lat(msg);
    gcs_simulation_status->ball_lon = mavlink_msg_gcs_simulation_status_get_ball_lon(msg);
    gcs_simulation_status->course = mavlink_msg_gcs_simulation_status_get_course(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN? msg->len : MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN;
        memset(gcs_simulation_status, 0, MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_LEN);
    memcpy(gcs_simulation_status, _MAV_PAYLOAD(msg), len);
#endif
}
