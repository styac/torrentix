/*
* Copyright (c) 2021-2022, The PurpleI2P Project
*
* This file is part of Purple i2pd project and licensed under BSD3
*
* See full license text in LICENSE file at top of project tree
*/

#ifndef __I18N_H__
#define __I18N_H__

#include <string>
#include <map>
#include <utility>
#include <functional>

namespace i2p
{
namespace i18n
{
	class Locale
	{
		public:
			Locale (
				const std::string& language,
				const std::map<std::string, std::string>& strings,
				const std::map<std::string, std::vector<std::string>>& plurals,
				std::function<int(int)> formula
			): m_Language (language), m_Strings (strings), m_Plurals (plurals), m_Formula (formula) { };

			// Get activated language name for webconsole
			std::string GetLanguage() const
			{
				return m_Language;
			}

			std::string GetString (const std::string& arg) const
			{
				const auto it = m_Strings.find(arg);
				if (it == m_Strings.end())
				{
					return arg;
				}
				else
				{
					return it->second;
				}
			}

			std::string GetPlural (const std::string& arg, const std::string& arg2, const int& n) const
			{
				const auto it = m_Plurals.find(arg2);
				if (it == m_Plurals.end()) // not found, fallback to english
				{
					return n == 1 ? arg : arg2;
				}
				else
				{
					int form = m_Formula(n);
					return it->second[form];
				}
			}

		private:
			const std::string m_Language;
			const std::map<std::string, std::string> m_Strings;
			const std::map<std::string, std::vector<std::string>> m_Plurals;
			std::function<int(int)> m_Formula;
	};
	
	void SetLanguage(const std::string &lang);
	std::string translate (const std::string& arg);
	std::string translate (const std::string& arg, const std::string& arg2, const int& n);
} // i18n
} // i2p

template<typename... TArgs>
std::string tr (TArgs&&... args)
{
	return i2p::i18n::translate(std::forward<TArgs>(args)...);
}

#endif // __I18N_H__
