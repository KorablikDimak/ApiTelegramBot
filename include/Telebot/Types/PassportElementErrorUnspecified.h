#ifndef Telebot_PassportElementErrorUnspecified_H
#define Telebot_PassportElementErrorUnspecified_H

#include <Telebot/Types/PassportElementError.h>

namespace Telebot
{
    class PassportElementErrorUnspecified final : public PassportElementError
    {
    public:
        typedef std::shared_ptr<PassportElementErrorUnspecified> Ptr;

        static const std::string SOURCE;

        PassportElementErrorUnspecified()
        {
            Source = SOURCE;
        }

        std::string ElementHash;
    };
}

#endif