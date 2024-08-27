#ifndef Telebot_MenuButtonDefault_H
#define Telebot_MenuButtonDefault_H

#include <Telebot/Types/MenuButton.h>

namespace Telebot
{
    class MenuButtonDefault final : public MenuButton
    {
    public:
        typedef std::shared_ptr<MenuButtonDefault> Ptr;

        static const std::string TYPE;

        MenuButtonDefault() noexcept
        {
            Type = TYPE;
        }
    };
}

#endif