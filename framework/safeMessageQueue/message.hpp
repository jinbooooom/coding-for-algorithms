#ifndef MESSAGE_HPP
#define MESSAGE_HPP

enum message_type_e
{
    PVR_MSG_RECORD_START,
    PVR_MSG_RECORD_PAUSE,
    PVR_MSG_RECORD_RESTART,
    PVR_MSG_RECORD_STOP,
    HDD_MSG_SPACE_NOT_ENOUGH,
};

struct dvr_action_t
{
    int id;
};

struct hdd_action_t
{
    int id;
};

union message_body_u
{
    dvr_action_t dvr;
    hdd_action_t hdd;
};

struct message_t
{
    message_type_e what;
    message_body_u obj;
};

#endif