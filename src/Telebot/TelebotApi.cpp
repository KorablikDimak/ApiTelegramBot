#include <fstream>
#include <filesystem>

#include <Common/Random.h>

#include <Telebot/TelebotApi.h>
#include <Telebot/HttpContext.h>
#include <Telebot/HttpsClient.h>

const std::string Telebot::TelebotApi::HOST = "api.telegram.org";
const unsigned int Telebot::TelebotApi::HTTP_VERSION = 11;

Telebot::TelebotApi::TelebotApi(const std::string& token) noexcept
{
    _token = token;
}

std::optional<Json::Json> Telebot::TelebotApi::Get(const std::string& methodName) const noexcept
{
    const auto httpContext = std::make_shared<HttpContext<EmptyBody, StringBody>>();
    httpContext->Request->version(HTTP_VERSION);
    httpContext->Request->method_string("GET");
    httpContext->Request->set(boost::beast::http::field::host, HOST);
    httpContext->Request->target("/bot" + _token + "/" + methodName);

    try
    { HttpsClient::SendHttpsAsync(httpContext); }
    catch (...)
    { return std::nullopt; }

    const auto json = Json::Json::parse(httpContext->Response->get().body());
    if (!json.contains("ok")) return std::nullopt;
    if (json.at("ok").get<bool>())
    {
        if (!json.contains("result"))
            return std::nullopt;
        return json.at("result");
    }
    return std::nullopt;
}

std::optional<Json::Json> Telebot::TelebotApi::Post(const std::string& methodName, const Json::Json& params) const noexcept
{
    auto httpContext = std::make_shared<HttpContext<StringBody, StringBody>>();
    httpContext->Request->version(HTTP_VERSION);
    httpContext->Request->method_string("POST");
    httpContext->Request->set(boost::beast::http::field::host, HOST);
    httpContext->Request->target("/bot" + _token + "/" + methodName);

    httpContext->Request->set(boost::beast::http::field::content_type, "application/json");
    httpContext->Request->body() = params.dump();
    httpContext->Request->prepare_payload();

    try
    { HttpsClient::SendHttpsAsync(httpContext); }
    catch (...)
    { return std::nullopt; }

    const auto json = Json::Json::parse(httpContext->Response->get().body());
    if (!json.contains("ok")) return std::nullopt;
    if (json.at("ok").get<bool>())
    {
        if (!json.contains("result"))
            return std::nullopt;
        return json.at("result");
    }
    return std::nullopt;
}

std::vector<Telebot::Update::Ptr> Telebot::TelebotApi::GetUpdates(int offset,
                                                                  int limit,
                                                                  int timeout,
                                                                  const std::vector<std::string>& allowedUpdates) const noexcept
{
    Json::Json requestBody;
    requestBody["offset"] = offset;
    requestBody["limit"] = limit;
    requestBody["timeout"] = timeout;
    requestBody["allowed_updates"] = allowedUpdates;

    std::vector<Update::Ptr> updates;
    const auto postResult = Post("getUpdates", requestBody);
    if (!postResult.has_value()) return updates;
    const Json::Json& responseBody = postResult.value();

    for (const Json::Json& element : responseBody)
    {
        auto update = std::make_shared<Update>();
        *update = element.get<Update>();
        updates.push_back(update);
    }
    return updates;
}

bool Telebot::TelebotApi::SetWebhook(const std::string &url,
                                     const InputFile::Ptr& certificate,
                                     std::int32_t maxConnections,
                                     const std::vector<std::string> &allowedUpdates,
                                     const std::string &ipAddress,
                                     bool dropPendingUpdates,
                                     const std::string &secretToken)
{
    throw std::exception();
}

bool Telebot::TelebotApi::DeleteWebhook(bool dropPendingUpdates)
{
    throw std::exception();
}

Telebot::WebhookInfo::Ptr Telebot::TelebotApi::GetWebhookInfo()
{
    throw std::exception();
}

Telebot::User::Ptr Telebot::TelebotApi::GetMe() const noexcept
{
    const auto getResult = Get("getMe");
    if (!getResult.has_value()) return { nullptr };
    const Json::Json& responseBody = getResult.value();

    auto user = std::make_shared<User>();
    *user = responseBody.get<User>();
    return user;
}

bool Telebot::TelebotApi::LogOut()
{
    throw std::exception();
}

bool Telebot::TelebotApi::Close()
{
    throw std::exception();
}

#undef SendMessage

