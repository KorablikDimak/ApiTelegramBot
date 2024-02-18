#ifndef Telebot_MessageId_H
#define Telebot_MessageId_H

#include <memory>

namespace Telebot
{
    class MessageId
    {
    public:
        typedef std::shared_ptr<MessageId> Ptr;

        std::int32_t message_id;
    };
}

#endif