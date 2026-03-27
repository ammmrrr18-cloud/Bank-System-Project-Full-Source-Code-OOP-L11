#pragma once

class clsColors {
public:
    static const char* Red() { return "\033[1;31m"; }
    static const char* Green() { return "\033[1;32m"; }
    static const char* Yellow() { return "\033[1;33m"; }
    static const char* Blue() { return "\033[1;34m"; }
    static const char* Magenta() { return "\033[1;35m"; }
    static const char* Cyan() { return "\033[1;36m"; }
    static const char* Grey() { return "\033[0;37m"; }

    static const char* RedBackground() { return "\033[41m"; }
    static const char* GreenBackground() { return "\033[42m"; }
    static const char* YellowBackground() { return "\033[43m"; }
    static const char* BlueBackground() { return "\033[44m"; }

    static const char* BrightCyan() { return "\033[1;96m"; }
    static const char* BrightYellow() { return "\033[1;93m"; }
    static const char* BrightGreen() { return "\033[1;92m"; }
    static const char* BrightBlue() { return "\033[1;94m"; }
    static const char* BrightMagenta() { return "\033[1;95m"; }

    static const char* Underline() { return "\033[4m"; }
    static const char* Reset() { return "\033[0m"; }
};