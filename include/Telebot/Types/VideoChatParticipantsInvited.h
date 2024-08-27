#ifndef Telebot_VideoChatParticipantsInvited_H
#define Telebot_VideoChatParticipantsInvited_H

#include <Telebot/Types/User.h>

namespace Telebot
{
    class VideoChatParticipantsInvited
    {
    public:
        typedef std::shared_ptr<VideoChatParticipantsInvited> Ptr;

        std::vector<User::Ptr> users;
    };

    inline void from_json(const Json::Json& json, VideoChatParticipantsInvited& object) noexcept
    {
        OBJECTS_FROM_JSON(users)
    }
}

#endif