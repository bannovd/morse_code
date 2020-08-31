#include "translator.h"

Translator::Translator(QObject *parent) : QObject(parent)
{
    enToMorseMap["a"] = ".-";
    enToMorseMap["b"] = "-...";
    enToMorseMap["c"] = "-.-.";
    enToMorseMap["d"] = "-..";
    enToMorseMap["e"] = ".";
    enToMorseMap["f"] = "..-.";
    enToMorseMap["g"] = "--.";
    enToMorseMap["h"] = "....";
    enToMorseMap["i"] = "..";
    enToMorseMap["j"] = ".---";
    enToMorseMap["k"] = "-.-";
    enToMorseMap["l"] = ".-..";
    enToMorseMap["m"] = "--";
    enToMorseMap["n"] = "-.";
    enToMorseMap["o"] = "---";
    enToMorseMap["p"] = ".--.";
    enToMorseMap["q"] = "--.-";
    enToMorseMap["r"] = ".-.";
    enToMorseMap["s"] = "...";
    enToMorseMap["t"] = "-";
    enToMorseMap["u"] = "..-";
    enToMorseMap["v"] = "...-";
    enToMorseMap["w"] = ".--";
    enToMorseMap["x"] = "-..-";
    enToMorseMap["y"] = "-.--";
    enToMorseMap["z"] = "--..";
    enToMorseMap["."] = ".-.-.-";
    enToMorseMap[","] = "--..--";
    enToMorseMap["?"] = "..--..";
    enToMorseMap["!"] = "-.-.--";
    enToMorseMap["-"] = "-....-";

    morseToEnMap[".-"] = "a";
    morseToEnMap["-..."] = "b";
    morseToEnMap["-.-."] = "c";
    morseToEnMap["-.."] = "d";
    morseToEnMap["."] = "e";
    morseToEnMap["..-."] = "f";
    morseToEnMap["--."] = "g";
    morseToEnMap["...."] = "h";
    morseToEnMap[".."] = "i";
    morseToEnMap[".---"] = "j";
    morseToEnMap["-.-"] = "k";
    morseToEnMap[".-.."] = "l";
    morseToEnMap["--"] = "m";
    morseToEnMap["-."] = "n";
    morseToEnMap["---"] = "o";
    morseToEnMap[".--."] = "p";
    morseToEnMap["--.-"] = "q";
    morseToEnMap[".-."] = "r";
    morseToEnMap["..."] = "s";
    morseToEnMap["-"] = "t";
    morseToEnMap["..-"] = "u";
    morseToEnMap["...-"] = "v";
    morseToEnMap[".--"] = "w";
    morseToEnMap["-..-"] = "x";
    morseToEnMap["-.--"] = "y";
    morseToEnMap["--.."] = "z";
    morseToEnMap[".-.-.-"] = ".";
    morseToEnMap["--..--"] = ",";
    morseToEnMap["..--.."] = "?";
    morseToEnMap["-.-.--"] = "!";
    morseToEnMap["-....-"] = "-";
}

QString Translator::fromMorseToEn(const QString & str)
{
    QString res;
    QStringList words = str.split("  ", Qt::SkipEmptyParts);
    for (int i = 0; i < words.size(); ++i)
    {
        QStringList letters = words[i].split(" ", Qt::SkipEmptyParts);
        for (int j = 0; j < letters.size(); ++j)
        {
            res += morseToEnMap[letters[j]];
        }

        res += " ";
    }
    return res;
}

QString Translator::fromEnToMorse(const QString & str)
{
    QString res;
    QStringList words = str.split(" ", Qt::SkipEmptyParts);
    for (int i = 0; i < words.size(); ++i)
    {
        for (int j = 0; j < words[i].length(); ++j)
        {
            res += enToMorseMap[words[i][j].toLower()] + " ";
        }

        res += "  ";
    }
    return res;
}
