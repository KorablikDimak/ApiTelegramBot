#ifndef Telebot_PassportElementErrorFrontSide_H
#define Telebot_PassportElementErrorFrontSide_H

#include <Telebot/Types/PassportElementError.h>

namespace Telebot
{
    class PassportElementErrorFrontSide final : public PassportElementError
    {
    public:
        typedef std::shared_ptr<PassportElementErrorFrontSide> Ptr;

        static const std::string SOURCE;

        PassportElementErrorFrontSide()
        {
            Source = SOURCE;
        }

        std::string FileHash;
    };
}

#endif