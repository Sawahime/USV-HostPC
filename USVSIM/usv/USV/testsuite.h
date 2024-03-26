/** @file
 *    @brief MAVLink comm protocol testsuite generated from USV.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef USV_TESTSUITE_H
#define USV_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_USV(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_USV(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_usv_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_USV_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_usv_status_t packet_in = {
        17.0,45.0,963497880,963498088,129.0,157.0,185.0,213.0,101
    };
    mavlink_usv_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.course = packet_in.course;
        packet1.velocity = packet_in.velocity;
        packet1.command_velocity = packet_in.command_velocity;
        packet1.command_turn = packet_in.command_turn;
        packet1.stage = packet_in.stage;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_USV_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_USV_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_usv_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_status_pack(system_id, component_id, &msg , packet1.stage , packet1.x , packet1.y , packet1.lat , packet1.lon , packet1.course , packet1.velocity , packet1.command_velocity , packet1.command_turn );
    mavlink_msg_usv_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.stage , packet1.x , packet1.y , packet1.lat , packet1.lon , packet1.course , packet1.velocity , packet1.command_velocity , packet1.command_turn );
    mavlink_msg_usv_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_usv_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_status_send(MAVLINK_COMM_1 , packet1.stage , packet1.x , packet1.y , packet1.lat , packet1.lon , packet1.course , packet1.velocity , packet1.command_velocity , packet1.command_turn );
    mavlink_msg_usv_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gcs_commond(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GCS_COMMOND >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gcs_commond_t packet_in = {
        17.0,45.0,73.0,41
    };
    mavlink_gcs_commond_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.P = packet_in.P;
        packet1.I = packet_in.I;
        packet1.D = packet_in.D;
        packet1.Stop_flag = packet_in.Stop_flag;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GCS_COMMOND_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GCS_COMMOND_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_commond_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gcs_commond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_commond_pack(system_id, component_id, &msg , packet1.P , packet1.I , packet1.D , packet1.Stop_flag );
    mavlink_msg_gcs_commond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_commond_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.P , packet1.I , packet1.D , packet1.Stop_flag );
    mavlink_msg_gcs_commond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gcs_commond_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_commond_send(MAVLINK_COMM_1 , packet1.P , packet1.I , packet1.D , packet1.Stop_flag );
    mavlink_msg_gcs_commond_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_usv_ball(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_USV_BALL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_usv_ball_t packet_in = {
        963497464,963497672,29,96
    };
    mavlink_usv_ball_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.ball_lat = packet_in.ball_lat;
        packet1.ball_lon = packet_in.ball_lon;
        packet1.ball_id = packet_in.ball_id;
        packet1.ball_color = packet_in.ball_color;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_USV_BALL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_USV_BALL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_ball_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_usv_ball_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_ball_pack(system_id, component_id, &msg , packet1.ball_id , packet1.ball_color , packet1.ball_lat , packet1.ball_lon );
    mavlink_msg_usv_ball_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_ball_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ball_id , packet1.ball_color , packet1.ball_lat , packet1.ball_lon );
    mavlink_msg_usv_ball_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_usv_ball_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_ball_send(MAVLINK_COMM_1 , packet1.ball_id , packet1.ball_color , packet1.ball_lat , packet1.ball_lon );
    mavlink_msg_usv_ball_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gcs_simulation_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GCS_SIMULATION_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gcs_simulation_status_t packet_in = {
        963497464,963497672,73.0
    };
    mavlink_gcs_simulation_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.ball_lat = packet_in.ball_lat;
        packet1.ball_lon = packet_in.ball_lon;
        packet1.course = packet_in.course;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GCS_SIMULATION_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_simulation_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gcs_simulation_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_simulation_status_pack(system_id, component_id, &msg , packet1.ball_lat , packet1.ball_lon , packet1.course );
    mavlink_msg_gcs_simulation_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_simulation_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ball_lat , packet1.ball_lon , packet1.course );
    mavlink_msg_gcs_simulation_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gcs_simulation_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_simulation_status_send(MAVLINK_COMM_1 , packet1.ball_lat , packet1.ball_lon , packet1.course );
    mavlink_msg_gcs_simulation_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_usv_simulation_commond(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_USV_SIMULATION_COMMOND >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_usv_simulation_commond_t packet_in = {
        17.0,45.0,29
    };
    mavlink_usv_simulation_commond_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.command_velocity = packet_in.command_velocity;
        packet1.command_turn = packet_in.command_turn;
        packet1.stage = packet_in.stage;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_USV_SIMULATION_COMMOND_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_simulation_commond_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_usv_simulation_commond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_simulation_commond_pack(system_id, component_id, &msg , packet1.stage , packet1.command_velocity , packet1.command_turn );
    mavlink_msg_usv_simulation_commond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_simulation_commond_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.stage , packet1.command_velocity , packet1.command_turn );
    mavlink_msg_usv_simulation_commond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_usv_simulation_commond_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_usv_simulation_commond_send(MAVLINK_COMM_1 , packet1.stage , packet1.command_velocity , packet1.command_turn );
    mavlink_msg_usv_simulation_commond_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gcs_set_or_usv_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GCS_SET_OR_USV_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gcs_set_or_usv_ack_t packet_in = {
        963497464,963497672,17651,163
    };
    mavlink_gcs_set_or_usv_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.content0 = packet_in.content0;
        packet1.content1 = packet_in.content1;
        packet1.content2 = packet_in.content2;
        packet1.type = packet_in.type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GCS_SET_OR_USV_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GCS_SET_OR_USV_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_or_usv_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gcs_set_or_usv_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_or_usv_ack_pack(system_id, component_id, &msg , packet1.type , packet1.content0 , packet1.content1 , packet1.content2 );
    mavlink_msg_gcs_set_or_usv_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_or_usv_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.content0 , packet1.content1 , packet1.content2 );
    mavlink_msg_gcs_set_or_usv_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gcs_set_or_usv_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gcs_set_or_usv_ack_send(MAVLINK_COMM_1 , packet1.type , packet1.content0 , packet1.content1 , packet1.content2 );
    mavlink_msg_gcs_set_or_usv_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_USV(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_usv_status(system_id, component_id, last_msg);
    mavlink_test_gcs_commond(system_id, component_id, last_msg);
    mavlink_test_usv_ball(system_id, component_id, last_msg);
    mavlink_test_gcs_simulation_status(system_id, component_id, last_msg);
    mavlink_test_usv_simulation_commond(system_id, component_id, last_msg);
    mavlink_test_gcs_set_or_usv_ack(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // USV_TESTSUITE_H
