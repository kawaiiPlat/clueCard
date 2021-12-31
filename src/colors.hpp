//ANSI color codes from https://www.delftstack.com/howto/cpp/how-to-colorize-output-in-console-cpp/
//reference: https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
#ifndef COLORS_H
#define COLORS_H

// reset color
#define COLOR_NC                "\e[0m"

// Foreground colors
#define COLOR_BLACK             "\e[0;30m"
#define COLOR_RED               "\e[0;31m"
#define COLOR_GREEN             "\e[0;32m"
#define COLOR_YELLOW            "\e[0;33m"
#define COLOR_BLUE              "\e[0;34m"
#define COLOR_MAGENTA           "\e[0;35m"
#define COLOR_CYN               "\e[0;36m"
#define COLOR_WHITE             "\e[0;37m"

#define COLOR_BRIGHT_BLACK      "\e[0;90m"
#define COLOR_BRIGHT_RED        "\e[0;91m"
#define COLOR_BRIGHT_GREEN      "\e[0;92m"
#define COLOR_BRIGHT_YELLOW     "\e[0;93m"
#define COLOR_BRIGHT_BLUE       "\e[0;94m"
#define COLOR_BRIGHT_MAGENTA    "\e[0;95m"
#define COLOR_BRIGHT_CYAN       "\e[0;96m"
#define COLOR_BRIGHT_WHITE      "\e[0;97m"

// Background Colors
#define COLOR_BLACKB             "\e[40m"
#define COLOR_REDB               "\e[41m"
#define COLOR_GREENB             "\e[42m"
#define COLOR_YELLOWB            "\e[43m"
#define COLOR_BLUEB              "\e[44m"
#define COLOR_MAGENTAB           "\e[45m"
#define COLOR_CYANB              "\e[46m"
#define COLOR_WHITEB             "\e[47m"

#define COLOR_BRIGHT_BLACKB      "\e[100m"
#define COLOR_BRIGHT_REDB        "\e[101m"
#define COLOR_BRIGHT_GREENB      "\e[102m"
#define COLOR_BRIGHT_YELLOWB     "\e[103m"
#define COLOR_BRIGHT_BLUEB       "\e[104m"
#define COLOR_BRIGHT_MAGENTAB    "\e[105m"
#define COLOR_BRIGHT_CYANB       "\e[106m"
#define COLOR_BRIGHT_WHITEB      "\e[107m"

#endif