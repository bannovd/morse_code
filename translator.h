#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QMap>

class Translator : public QObject
{
    Q_OBJECT
public:
    explicit Translator(QObject *parent = nullptr);
    QString fromMorseToEn(const QString & str);
    QString fromEnToMorse(const QString & str);

private:
    QMap<QString, QString> morseToEnMap;
    QMap<QString, QString> enToMorseMap;

signals:

};

#endif // TRANSLATOR_H
