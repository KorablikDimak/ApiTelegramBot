#ifndef Telebot_InlineQueryResultGame_H
#define Telebot_InlineQueryResultGame_H

#include <Telebot/Types/InlineQueryResult.h>

namespace Telebot
{
    class InlineQueryResultGame final : public InlineQueryResult
    {
    public:
        typedef std::shared_ptr<InlineQueryResultGame> Ptr;

        static const std::string TYPE;

        InlineQueryResultGame() noexcept
        {
            Type = TYPE;
        }

        std::string GameShortName;
    };
}

#endif