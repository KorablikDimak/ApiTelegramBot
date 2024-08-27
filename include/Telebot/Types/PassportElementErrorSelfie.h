#ifndef Telebot_PassportElementErrorSelfie_H
#define Telebot_PassportElementErrorSelfie_H

#include <Telebot/Types/PassportElementError.h>

namespace Telebot
{
    class PassportElementErrorSelfie final : public PassportElementError
    {
    public:
        typedef std::shared_ptr<PassportElementErrorSelfie> Ptr;

        static const std::string SOURCE;

        PassportElementErrorSelfie() noexcept
        {
            Source = SOURCE;
        }

        std::string FileHash;
    };
}

#endif