#pragma once
// MESSAGE SENSORS PACKING

#define MAVLINK_MSG_ID_SENSORS 1


typedef struct __mavlink_sensors_t {
 uint16_t angles[8]; /*< */
 uint16_t rpms[4]; /*< */
} mavlink_sensors_t;

#define MAVLINK_MSG_ID_SENSORS_LEN 24
#define MAVLINK_MSG_ID_SENSORS_MIN_LEN 24
#define MAVLINK_MSG_ID_1_LEN 24
#define MAVLINK_MSG_ID_1_MIN_LEN 24

#define MAVLINK_MSG_ID_SENSORS_CRC 152
#define MAVLINK_MSG_ID_1_CRC 152

#define MAVLINK_MSG_SENSORS_FIELD_ANGLES_LEN 8
#define MAVLINK_MSG_SENSORS_FIELD_RPMS_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSORS { \
    1, \
    "SENSORS", \
    2, \
    {  { "angles", NULL, MAVLINK_TYPE_UINT16_T, 8, 0, offsetof(mavlink_sensors_t, angles) }, \
         { "rpms", NULL, MAVLINK_TYPE_UINT16_T, 4, 16, offsetof(mavlink_sensors_t, rpms) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSORS { \
    "SENSORS", \
    2, \
    {  { "angles", NULL, MAVLINK_TYPE_UINT16_T, 8, 0, offsetof(mavlink_sensors_t, angles) }, \
         { "rpms", NULL, MAVLINK_TYPE_UINT16_T, 4, 16, offsetof(mavlink_sensors_t, rpms) }, \
         } \
}
#endif

/**
 * @brief Pack a sensors message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param angles 
 * @param rpms 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensors_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint16_t *angles, const uint16_t *rpms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSORS_LEN];

    _mav_put_uint16_t_array(buf, 0, angles, 8);
    _mav_put_uint16_t_array(buf, 16, rpms, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSORS_LEN);
#else
    mavlink_sensors_t packet;

    mav_array_memcpy(packet.angles, angles, sizeof(uint16_t)*8);
    mav_array_memcpy(packet.rpms, rpms, sizeof(uint16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSORS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSORS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSORS_MIN_LEN, MAVLINK_MSG_ID_SENSORS_LEN, MAVLINK_MSG_ID_SENSORS_CRC);
}

/**
 * @brief Pack a sensors message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param angles 
 * @param rpms 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensors_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint16_t *angles,const uint16_t *rpms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSORS_LEN];

    _mav_put_uint16_t_array(buf, 0, angles, 8);
    _mav_put_uint16_t_array(buf, 16, rpms, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSORS_LEN);
#else
    mavlink_sensors_t packet;

    mav_array_memcpy(packet.angles, angles, sizeof(uint16_t)*8);
    mav_array_memcpy(packet.rpms, rpms, sizeof(uint16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSORS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSORS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSORS_MIN_LEN, MAVLINK_MSG_ID_SENSORS_LEN, MAVLINK_MSG_ID_SENSORS_CRC);
}

/**
 * @brief Encode a sensors struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sensors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensors_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sensors_t* sensors)
{
    return mavlink_msg_sensors_pack(system_id, component_id, msg, sensors->angles, sensors->rpms);
}

/**
 * @brief Encode a sensors struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensors_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sensors_t* sensors)
{
    return mavlink_msg_sensors_pack_chan(system_id, component_id, chan, msg, sensors->angles, sensors->rpms);
}

/**
 * @brief Send a sensors message
 * @param chan MAVLink channel to send the message
 *
 * @param angles 
 * @param rpms 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sensors_send(mavlink_channel_t chan, const uint16_t *angles, const uint16_t *rpms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSORS_LEN];

    _mav_put_uint16_t_array(buf, 0, angles, 8);
    _mav_put_uint16_t_array(buf, 16, rpms, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSORS, buf, MAVLINK_MSG_ID_SENSORS_MIN_LEN, MAVLINK_MSG_ID_SENSORS_LEN, MAVLINK_MSG_ID_SENSORS_CRC);
#else
    mavlink_sensors_t packet;

    mav_array_memcpy(packet.angles, angles, sizeof(uint16_t)*8);
    mav_array_memcpy(packet.rpms, rpms, sizeof(uint16_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSORS, (const char *)&packet, MAVLINK_MSG_ID_SENSORS_MIN_LEN, MAVLINK_MSG_ID_SENSORS_LEN, MAVLINK_MSG_ID_SENSORS_CRC);
#endif
}

/**
 * @brief Send a sensors message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sensors_send_struct(mavlink_channel_t chan, const mavlink_sensors_t* sensors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sensors_send(chan, sensors->angles, sensors->rpms);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSORS, (const char *)sensors, MAVLINK_MSG_ID_SENSORS_MIN_LEN, MAVLINK_MSG_ID_SENSORS_LEN, MAVLINK_MSG_ID_SENSORS_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSORS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sensors_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint16_t *angles, const uint16_t *rpms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_uint16_t_array(buf, 0, angles, 8);
    _mav_put_uint16_t_array(buf, 16, rpms, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSORS, buf, MAVLINK_MSG_ID_SENSORS_MIN_LEN, MAVLINK_MSG_ID_SENSORS_LEN, MAVLINK_MSG_ID_SENSORS_CRC);
#else
    mavlink_sensors_t *packet = (mavlink_sensors_t *)msgbuf;

    mav_array_memcpy(packet->angles, angles, sizeof(uint16_t)*8);
    mav_array_memcpy(packet->rpms, rpms, sizeof(uint16_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSORS, (const char *)packet, MAVLINK_MSG_ID_SENSORS_MIN_LEN, MAVLINK_MSG_ID_SENSORS_LEN, MAVLINK_MSG_ID_SENSORS_CRC);
#endif
}
#endif

#endif

// MESSAGE SENSORS UNPACKING


/**
 * @brief Get field angles from sensors message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_sensors_get_angles(const mavlink_message_t* msg, uint16_t *angles)
{
    return _MAV_RETURN_uint16_t_array(msg, angles, 8,  0);
}

/**
 * @brief Get field rpms from sensors message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_sensors_get_rpms(const mavlink_message_t* msg, uint16_t *rpms)
{
    return _MAV_RETURN_uint16_t_array(msg, rpms, 4,  16);
}

/**
 * @brief Decode a sensors message into a struct
 *
 * @param msg The message to decode
 * @param sensors C-struct to decode the message contents into
 */
static inline void mavlink_msg_sensors_decode(const mavlink_message_t* msg, mavlink_sensors_t* sensors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sensors_get_angles(msg, sensors->angles);
    mavlink_msg_sensors_get_rpms(msg, sensors->rpms);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSORS_LEN? msg->len : MAVLINK_MSG_ID_SENSORS_LEN;
        memset(sensors, 0, MAVLINK_MSG_ID_SENSORS_LEN);
    memcpy(sensors, _MAV_PAYLOAD(msg), len);
#endif
}
