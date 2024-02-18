#ifndef Telebot_PassportElementErrorReverseSide_H
#define Telebot_PassportElementErrorReverseSide_H

#include <Telebot/Types/PassportElementError.h>

namespace Telebot
{
    class PassportElementErrorReverseSide final : public PassportElementError
    {
    public:
        typedef std::shared_ptr<PassportElementErrorReverseSide> Ptr;

        static const std::string SOURCE;

        PassportElementErrorReverseSide()
        {
            Source = SOURCE;
        }

        std::string FileHash;
    };
}

#endif