Telebot::Message::Ptr Telebot::TelebotApi::SendMessage(std::int64_t chatId,
                                                       const std::string& text,
                                                       bool disableWebPagePreview,
                                                       std::int32_t replyToMessageId,
                                                       const GenericReply::Ptr& replyMarkup,
                                                       const std::string& parseMode,
                                                       bool disableNotification,
                                                       const std::vector<MessageEntity::Ptr>& entities,
                                                       bool allowSendingWithoutReply,
                                                       bool protectContent,
                                                       std::int32_t messageThreadId) const noexcept
{
    Json::Json requestBody;
    requestBody["chat_id"] = chatId;
    requestBody["text"] = text;
    if (replyMarkup.get() != nullptr) requestBody["reply_markup"] = replyMarkup;

    const auto postResult = Post("sendMessage", requestBody);
    if (!postResult.has_value()) return { nullptr };
    const Json::Json& responseBody = postResult.value();

    auto message = std::make_shared<Message>();
    *message = responseBody.get<Message>();
    return message;
}

#define SendMessage __MINGW_NAME_AW(SendMessage)

Telebot::Message::Ptr Telebot::TelebotApi::ForwardMessage(std::int64_t chatId,
                                                          std::int64_t fromChatId,
                                                          std::int32_t messageId,
                                                          bool disableNotification,
                                                          bool protectContent,
                                                          std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::MessageId::Ptr Telebot::TelebotApi::CopyMessage(std::int64_t chatId,
                                                         std::int64_t fromChatId,
                                                         std::int32_t messageId,
                                                         const std::string& caption,
                                                         const std::string& parseMode,
                                                         const std::vector<MessageEntity::Ptr>& captionEntities,
                                                         bool disableNotification,
                                                         std::int32_t replyToMessageId,
                                                         bool allowSendingWithoutReply,
                                                         const GenericReply::Ptr& replyMarkup,
                                                         bool protectContent,
                                                         std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendPhoto(std::int64_t chatId,
                                                     const std::variant<std::string, InputFile::Ptr>& photo,
                                                     const std::string& caption,
                                                     std::int32_t replyToMessageId,
                                                     const GenericReply::Ptr& replyMarkup,
                                                     const std::string& parseMode,
                                                     bool disableNotification,
                                                     const std::vector<MessageEntity::Ptr>& captionEntities,
                                                     bool allowSendingWithoutReply,
                                                     bool protectContent,
                                                     std::int32_t messageThreadId,
                                                     bool hasSpoiler) const noexcept
{
    if (photo.index() == 0)
    {
        Json::Json requestBody;
        requestBody["chat_id"] = chatId;
        requestBody["photo"] = std::get<std::string>(photo);

        const auto postResult = Post("sendPhoto", requestBody);
        if (!postResult.has_value()) return { nullptr };
        const Json::Json& responseBody = postResult.value();

        auto message = std::make_shared<Message>();
        *message = responseBody.get<Message>();
        return message;
    }
    else
    {
        return { nullptr };
    }
}

Telebot::Message::Ptr Telebot::TelebotApi::SendAudio(std::int64_t chatId,
                                                     const std::variant<std::string, InputFile::Ptr>& audio,
                                                     const std::string& caption,
                                                     std::int32_t duration,
                                                     const std::string& performer,
                                                     const std::string& title,
                                                     const InputFile::Ptr& thumb,
                                                     std::int32_t replyToMessageId,
                                                     const GenericReply::Ptr& replyMarkup,
                                                     const std::string& parseMode,
                                                     bool disableNotification,
                                                     const std::vector<MessageEntity::Ptr>& captionEntities,
                                                     bool allowSendingWithoutReply,
                                                     bool protectContent,
                                                     std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendDocument(std::int64_t chatId,
                                                        const std::variant<std::string, InputFile::Ptr>& document,
                                                        const InputFile::Ptr& thumb,
                                                        const std::string& caption,
                                                        std::int32_t replyToMessageId,
                                                        const GenericReply::Ptr& replyMarkup,
                                                        const std::string& parseMode,
                                                        bool disableNotification,
                                                        const std::vector<MessageEntity::Ptr>& captionEntities,
                                                        bool disableContentTypeDetection,
                                                        bool allowSendingWithoutReply,
                                                        bool protectContent,
                                                        std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendVideo(std::int64_t chatId,
                                                     const std::variant<std::string, InputFile::Ptr>& video,
                                                     bool supportsStreaming,
                                                     std::int32_t duration,
                                                     std::int32_t width,
                                                     std::int32_t height,
                                                     const InputFile::Ptr& thumb,
                                                     const std::string &caption,
                                                     std::int32_t replyToMessageId,
                                                     const GenericReply::Ptr& replyMarkup,
                                                     const std::string &parseMode,
                                                     bool disableNotification,
                                                     const std::vector<MessageEntity::Ptr>& captionEntities,
                                                     bool allowSendingWithoutReply,
                                                     bool protectContent,
                                                     std::int32_t messageThreadId,
                                                     bool hasSpoiler)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendAnimation(std::int64_t chatId,
                                                         const std::variant<std::string, InputFile::Ptr>& animation,
                                                         std::int32_t duration,
                                                         std::int32_t width,
                                                         std::int32_t height,
                                                         const InputFile::Ptr& thumb,
                                                         const std::string& caption,
                                                         std::int32_t replyToMessageId,
                                                         const GenericReply::Ptr& replyMarkup,
                                                         const std::string &parseMode,
                                                         bool disableNotification,
                                                         const std::vector<MessageEntity::Ptr>& captionEntities,
                                                         bool allowSendingWithoutReply,
                                                         bool protectContent,
                                                         std::int32_t messageThreadId,
                                                         bool hasSpoiler)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendVoice(std::int64_t chatId,
                                                     const std::variant<std::string, InputFile::Ptr>& voice,
                                                     const std::string& caption,
                                                     std::int32_t duration,
                                                     std::int32_t replyToMessageId,
                                                     const GenericReply::Ptr& replyMarkup,
                                                     const std::string& parseMode,
                                                     bool disableNotification,
                                                     const std::vector<MessageEntity::Ptr>& captionEntities,
                                                     bool allowSendingWithoutReply,
                                                     bool protectContent,
                                                     std::int32_t messageThreadId) const noexcept
{
    if (voice.index() == 0)
    {
        try
        {
            std::stringstream fileContent;
            std::ifstream file(std::get<std::string>(voice).c_str(), std::ios::binary);
            if (!file.is_open()) return nullptr;
            fileContent << file.rdbuf();

            std::filesystem::path filePath(std::get<std::string>(voice));
            const std::string guid = Common::RandomString(12);
            std::string body = "--" + guid + "\r\n"
                               "Content-Disposition: form-data; name=\"chat_id\"\r\n"
                               "Content-Type: text/plain\r\n\r\n"
                               + std::to_string(chatId) + "\r\n"
                               "--" + guid + "\r\n"
                               "Content-Disposition: form-data; name=\"voice\"; filename=\""
                               + filePath.filename().string() + "\"\r\n"
                               "Content-Type: application/octet-stream\r\n\r\n"
                               + fileContent.str() + "\r\n"
                               "--" + guid + "--\r\n";

            auto httpContext = std::make_shared<HttpContext<StringBody, StringBody>>();
            httpContext->Request->version(HTTP_VERSION);
            httpContext->Request->method_string("POST");
            httpContext->Request->set(boost::beast::http::field::host, HOST);
            httpContext->Request->target("/bot" + _token + "/sendVoice");

            httpContext->Request->set(boost::beast::http::field::content_type, "multipart/form-data; boundary=" + guid);
            httpContext->Request->body() = std::move(body);
            httpContext->Request->prepare_payload();

            HttpsClient::SendHttpsAsync(httpContext);

            auto responseBody = Json::Json::parse(httpContext->Response->get().body());
            auto message = std::make_shared<Message>();
            *message = responseBody.get<Message>();
            return message;
        }
        catch (...)
        {
            return { nullptr };
        }
    }
    else
    {
        return { nullptr };
    }
}

Telebot::Message::Ptr Telebot::TelebotApi::SendVideoNote(std::int64_t chatId,
                                                         const std::variant<std::string, InputFile::Ptr>& videoNote,
                                                         std::int64_t replyToMessageId,
                                                         bool disableNotification,
                                                         std::int32_t duration,
                                                         std::int32_t length,
                                                         const InputFile::Ptr& thumb,
                                                         const GenericReply::Ptr& replyMarkup,
                                                         bool allowSendingWithoutReply,
                                                         bool protectContent,
                                                         std::int32_t messageThreadId)
{
    throw std::exception();
}

std::vector<Telebot::Message::Ptr> Telebot::TelebotApi::SendMediaGroup(std::int64_t chatId,
                                                                       const std::vector<InputMedia::Ptr>& media,
                                                                       bool disableNotification,
                                                                       std::int32_t replyToMessageId,
                                                                       bool allowSendingWithoutReply,
                                                                       bool protectContent,
                                                                       std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendLocation(std::int64_t chatId,
                                                        float latitude,
                                                        float longitude,
                                                        std::int32_t livePeriod,
                                                        std::int32_t replyToMessageId,
                                                        const GenericReply::Ptr& replyMarkup,
                                                        bool disableNotification,
                                                        float horizontalAccuracy,
                                                        std::int32_t heading,
                                                        std::int32_t proximityAlertRadius,
                                                        bool allowSendingWithoutReply,
                                                        bool protectContent,
                                                        std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendVenue(std::int64_t chatId,
                                                     float latitude,
                                                     float longitude,
                                                     const std::string& title,
                                                     const std::string& address,
                                                     const std::string& foursquareId,
                                                     const std::string& foursquareType,
                                                     bool disableNotification,
                                                     std::int32_t replyToMessageId,
                                                     const GenericReply::Ptr& replyMarkup,
                                                     const std::string& googlePlaceId,
                                                     const std::string& googlePlaceType,
                                                     bool allowSendingWithoutReply,
                                                     bool protectContent,
                                                     std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendContact(std::int64_t chatId,
                                                       const std::string& phoneNumber,
                                                       const std::string& firstName,
                                                       const std::string& lastName,
                                                       const std::string& vcard,
                                                       bool disableNotification,
                                                       std::int32_t replyToMessageId,
                                                       const GenericReply::Ptr& replyMarkup,
                                                       bool allowSendingWithoutReply,
                                                       bool protectContent,
                                                       std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendPoll(std::int64_t chatId,
                                                    const std::string& question,
                                                    const std::vector<std::string>& options,
                                                    bool disableNotification,
                                                    std::int32_t replyToMessageId,
                                                    const GenericReply::Ptr& replyMarkup,
                                                    bool isAnonymous,
                                                    const std::string& type,
                                                    bool allowsMultipleAnswers,
                                                    std::int32_t correctOptionId,
                                                    const std::string& explanation,
                                                    const std::string& explanationParseMode,
                                                    const std::vector<MessageEntity::Ptr>& explanationEntities,
                                                    std::int32_t openPeriod,
                                                    std::int32_t closeDate,
                                                    bool isClosed,
                                                    bool allowSendingWithoutReply,
                                                    bool protectContent,
                                                    std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendDice(const std::int64_t chatId,
                                                    bool disableNotification,
                                                    std::int32_t replyToMessageId,
                                                    const GenericReply::Ptr& replyMarkup,
                                                    const std::string& emoji,
                                                    bool allowSendingWithoutReply,
                                                    bool protectContent,
                                                    std::int32_t messageThreadId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SendChatAction(std::int64_t chatId,
                                         const std::string& action,
                                         std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::UserProfilePhotos::Ptr Telebot::TelebotApi::GetUserProfilePhotos(std::int64_t userId,
                                                                          std::int32_t offset,
                                                                          std::int32_t limit)
{
    throw std::exception();
}

Telebot::File::Ptr Telebot::TelebotApi::GetFile(const std::string& fileId) const noexcept
{
    Json::Json requestBody;
    requestBody["file_id"] = fileId;

    const auto postResult = Post("getFile", requestBody);
    if (!postResult.has_value()) return { nullptr };
    const Json::Json& responseBody = postResult.value();

    auto file = std::make_shared<File>();
    *file = responseBody.get<File>();
    return file;
}

std::string Telebot::TelebotApi::DownloadFile(const File::Ptr& file, const std::string& toDirectory) const noexcept
{
    try
    {
        const auto httpContext = std::make_shared<HttpContext<EmptyBody, FileBody>>();
        httpContext->Request->version(HTTP_VERSION);
        httpContext->Request->method_string("GET");
        httpContext->Request->set(boost::beast::http::field::host, HOST);
        httpContext->Request->target("/file/bot" + _token + "/" + file->file_path);

        const std::filesystem::path path(file->file_path);
        std::string filePath = toDirectory + "/" + file->file_unique_id + path.extension().string();
        boost::beast::error_code ec;
        httpContext->Response->get().body().open(filePath.c_str(), boost::beast::file_mode::write, ec);

        HttpsClient::SendHttpsAsync(httpContext);
        return filePath;
    }
    catch (...)
    {
        return {};
    }
}

bool Telebot::TelebotApi::BanChatMember(std::int64_t chatId,
                                        std::int64_t userId,
                                        std::int32_t untilDate,
                                        bool revokeMessages)
{
    throw std::exception();
}

bool Telebot::TelebotApi::UnbanChatMember(std::int64_t chatId,
                                          std::int64_t userId,
                                          bool onlyIfBanned)
{
    throw std::exception();
}

bool Telebot::TelebotApi::RestrictChatMember(std::int64_t chatId,
                                             std::int64_t userId,
                                             const ChatPermissions::Ptr& permissions,
                                             std::int64_t untilDate,
                                             bool useIndependentChatPermissions)
{
    throw std::exception();
}

bool Telebot::TelebotApi::PromoteChatMember(std::int64_t chatId,
                                            std::int64_t userId,
                                            bool canChangeInfo,
                                            bool canPostMessages,
                                            bool canEditMessages,
                                            bool canDeleteMessages,
                                            bool canInviteUsers,
                                            bool canPinMessages,
                                            bool canPromoteMembers,
                                            bool isAnonymous,
                                            bool canManageChat,
                                            bool canManageVideoChats,
                                            bool canRestrictMembers,
                                            bool canManageTopics)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetChatAdministratorCustomTitle(std::int64_t chatId,
                                                          std::int64_t userId,
                                                          const std::string& customTitle)
{
    throw std::exception();
}

bool Telebot::TelebotApi::BanChatSenderChat(std::int64_t chatId,
                                            std::int64_t senderChatId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::UnbanChatSenderChat(std::int64_t chatId,
                                              std::int64_t senderChatId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetChatPermissions(std::int64_t chatId,
                                             const ChatPermissions::Ptr& permissions,
                                             bool useIndependentChatPermissions)
{
    throw std::exception();
}

std::string Telebot::TelebotApi::ExportChatInviteLink(std::int64_t chatId)
{
    throw std::exception();
}

Telebot::ChatInviteLink::Ptr Telebot::TelebotApi::CreateChatInviteLink(std::int64_t chatId,
                                                                       std::int32_t expireDate,
                                                                       std::int32_t memberLimit,
                                                                       const std::string& name,
                                                                       bool createsJoinRequest)
{
    throw std::exception();
}

Telebot::ChatInviteLink::Ptr Telebot::TelebotApi::EditChatInviteLink(std::int64_t chatId,
                                                                     const std::string& inviteLink,
                                                                     std::int32_t expireDate,
                                                                     std::int32_t memberLimit,
                                                                     const std::string& name,
                                                                     bool createsJoinRequest)
{
    throw std::exception();
}

Telebot::ChatInviteLink::Ptr Telebot::TelebotApi::RevokeChatInviteLink(std::int64_t chatId,
                                                                       const std::string& inviteLink)
{
    throw std::exception();
}

bool Telebot::TelebotApi::ApproveChatJoinRequest(std::int64_t chatId,
                                                 std::int64_t userId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::DeclineChatJoinRequest(std::int64_t chatId,
                                                 std::int64_t userId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetChatPhoto(std::int64_t chatId,
                                       const InputFile::Ptr& photo)
{
    throw std::exception();
}

bool Telebot::TelebotApi::DeleteChatPhoto(std::int64_t chatId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetChatTitle(std::int64_t chatId,
                                       const std::string& title)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetChatDescription(std::int64_t chatId,
                                             const std::string& description)
{
    throw std::exception();
}

bool Telebot::TelebotApi::PinChatMessage(std::int64_t chatId,
                                         std::int32_t messageId,
                                         bool disableNotification)
{
    throw std::exception();
}

bool Telebot::TelebotApi::UnpinChatMessage(std::int64_t chatId,
                                           std::int32_t messageId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::UnpinAllChatMessages(std::int64_t chatId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::LeaveChat(std::int64_t chatId)
{
    throw std::exception();
}

Telebot::Chat::Ptr Telebot::TelebotApi::GetChat(std::int64_t chatId)
{
    throw std::exception();
}

std::vector<Telebot::ChatMember::Ptr> Telebot::TelebotApi::GetChatAdministrators(std::int64_t chatId)
{
    throw std::exception();
}

std::int32_t Telebot::TelebotApi::GetChatMemberCount(std::int64_t chatId)
{
    throw std::exception();
}

Telebot::ChatMember::Ptr Telebot::TelebotApi::GetChatMember(std::int64_t chatId,
                                                            std::int64_t userId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetChatStickerSet(std::int64_t chatId,
                                            const std::string& stickerSetName)
{
    throw std::exception();
}

bool Telebot::TelebotApi::DeleteChatStickerSet(std::int64_t chatId)
{
    throw std::exception();
}

std::vector<Telebot::Sticker::Ptr> Telebot::TelebotApi::GetForumTopicIconStickers()
{
    throw std::exception();
}

Telebot::ForumTopic::Ptr Telebot::TelebotApi::CreateForumTopic(std::int64_t chatId,
                                                               const std::string& name,
                                                               std::int32_t iconColor,
                                                               const std::string& iconCustomEmojiId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::EditForumTopic(std::int64_t chatId,
                                         std::int32_t messageThreadId,
                                         const std::string& name,
                                         std::int8_t iconCustomEmojiId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::CloseForumTopic(std::int64_t chatId,
                                          std::int32_t messageThreadId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::ReopenForumTopic(std::int64_t chatId,
                                           std::int32_t messageThreadId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::DeleteForumTopic(std::int64_t chatId,
                                           std::int32_t messageThreadId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::UnpinAllForumTopicMessages(std::int64_t chatId,
                                                     std::int32_t messageThreadId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::EditGeneralForumTopic(std::int64_t chatId,
                                                const std::string& name)
{
    throw std::exception();
}

bool Telebot::TelebotApi::CloseGeneralForumTopic(std::int64_t chatId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::ReopenGeneralForumTopic(std::int64_t chatId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::HideGeneralForumTopic(std::int64_t chatId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::UnhideGeneralForumTopic(std::int64_t chatId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::AnswerCallbackQuery(const std::string& callbackQueryId,
                                              const std::string& text,
                                              bool showAlert,
                                              const std::string& url,
                                              std::int32_t cacheTime) const noexcept
{
    Json::Json requestBody;
    requestBody["callback_query_id"] = callbackQueryId;
    if (!text.empty()) requestBody["text"] = text;
    requestBody["show_alert"] = showAlert;

    const auto postResult = Post("answerCallbackQuery", requestBody);
    if (!postResult.has_value()) return false;
    const Json::Json& responseBody = postResult.value();

    return responseBody.get<bool>();
}

bool Telebot::TelebotApi::SetMyCommands(const std::vector<BotCommand::Ptr>& commands,
                                        const BotCommandScope::Ptr& scope,
                                        const std::string& languageCode) const noexcept
{
    Json::Json requestBody;
    requestBody["commands"] = commands;
    if (scope.get() != nullptr) requestBody["scope"] = scope;
    if (!languageCode.empty()) requestBody["language_code"] = languageCode;

    const auto postResult = Post("setMyCommands", requestBody);
    if (!postResult.has_value()) return false;
    const Json::Json& responseBody = postResult.value();

    return responseBody.get<bool>();
}

bool Telebot::TelebotApi::DeleteMyCommands(const BotCommandScope::Ptr& scope,
                                           const std::string& languageCode)
{
    throw std::exception();
}

std::vector<Telebot::BotCommand::Ptr> Telebot::TelebotApi::GetMyCommands(const BotCommandScope::Ptr& scope,
                                                                         const std::string& languageCode)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetMyDescription(const std::string& description, const std::string& languageCode)
{
    throw std::exception();
}

std::string Telebot::TelebotApi::GetMyDescription(const std::string& languageCode)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetMyShortDescription(const std::string& shortDescription,
                                                const std::string& languageCode)
{
    throw std::exception();
}

std::string Telebot::TelebotApi::GetMyShortDescription(const std::string& languageCode)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetChatMenuButton(std::int64_t chatId,
                                            const MenuButton::Ptr& menuButton)
{
    throw std::exception();
}

Telebot::MenuButton::Ptr Telebot::TelebotApi::GetChatMenuButton(std::int64_t chatId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetMyDefaultAdministratorRights(const ChatAdministratorRights::Ptr& rights,
                                                          bool forChannels)
{
    throw std::exception();
}

Telebot::ChatAdministratorRights::Ptr Telebot::TelebotApi::GetMyDefaultAdministratorRights(bool forChannels)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::EditMessageText(const std::string& text,
                                                           std::int64_t chatId,
                                                           std::int32_t messageId,
                                                           const std::string& inlineMessageId,
                                                           const std::string& parseMode,
                                                           bool disableWebPagePreview,
                                                           const GenericReply::Ptr& replyMarkup,
                                                           const std::vector<MessageEntity::Ptr>& entities) const noexcept
{
    Json::Json requestBody;
    requestBody["text"] = text;
    requestBody["chat_id"] = chatId;
    requestBody["message_id"] = messageId;
    requestBody["reply_markup"] = replyMarkup;

    const auto postResult = Post("editMessageText", requestBody);
    if (!postResult.has_value()) return { nullptr };
    const Json::Json& responseBody = postResult.value();

    auto message = std::make_shared<Message>();
    *message = responseBody.get<Message>();
    return message;
}

Telebot::Message::Ptr Telebot::TelebotApi::EditMessageCaption(std::int64_t chatId,
                                                              std::int32_t messageId,
                                                              const std::string& caption,
                                                              const std::string& inlineMessageId,
                                                              const GenericReply::Ptr& replyMarkup,
                                                              const std::string& parseMode,
                                                              const std::vector<MessageEntity::Ptr>& captionEntities)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::EditMessageMedia(const InputMedia::Ptr& media,
                                                            const std::int64_t chatId,
                                                            std::int32_t messageId,
                                                            const std::string& inlineMessageId,
                                                            const Telebot::GenericReply::Ptr& replyMarkup)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::EditMessageLiveLocation(float latitude,
                                                                   float longitude,
                                                                   const std::int64_t chatId,
                                                                   std::int32_t messageId,
                                                                   const std::string& inlineMessageId,
                                                                   const InlineKeyboardMarkup::Ptr& replyMarkup,
                                                                   float horizontalAccuracy,
                                                                   std::int32_t heading,
                                                                   std::int32_t proximityAlertRadius)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::StopMessageLiveLocation(const std::int64_t chatId,
                                                                   std::int32_t messageId,
                                                                   const std::string& inlineMessageId,
                                                                   const InlineKeyboardMarkup::Ptr& replyMarkup)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::EditMessageReplyMarkup(const std::int64_t chatId,
                                                                  std::int32_t messageId,
                                                                  const std::string& inlineMessageId,
                                                                  const GenericReply::Ptr& replyMarkup)
{
    throw std::exception();
}

Telebot::Poll::Ptr Telebot::TelebotApi::StopPoll(std::int64_t chatId,
                                                 std::int64_t messageId,
                                                 const InlineKeyboardMarkup::Ptr& replyMarkup)
{
    throw std::exception();
}

bool Telebot::TelebotApi::DeleteMessage(std::int64_t chatId,
                                        std::int32_t messageId)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendSticker(std::int64_t chatId,
                                                       const InputFile::Ptr& sticker,
                                                       std::int32_t replyToMessageId,
                                                       const GenericReply::Ptr& replyMarkup,
                                                       bool disableNotification,
                                                       bool allowSendingWithoutReply,
                                                       bool protectContent,
                                                       std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::StickerSet::Ptr Telebot::TelebotApi::GetStickerSet(const std::string& name)
{
    throw std::exception();
}

std::vector<Telebot::Sticker::Ptr> Telebot::TelebotApi::GetCustomEmojiStickers(const std::vector<std::string>& customEmojiIds)
{
    throw std::exception();
}

Telebot::File::Ptr Telebot::TelebotApi::UploadStickerFile(std::int64_t userId,
                                                          const InputFile::Ptr& pngSticker)
{
    throw std::exception();
}

bool Telebot::TelebotApi::CreateNewStickerSet(std::int64_t userId,
                                              const std::string& name,
                                              const std::string& title,
                                              const std::string& emojis,
                                              const MaskPosition::Ptr& maskPosition,
                                              const InputFile::Ptr& pngSticker,
                                              const InputFile::Ptr& tgsSticker,
                                              const InputFile::Ptr& webmSticker,
                                              const std::string& stickerType)
{
    throw std::exception();
}

bool Telebot::TelebotApi::AddStickerToSet(std::int64_t userId,
                                          const std::string& name,
                                          const std::string& emojis,
                                          const MaskPosition::Ptr& maskPosition,
                                          const InputFile::Ptr& pngSticker,
                                          const InputFile::Ptr& tgsSticker,
                                          const InputFile::Ptr& webmSticker)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetStickerPositionInSet(const std::string& sticker,
                                                  std::int32_t position)
{
    throw std::exception();
}

bool Telebot::TelebotApi::DeleteStickerFromSet(const std::string& sticker)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetStickerEmojiList(const std::string& sticker,
                                              const std::vector<std::string>& emojiList)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetStickerKeywords(const std::string& sticker,
                                             const std::vector<std::string>& keywords)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetStickerMaskPosition(const std::string& sticker,
                                                 const MaskPosition::Ptr& maskPosition)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetStickerTitle(const std::string& name,
                                          const std::string& title)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetStickerSetThumbnail(const std::string& name,
                                                 std::int64_t userId,
                                                 const InputFile::Ptr& thumb)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetCustomEmojiStickerSetThumbnail(const std::string& name,
                                                            const std::string& customEmojiId)
{
    throw std::exception();
}

bool Telebot::TelebotApi::DeleteStickerSet(const std::string& name)
{
    throw std::exception();
}

bool Telebot::TelebotApi::AnswerInlineQuery(const std::string& inlineQueryId,
                                            const std::vector<InlineQueryResult::Ptr>& results,
                                            std::int32_t cacheTime,
                                            bool isPersonal,
                                            const std::string& nextOffset,
                                            const std::string& switchPmText,
                                            const std::string& switchPmParameter)
{
    throw std::exception();
}

Telebot::SentWebAppMessage::Ptr Telebot::TelebotApi::AnswerWebAppQuery(const std::string& webAppQueryId,
                                                                       const InlineQueryResult::Ptr& result)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendInvoice(std::int64_t chatId,
                                                       const std::string& title,
                                                       const std::string& description,
                                                       const std::string& payload,
                                                       const std::string& providerToken,
                                                       const std::string& currency,
                                                       const std::vector<LabeledPrice::Ptr>& prices,
                                                       const std::string& providerData,
                                                       const std::string& photoUrl,
                                                       std::int32_t photoSize,
                                                       std::int32_t photoWidth,
                                                       std::int32_t photoHeight,
                                                       bool needName,
                                                       bool needPhoneNumber,
                                                       bool needEmail,
                                                       bool needShippingAddress,
                                                       bool sendPhoneNumberToProvider,
                                                       bool sendEmailToProvider,
                                                       bool isFlexible,
                                                       std::int32_t replyToMessageId,
                                                       const GenericReply::Ptr& replyMarkup,
                                                       bool disableNotification,
                                                       bool allowSendingWithoutReply,
                                                       std::int32_t maxTipAmount,
                                                       const std::vector<std::int32_t>& suggestedTipAmounts,
                                                       const std::string& startParameter,
                                                       bool protectContent,
                                                       std::int32_t messageThreadId)
{
    throw std::exception();
}

std::string Telebot::TelebotApi::CreateInvoiceLink(const std::string& title,
                                                   const std::string& description,
                                                   const std::string& payload,
                                                   const std::string& providerToken,
                                                   const std::string& currency,
                                                   const std::vector<LabeledPrice::Ptr>& prices,
                                                   std::int32_t maxTipAmount,
                                                   const std::vector<std::int32_t>& suggestedTipAmounts,
                                                   const std::string& providerData,
                                                   const std::string& photoUrl,
                                                   std::int32_t photoSize,
                                                   std::int32_t photoWidth,
                                                   std::int32_t photoHeight,
                                                   bool needName,
                                                   bool needPhoneNumber,
                                                   bool needEmail,
                                                   bool needShippingAddress,
                                                   bool sendPhoneNumberToProvider,
                                                   bool sendEmailToProvider,
                                                   bool isFlexible)
{
    throw std::exception();
}

bool Telebot::TelebotApi::AnswerShippingQuery(const std::string& shippingQueryId,
                                              bool ok,
                                              const std::vector<ShippingOption::Ptr>& shippingOptions,
                                              const std::string& errorMessage)
{
    throw std::exception();
}

bool Telebot::TelebotApi::AnswerPreCheckoutQuery(const std::string& preCheckoutQueryId,
                                                 bool ok,
                                                 const std::string& errorMessage)
{
    throw std::exception();
}

bool Telebot::TelebotApi::SetPassportDataErrors(std::int64_t userId,
                                                const std::vector<PassportElementError::Ptr>& errors)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SendGame(std::int64_t chatId,
                                                    const std::string& gameShortName,
                                                    std::int32_t replyToMessageId,
                                                    const InlineKeyboardMarkup::Ptr& replyMarkup,
                                                    bool disableNotification,
                                                    bool allowSendingWithoutReply,
                                                    bool protectContent,
                                                    std::int32_t messageThreadId)
{
    throw std::exception();
}

Telebot::Message::Ptr Telebot::TelebotApi::SetGameScore(std::int64_t userId,
                                                        std::int32_t score,
                                                        bool force,
                                                        bool disableEditMessage,
                                                        std::int64_t chatId,
                                                        std::int32_t messageId,
                                                        const std::string& inlineMessageId)
{
    throw std::exception();
}

std::vector<Telebot::GameHighScore::Ptr> Telebot::TelebotApi::GetGameHighScores(std::int64_t userId,
                                                                                std::int64_t chatId,
                                                                                std::int32_t messageId,
                                                                                const std::string& inlineMessageId)
{
    throw std::exception();
}