#pragma once
#include "../../SDK/SDK.h"
#include <functional>

using CommandCallback = std::function<void(std::deque<std::string>)>;

class CCommands
{
private:
    std::unordered_map<uint32_t, CommandCallback> CommandMap;
	std::unordered_map<uint32_t, uint32_t> Aliases;

public:
    void Initialize();
    bool Run(const std::string& cmd, std::deque<std::string>& args);
    void Register(const std::string& name, CommandCallback callback);
	void RegisterAlias(const std::string& alias, const std::string& commandName);
};

ADD_FEATURE(CCommands, Commands)