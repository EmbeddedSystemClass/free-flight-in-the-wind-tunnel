#pragma once
// MESSAGE PWMS PACKING

#define MAVLINK_MSG_ID_PWMS 2

MAVPACKED(
typedef struct __mavlink_pwms_t {
 uint16_t pwms[8]; /*< */
}) mavlink_pwms_t;

#define MAVLINK_MSG_ID_PWMS_LEN 16
#define MAVLINK_MSG_ID_PWMS_MIN_LEN 16
#define MAVLINK_MSG_ID_2_LEN 16
#define MAVLINK_MSG_ID_2_MIN_LEN 16

#define MAVLINK_MSG_ID_PWMS_CRC 194
#define MAVLINK_MSG_ID_2_CRC 194

#define MAVLINK_MSG_PWMS_FIELD_PWMS_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PWMS { \
    2, \
    "PWMS", \
    1, \
    {  { "pwms", NULL, MAVLINK_TYPE_UINT16_T, 8, 0, offsetof(mavlink_pwms_t, pwms) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PWMS { \
    "PWMS", \
    1, \
    {  { "pwms", NULL, MAVLINK_TYPE_UINT16_T, 8, 0, offsetof(mavlink_pwms_t, pwms) }, \
         } \
}
#endif

/**
 * @brief Pack a pwms message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pwms 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pwms_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint16_t *pwms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PWMS_LEN];

    _mav_put_uint16_t_array(buf, 0, pwms, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PWMS_LEN);
#else
    mavlink_pwms_t packet;

    mav_array_memcpy(packet.pwms, pwms, sizeof(uint16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PWMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PWMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PWMS_MIN_LEN, MAVLINK_MSG_ID_PWMS_LEN, MAVLINK_MSG_ID_PWMS_CRC);
}

/**
 * @brief Pack a pwms message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pwms 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pwms_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint16_t *pwms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PWMS_LEN];

    _mav_put_uint16_t_array(buf, 0, pwms, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PWMS_LEN);
#else
    mavlink_pwms_t packet;

    mav_array_memcpy(packet.pwms, pwms, sizeof(uint16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PWMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PWMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PWMS_MIN_LEN, MAVLINK_MSG_ID_PWMS_LEN, MAVLINK_MSG_ID_PWMS_CRC);
}

/**
 * @brief Encode a pwms struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pwms C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pwms_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pwms_t* pwms)
{
    return mavlink_msg_pwms_pack(system_id, component_id, msg, pwms->pwms);
}

/**
 * @brief Encode a pwms struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pwms C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pwms_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pwms_t* pwms)
{
    return mavlink_msg_pwms_pack_chan(system_id, component_id, chan, msg, pwms->pwms);
}

/**
 * @brief Send a pwms message
 * @param chan MAVLink channel to send the message
 *
 * @param pwms 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pwms_send(mavlink_channel_t chan, const uint16_t *pwms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PWMS_LEN];

    _mav_put_uint16_t_array(buf, 0, pwms, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWMS, buf, MAVLINK_MSG_ID_PWMS_MIN_LEN, MAVLINK_MSG_ID_PWMS_LEN, MAVLINK_MSG_ID_PWMS_CRC);
#else
    mavlink_pwms_t packet;

    mav_array_memcpy(packet.pwms, pwms, sizeof(uint16_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWMS, (const char *)&packet, MAVLINK_MSG_ID_PWMS_MIN_LEN, MAVLINK_MSG_ID_PWMS_LEN, MAVLINK_MSG_ID_PWMS_CRC);
#endif
}

/**
 * @brief Send a pwms message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pwms_send_struct(mavlink_channel_t chan, const mavlink_pwms_t* pwms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pwms_send(chan, pwms->pwms);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWMS, (const char *)pwms, MAVLINK_MSG_ID_PWMS_MIN_LEN, MAVLINK_MSG_ID_PWMS_LEN, MAVLINK_MSG_ID_PWMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_PWMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pwms_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint16_t *pwms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_uint16_t_array(buf, 0, pwms, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWMS, buf, MAVLINK_MSG_ID_PWMS_MIN_LEN, MAVLINK_MSG_ID_PWMS_LEN, MAVLINK_MSG_ID_PWMS_CRC);
#else
    mavlink_pwms_t *packet = (mavlink_pwms_t *)msgbuf;

    mav_array_memcpy(packet->pwms, pwms, sizeof(uint16_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWMS, (const char *)packet, MAVLINK_MSG_ID_PWMS_MIN_LEN, MAVLINK_MSG_ID_PWMS_LEN, MAVLINK_MSG_ID_PWMS_CRC);
#endif
}
#endif

#endif

// MESSAGE PWMS UNPACKING


/**
 * @brief Get field pwms from pwms message
 *
 * @return 
 */
static inline uint16_t mavlink_msg_pwms_get_pwms(const mavlink_message_t* msg, uint16_t *pwms)
{
    return _MAV_RETURN_uint16_t_array(msg, pwms, 8,  0);
}

/**
 * @brief Decode a pwms message into a struct
 *
 * @param msg The message to decode
 * @param pwms C-struct to decode the message contents into
 */
static inline void mavlink_msg_pwms_decode(const mavlink_message_t* msg, mavlink_pwms_t* pwms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pwms_get_pwms(msg, pwms->pwms);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PWMS_LEN? msg->len : MAVLINK_MSG_ID_PWMS_LEN;
        memset(pwms, 0, MAVLINK_MSG_ID_PWMS_LEN);
    memcpy(pwms, _MAV_PAYLOAD(msg), len);
#endif
}
