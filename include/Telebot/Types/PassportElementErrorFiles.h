#ifndef Telebot_PassportElementErrorFiles_H
#define Telebot_PassportElementErrorFiles_H

#include <vector>

#include <Telebot/Types/PassportElementError.h>

namespace Telebot
{
    class PassportElementErrorFiles final : public PassportElementError
    {
    public:
        typedef std::shared_ptr<PassportElementErrorFiles> Ptr;

        static const std::string SOURCE;

        PassportElementErrorFiles() noexcept
        {
            Source = SOURCE;
        }

        std::vector<std::string> FileHashes;
    };
}

#endif