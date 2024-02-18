#ifndef Telebot_SentWebAppMessage_H
#define Telebot_SentWebAppMessage_H

#include <memory>
#include <string>

namespace Telebot
{
    class SentWebAppMessage
    {
    public:
        typedef std::shared_ptr<SentWebAppMessage> Ptr;

        std::string InlineMessageId;
    };
}

#endif