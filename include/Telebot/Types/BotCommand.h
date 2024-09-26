#ifndef Telebot_BotCommand_H
#define Telebot_BotCommand_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class BotCommand final
    {
    public:
        typedef std::shared_ptr<BotCommand> Ptr;

        BotCommand() = default;

        BotCommand(const std::string& command, const std::string& description)
        {
            this->command = command;
            this->description = description;
        }

        ~BotCommand() = default;

        std::string command;
        std::string description;
    };

    inline void from_json(const ExtendedCpp::Json& json, BotCommand& object) noexcept
    {
        VALUE_FROM_JSON(command)
        VALUE_FROM_JSON(description)
    }

    inline void to_json(ExtendedCpp::Json& json, const BotCommand::Ptr& object) noexcept
    {
        VALUE_TO_JSON(command)
        VALUE_TO_JSON(description)
    }
}

#endif