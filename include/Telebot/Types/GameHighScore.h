#ifndef Telebot_GameHighScore_H
#define Telebot_GameHighScore_H

#include <Telebot/Types/User.h>

namespace Telebot
{
    class GameHighScore
    {
    public:
        typedef std::shared_ptr<GameHighScore> Ptr;

        std::string Position;
        User::Ptr User;
        std::int32_t Score;
    };
}

#endif