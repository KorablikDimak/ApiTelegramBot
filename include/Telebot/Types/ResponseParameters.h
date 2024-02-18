#ifndef Telebot_ResponseParameters_H
#define Telebot_ResponseParameters_H

#include <memory>
#include <cstdint>

namespace Telebot
{
    class ResponseParameters
    {
    public:
        typedef std::shared_ptr<ResponseParameters> Ptr;

        std::int64_t MigrateToChatId;
        std::int32_t RetryAfter;
    };
}

#endif