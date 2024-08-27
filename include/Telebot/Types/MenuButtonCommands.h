#ifndef Telebot_MenuButtonCommands_H
#define Telebot_MenuButtonCommands_H

#include <Telebot/Types/MenuButton.h>

namespace Telebot
{
    class MenuButtonCommands final : public MenuButton
    {
    public:
        typedef std::shared_ptr<MenuButtonCommands> Ptr;

        static const std::string TYPE;

        MenuButtonCommands() noexcept
        {
            Type = TYPE;
        }
    };
}

#endif