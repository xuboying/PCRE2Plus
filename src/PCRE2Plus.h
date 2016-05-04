﻿/*
Copyright (c) 2016, Boying Xu All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list
of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this 
list of conditions and the following disclaimer in the documentation and/or 
other materials provided with the distribution.

Neither the name of the copyright holder nor the names of its contributors may 
be used to endorse or promote products derived from this software without 
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUB STITUTE GOODS OR 
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
#define MARKUP_SIZEOFWCHAR 4
#else
#define MARKUP_SIZEOFWCHAR 2
#endif
#endif

#if MARKUP_SIZEOFWCHAR == 4
#define PCRE2_CODE_UNIT_WIDTH 32
#else
#define PCRE2_CODE_UNIT_WIDTH 16
#endif

#if defined(_MSC_VER)
#if defined (_DEBUG)
#pragma comment(lib, "libpcre2-8d")
#if MARKUP_SIZEOFWCHAR == 4
#pragma comment(lib, "libpcre2-32d")
#else
#pragma comment(lib, "libpcre2-16d")
#endif
#else
#pragma comment(lib, "libpcre2-8")
#if MARKUP_SIZEOFWCHAR == 4
#define PCRE2_CODE_UNIT_WIDTH 32
#pragma comment(lib, "libpcre2-32")
#else
#pragma comment(lib, "libpcre2-16")
#endif
#endif
#endif





#define PCRE2_STATIC 1
#include <pcre2.h>
#include <string>
#include <vector>
#include <memory>
#include <tuple>


namespace PCRE2Plus{
    //==========================================================================
    class re{
    protected:
        static int lasterror;
        static size_t erroroffset;
    public:
        class RegexObject;
        class MatchObject;
        class iter;
        class RegexObjectW;
        class MatchObjectW;
        class iterW;
        static std::shared_ptr<re::RegexObject> compile(const std::string & pattern, int flags = 0);
        static std::shared_ptr<re::RegexObjectW> compile(const std::wstring & pattern, int flags = 0);
        static std::unique_ptr<re::MatchObject> search(const std::string & pattern, const std::string & Str, int flags = 0);
        static std::unique_ptr<re::MatchObject> search(const std::string & pattern, const std::string && Str, int flags = 0) = delete;
        static std::unique_ptr<re::MatchObjectW> search(const std::wstring & pattern, const std::wstring & Str, int flags = 0);
        static std::unique_ptr<re::MatchObjectW> search(const std::wstring & pattern, const std::wstring && Str, int flags = 0) = delete;
        static std::vector<std::string> split(const std::string & pattern, const std::string & Str, size_t maxsplit = 0, int flags = 0);
        static std::vector<std::string> split(const std::string & pattern, const std::string && Str, size_t maxsplit = 0, int flags = 0) = delete;
        static std::vector<std::wstring> split(const std::wstring & pattern, const std::wstring & Str, size_t maxsplit = 0, int flags = 0);
        static std::vector<std::wstring> split(const std::wstring & pattern, const std::wstring && Str, size_t maxsplit = 0, int flags = 0) = delete;
        static std::vector<std::string> findall(const std::string & pattern, const std::string & Str, int flags = 0);
        static std::vector<std::string> findall(const std::string & pattern, const std::string && Str, int flags = 0) = delete;
        static std::vector<std::wstring> findall(const std::wstring & pattern, const std::wstring & Str, int flags = 0);
        static std::vector<std::wstring> findall(const std::wstring & pattern, const std::wstring && Str, int flags = 0) = delete;
        static std::unique_ptr<re::iter> finditer(const std::string & pattern, const std::string & Str, int flags = 0);
        static std::unique_ptr<re::iter> finditer(const std::string & pattern, const std::string && Str, int flags = 0) = delete;
        static std::unique_ptr<re::iterW> finditer(const std::wstring & pattern, const std::wstring & Str, int flags = 0);
        static std::unique_ptr<re::iterW> finditer(const std::wstring & pattern, const std::wstring && Str, int flags = 0) = delete;
        static std::string sub(const std::string & pattern, const std::string & repl, const std::string & Str, size_t count = 0, int flags = 0);
        static std::string sub(const std::string & pattern, const std::string & repl, const std::string && Str, size_t count = 0, int flags = 0) = delete;
        static std::wstring sub(const std::wstring & pattern, const std::wstring & repl, const std::wstring & Str, size_t count = 0, int flags = 0);
        static std::wstring sub(const std::wstring & pattern, const std::wstring & repl, const std::wstring && Str, size_t count = 0, int flags = 0) = delete;
        static std::tuple<std::string, size_t> subn(const std::string & pattern, const std::string & repl, const std::string & Str, size_t count = 0, int flags = 0);
        static std::tuple<std::string, size_t> subn(const std::string & pattern, const std::string & repl, const std::string && Str, size_t count = 0, int flags = 0) = delete;
        static std::tuple<std::wstring, size_t> subn(const std::wstring & pattern, const std::wstring & repl, const std::wstring & Str, size_t count = 0, int flags = 0);
        static std::tuple<std::wstring, size_t> subn(const std::wstring & pattern, const std::wstring & repl, const std::wstring && Str, size_t count = 0, int flags = 0) = delete;
        static std::string escape(const std::string & unquoted);
        static std::wstring escape(const std::wstring & unquoted);
        static int getlasterror();
        static int geterroroffset();
        static std::string getlasterrorstr();
    public:
        static const size_t DOTALL = PCRE2_DOTALL;
/*
Newline conventions

PCRE2 supports five different conventions for indicating line breaks in strings: a single CR (carriage return) character, a single LF (linefeed) character, the two-character sequence CRLF, any of the three preceding, or any Unicode newline sequence. The pcre2api page has further discussion about newlines, and shows how to set the newline convention when calling pcre2_compile().

It is also possible to specify a newline convention by starting a pattern string with one of the following five sequences:

  (*CR)        carriage return
  (*LF)        linefeed
  (*CRLF)      carriage return, followed by linefeed
  (*ANYCRLF)   any of the three above
  (*ANY)       all Unicode newline sequences

These override the default and the options given to the compiling function. For example, on a Unix system where LF is the default newline sequence, the pattern

  (*CR)a.b

changes the convention to CR. That pattern matches "a\nb" because LF is no longer a newline. If more than one of these settings is present, the last one is used.

The newline convention affects where the circumflex and dollar assertions are true. It also affects the interpretation of the dot metacharacter when PCRE2_DOTALL is not set, and the behaviour of \N. However, it does not affect what the \R escape sequence matches. By default, this is any Unicode newline sequence, for Perl compatibility. However, this can be changed; see the description of \R in the section entitled "Newline sequences" below. A change of \R setting can be combined with a change of newline convention. 
*/
        static const size_t S = DOTALL;
        static const size_t MULTLINE = PCRE2_MULTILINE;
        static const size_t M = MULTLINE;
        static const size_t IGNORECASE = PCRE2_CASELESS;
        static const size_t I = IGNORECASE;
        static const size_t VERBOSE = PCRE2_EXTENDED;
        static const size_t X = VERBOSE;
        static const size_t U = PCRE2_UCP | PCRE2_UTF;

        static const size_t LOCALE = 0x10000000u;  /* Not yet used by pcre2 */
        static const size_t L = LOCALE;


        //======================================================================
        class MatchObject{
        public:
            MatchObject(std::shared_ptr<RegexObject> re, const std::string & Str, PCRE2_SIZE * ovector, size_t lastindex, size_t pos, size_t endpos);
            std::string group(size_t i);
            std::string group();
            std::string group(std::string name);
            size_t pos();
            size_t endpos();
            size_t start(size_t i);
            size_t end(size_t i);
            std::vector<std::string> groups();
            std::string string();
            size_t lastindex();
            std::vector<int> span(size_t i);
            std::shared_ptr<RegexObject> re();
            friend class RegexObject;
        protected:
            std::shared_ptr<RegexObject> m_re;
            const std::string & m_str;
            size_t m_pos;
            size_t m_endpos;
            std::vector<size_t> m_groups;
            size_t m_lastindex;
        };
        //======================================================================
        class RegexObject : public std::enable_shared_from_this<RegexObject>{
        protected:
            size_t m_flags;
            std::string m_pattern;
            pcre2_code_8 * m_re;
            pcre2_match_data_8 * m_match_data;
            friend class re::MatchObject;
            friend class re::iter;
            void search(std::unique_ptr<re::MatchObject> & M, const std::string & Str, size_t pos, int endpos);
        public:
            RegexObject(pcre2_code_8 * re, size_t flags, std::string pattern);
            ~RegexObject();
            size_t flags();
            std::string pattern();
            std::unique_ptr<re::MatchObject> search(const std::string & Str, size_t pos = 0, int endpos = -1);
            std::unique_ptr<re::MatchObject> search(const std::string && Str, size_t pos = 0, int endpos = -1) = delete;
            std::vector<std::string> split(const std::string & Str, size_t maxsplit = 0);
            std::vector<std::string> split(const std::string && Str, size_t maxsplit = 0) = delete;
            std::vector<std::string> findall(const std::string & Str, size_t pos = 0, int endpos = -1);
            std::vector<std::string> findall(const std::string && Str, size_t pos = 0, int endpos = -1) = delete;
            std::unique_ptr<re::iter> finditer(const std::string & Str, size_t pos = 0, int endpos = -1);
            std::unique_ptr<re::iter> finditer(const std::string && Str, size_t pos = 0, int endpos = -1) = delete;
            std::string sub(const std::string & repl, const std::string & Str, size_t count = 0);
            std::string sub(const std::string & repl, const std::string && Str, size_t count = 0) = delete;
            std::tuple<std::string, size_t> subn(const std::string & repl, const std::string & Str, size_t count = 0);
            std::tuple<std::string, size_t> subn(const std::string & repl, const std::string && Str, size_t count = 0) = delete;

        };
        //======================================================================
        class iter{
        protected:
            std::shared_ptr<RegexObject> m_regexobj;
            int m_pos;
            int m_endpos;
            const std::string & m_str;
            std::unique_ptr<MatchObject> m_matchobj;
        public:
            iter(std::shared_ptr<RegexObject> regexobj, const std::string & Str, int endpos = -1);
            std::unique_ptr<MatchObject> Get();
            bool AtEnd();
            void next();
            iter & operator ++();
            iter & operator ++(int);
        };

        //======================================================================

        class MatchObjectW {
        public:
            MatchObjectW(std::shared_ptr<RegexObjectW> re, const std::wstring & Str, PCRE2_SIZE * ovector, size_t lastindex, size_t pos, size_t endpos);
            std::wstring group(size_t i);
            std::wstring group();
            std::wstring group(std::wstring name);
            size_t pos();
            size_t endpos();
            size_t start(size_t i);
            size_t end(size_t i);
            std::vector<std::wstring> groups();
            std::wstring string();
            size_t lastindex();
            std::vector<int> span(size_t i);
            std::shared_ptr<RegexObjectW> re();
            friend class RegexObjectW;
        protected:
            std::shared_ptr<RegexObjectW> m_re;
            const std::wstring & m_str;
            size_t m_pos;
            size_t m_endpos;
            std::vector<size_t> m_groups;
            size_t m_lastindex;
        };
        //======================================================================
        class RegexObjectW : public std::enable_shared_from_this< RegexObjectW >{
        protected:
            size_t m_flags;
            std::wstring m_pattern;
            pcre2_code * m_re;
            pcre2_match_data * m_match_data;
            friend class re::MatchObjectW;
            friend class re::iterW;
            void search(std::unique_ptr<re::MatchObjectW> & M, const std::wstring & Str, size_t pos, int endpos);
        public:
            RegexObjectW(pcre2_code * re, size_t flags, std::wstring pattern);
            ~RegexObjectW();
            size_t flags();
            std::wstring pattern();
            std::unique_ptr<re::MatchObjectW> search(const  std::wstring & Str, size_t pos = 0, int endpos = -1);
            std::unique_ptr<re::MatchObjectW> search(const  std::wstring && Str, size_t pos = 0, int endpos = -1) = delete;
            std::vector<std::wstring> split(const std::wstring & Str, size_t maxsplit = 0);
            std::vector<std::wstring> split(const std::wstring && Str, size_t maxsplit = 0) = delete;
            std::vector< std::wstring> findall(const  std::wstring & Str, size_t pos = 0, int endpos = -1);
            std::vector< std::wstring> findall(const  std::wstring && Str, size_t pos = 0, int endpos = -1) = delete;
            std::unique_ptr<re::iterW> finditer(const  std::wstring & Str, size_t pos = 0, int endpos = -1);
            std::unique_ptr<re::iterW> finditer(const  std::wstring && Str, size_t pos = 0, int endpos = -1) = delete;
            std::wstring sub(const  std::wstring & repl, const  std::wstring & Str, size_t count = 0);
            std::wstring sub(const  std::wstring & repl, const  std::wstring && Str, size_t count = 0) = delete;
            std::tuple<std::wstring, size_t> subn(const std::wstring & repl, const std::wstring & Str, size_t count = 0);
            std::tuple<std::wstring, size_t> subn(const std::wstring & repl, const std::wstring && Str, size_t count = 0) = delete;
        };
        //======================================================================
        class iterW{
        protected:
            std::shared_ptr<RegexObjectW> m_regexobj;
            int m_pos;
            std::wstring m_str;
            std::unique_ptr<MatchObjectW> m_matchobj;
            int m_endpos;
        public:
            iterW(std::shared_ptr<RegexObjectW> regexobj, const std::wstring & Str, int endpos = -1);
            std::unique_ptr<MatchObjectW> Get();
            bool AtEnd();
            void next();
            iterW & operator ++();
            iterW & operator ++(int);
        };
    };
};