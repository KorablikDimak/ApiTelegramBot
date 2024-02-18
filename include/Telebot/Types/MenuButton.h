#ifndef Telebot_MenuButton_H
#define Telebot_MenuButton_H

#include <memory>
#include <string>

namespace Telebot
{
    class MenuButton
    {
    public:
        typedef std::shared_ptr<MenuButton> Ptr;

        MenuButton() = default;
        virtual ~MenuButton() = default;

        std::string Type;
    };
}

#endif