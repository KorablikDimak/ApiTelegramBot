#ifndef Telebot_EncryptedCredentials_H
#define Telebot_EncryptedCredentials_H

#include <ExtendedCpp/Json.h>

namespace Telebot
{
    class EncryptedCredentials
    {
    public:
        typedef std::shared_ptr<EncryptedCredentials> Ptr;

        std::string data;
        std::string hash;
        std::string secret;
    };

    inline void from_json(const ExtendedCpp::Json& json, EncryptedCredentials& object) noexcept
    {
        VALUE_FROM_JSON(data)
        VALUE_FROM_JSON(hash)
        VALUE_FROM_JSON(secret)
    }
}

#endif