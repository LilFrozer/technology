#ifndef BOT_H
#define BOT_H

#include <iostream>
#include <memory.h>
#include <string>
#include "json.hpp"
#include <cstdint>
using nlohmann::json;

namespace TG
{
const std::string TELEGRAM_API = "api.telegram.org";
const std::string TELEGRAM_PORT = "443";
/**
 *  Интерфейс для взаимодействия с
 *  тг-ботом
 */
class TgApi
{
protected:
    virtual json SendRequest(const std::string &method, const json &payload = json::object()) = 0;
    virtual void SendMessage(int64_t chat_id, const std::string &text) = 0;
    virtual void ProcessUpdate(const json &updates) = 0;
public:
    virtual void run() = 0;
};

/**
 *  Класс для работы с тг-ботом
 */
class MovieBot : public TgApi
{
private:
    std::string m_token = "";
    int64_t m_last_update_id = 0;
protected:
    json SendRequest(const std::string &method, const json &payload = json::object()) override final;
    void SendMessage(int64_t chat_id, const std::string &text) override final;
    void ProcessUpdate(const json &updates) override final;
public:
    MovieBot(const char *t);
    ~MovieBot() = default;
    void run() override final;
};
}

#endif
