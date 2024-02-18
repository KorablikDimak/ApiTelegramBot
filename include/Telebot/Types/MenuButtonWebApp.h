#ifndef Telebot_MenuButtonWebApp_H
#define Telebot_MenuButtonWebApp_H

#include <Telebot/Types/MenuButton.h>
#include <Telebot/Types/WebAppInfo.h>

namespace Telebot
{
    class MenuButtonWebApp final : public MenuButton
    {
    public:
        typedef std::shared_ptr<MenuButtonWebApp> Ptr;

        static const std::string TYPE;

        MenuButtonWebApp()
        {
            Type = TYPE;
        }

        std::string Text;
        WebAppInfo::Ptr WebApp;
    };
}

#endif