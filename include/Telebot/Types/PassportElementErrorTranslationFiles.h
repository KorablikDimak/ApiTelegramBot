#ifndef Telebot_PassportElementErrorTranslationFiles_H
#define Telebot_PassportElementErrorTranslationFiles_H

#include <vector>

#include <Telebot/Types/PassportElementError.h>

namespace Telebot
{
    class PassportElementErrorTranslationFiles final : public PassportElementError
    {
    public:
        typedef std::shared_ptr<PassportElementErrorTranslationFiles> Ptr;

        static const std::string SOURCE;

        PassportElementErrorTranslationFiles() noexcept
        {
            Source = SOURCE;
        }

        std::vector<std::string> FileHashes;
    };
}

#endif